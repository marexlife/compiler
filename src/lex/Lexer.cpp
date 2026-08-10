#include "Lexer.h"

#include <absl/base/attributes.h>

#include <optional>
#include <string>

#include "Defer.h"
#include "LastCharKind.h"
#include "Statement.h"
#include "Token.h"
#include "TokenStream.h"
#include "absl/status/status.h"

namespace compiler::lex {
absl::StatusOr<TokenStream> Lexer::run(std::string&& sourceText)
{
    TokenStream result;

    core::Defer deferReset { [&]() { reset(); } };

    result.reserve(vectorDefaultSize);

    std::optional<char> lastCharOptional = std::nullopt;
    LastCharKind lastCharKind = LastCharKind::None;

    for (const auto sourceTextChar : sourceText) {
        LastCharKind thisCharKind = LastCharKind::WasNotDefault;

        core::Defer defeIterEnd { [&]() {
            lastCharOptional = sourceTextChar;
            lastCharKind = thisCharKind;
        } };

        switch (sourceTextChar) {
        case '\n':
            [[fallthrough]];
        case '\0':
            // ignore
            break;
        case ' ':
            if (lastCharKind == LastCharKind::WasDefault) {
                pushToken();
            }
            break;
        case ';':
            pushStatement(result);
            break;
        default:
            thisCharKind = LastCharKind::WasDefault;
            lastWord.push_back(sourceTextChar);
            break;
        }
    }

    if (!lastCharOptional.has_value()) [[unlikely]] {
        return absl::AbortedError("Source code is empty.");
    }

    if (*lastCharOptional != ';') [[unlikely]] {
        return absl::AbortedError("The last has to be a ';'.");
    }

    return result;
}

void Lexer::reset()
{
    lastStatement.clear();
    lastWord.clear();
}

void Lexer::pushToken()
{
    lastStatement.emplace_back(
        tokenFactory.createToken(std::string { lastWord }));

    lastWord.clear();
}

void Lexer::pushStatement(TokenStream& result)
{
    pushToken();

    result.push_back(Statement { lastStatement });

    lastStatement.clear();
}
} // namespace compiler::lex
