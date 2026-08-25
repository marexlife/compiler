#ifndef MAREX_PARSE_NODE_H
#define MAREX_PARSE_NODE_H
#include "ParserPack.h"
#include "Token.h"
#include "TokenKind.h"
#include <concepts>
#include <cstdint>
#include <string_view>

namespace marex::parse {
class AstNode {
public:
    explicit AstNode(lex::Token&& token);

    AstNode(AstNode&&) = default;
    AstNode& operator=(AstNode&&) = default;
    AstNode(const AstNode&) = delete;
    AstNode& operator=(const AstNode&) = delete;
    virtual ~AstNode() = default;

    template <typename T>
        requires std::derived_from<T, AstNode>
    [[nodiscard]] T& cast()
    {
        return static_cast<T&>(*this);
    }

    [[nodiscard]] virtual std::string as_string() = 0;

    [[nodiscard]] const lex::Token& get_token() const
    {
        return token;
    }

    [[nodiscard]] std::uint8_t
    get_binding_power() const
    {
        return token.get_binding_power();
    }

    [[nodiscard]] lex::TokenKind get_kind() const
    {
        return token.get_kind();
    }

    [[nodiscard]] std::string_view get_lexeme() const
    {
        return token.get_lexeme();
    }

    virtual void parse(ParserPack& pack) = 0;

private:
    lex::Token token;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODE_H