#ifndef MAREX_PARSE_NODE_H
#define MAREX_PARSE_NODE_H
#include "JumpCont.h"
#include "Token.h"
#include "TokenKind.h"
#include <concepts>
#include <cstdint>
#include <string_view>

namespace marex::parse {
class Node {
  public:
    explicit Node(lex::Token &&token);

    Node(Node &&) = default;
    Node &operator=(Node &&) = default;
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;
    virtual ~Node() = default;

    template <typename T>
        requires std::derived_from<T, Node>
    [[nodiscard]] T &cast() {
        return static_cast<T &>(*this);
    }

    [[nodiscard]] virtual std::string as_string() = 0;

    [[nodiscard]] const lex::Token &get_token() const {
        return token;
    }

    [[nodiscard]] std::uint8_t get_binding_power() const {
        return token.get_binding_power();
    }

    [[nodiscard]] lex::TokenKind get_kind() const {
        return token.get_kind();
    }

    [[nodiscard]] std::string_view get_lexeme() const {
        return token.get_lexeme();
    }

    [[nodiscard]] virtual JumpCount set(Node &next_node) = 0;

  private:
    lex::Token token;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODE_H