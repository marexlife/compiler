#ifndef MAREX_PARSE_NODE_H
#define MAREX_PARSE_NODE_H
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

    [[nodiscard]] std::string asString();

    [[nodiscard]] const lex::Token &getToken() const { return token; }

    [[nodiscard]] std::uint8_t getBindingPower() const {
        return token.getBindingPower();
    }

    [[nodiscard]] lex::TokenKind getKind() const {
        return token.getKind();
    }

    [[nodiscard]] std::string_view getLexeme() const {
        return token.getLexeme();
    }

  private:
    lex::Token token;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODE_H