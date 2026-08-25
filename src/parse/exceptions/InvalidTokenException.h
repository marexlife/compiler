#ifndef MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H
#define MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H
#include <exception>
#include <string>

#include "SourcePos.h"
#include "TokenKind.h"

namespace marex::parse::exceptions {
class InvalidTokenException final
    : public std::exception {
public:
    explicit InvalidTokenException(
        lex::SourcePos source_pos,
        lex::TokenKind& expected_token_kind);

    const char* what() const noexcept override;

private:
    std::string full_message;
};
} // namespace marex::parse::exceptions
#endif // MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H