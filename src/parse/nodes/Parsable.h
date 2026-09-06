#ifndef MAREX_PARSE_ASTNODE_H
#define MAREX_PARSE_ASTNODE_H
#include <cstdint>
#include <string_view>

#include "ParserPack.h"
#include "Token.h"
#include "TokenKind.h"

namespace marex::parse {
class Parsable {
   public:
    explicit Parsable(lex::Token&& token);

    Parsable(Parsable&&) = default;
    Parsable& operator=(Parsable&&) = default;
    Parsable(const Parsable&) = delete;
    Parsable& operator=(const Parsable&) = delete;
    virtual ~Parsable() = default;

    [[nodiscard]] virtual std::string as_c() = 0;

    [[nodiscard]] const lex::Token& get_token() const {
        return token;
    }

    [[nodiscard]] std::uint8_t get_binding_power()
        const {
        return token.get_binding_power();
    }

    [[nodiscard]] lex::TokenKind get_kind() const {
        return token.get_kind();
    }

    [[nodiscard]] std::string_view get_lexeme() const {
        return token.get_lexeme();
    }

    virtual void parse(ParserPack& pack) = 0;

   private:
    lex::Token token;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_ASTNODE_H