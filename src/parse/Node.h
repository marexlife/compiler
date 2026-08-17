#ifndef MAREX_PARSE_NODE_H
#define MAREX_PARSE_NODE_H
#include "Token.h"

namespace marex::parse {
class Node {
  public:
    explicit Node(lex::Token &&token);

    Node(Node &&) = default;
    Node &operator=(Node &&) = default;
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;
    virtual ~Node() = default;

    [[nodiscard]] const lex::Token &getToken() const { return token; }

  private:
    lex::Token token;
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODE_H