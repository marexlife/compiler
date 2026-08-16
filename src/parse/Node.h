#ifndef MAREX_PARSE_NODE_H
#define MAREX_PARSE_NODE_H
#include "Token.h"
#include <cstdint>

namespace marex::parse {
class Node {
  public:
    explicit Node(lex::Token &token);

    Node(Node &&) = default;
    Node &operator=(Node &&) = default;
    Node(const Node &) = delete;
    Node &operator=(const Node &) = delete;
    virtual ~Node() = default;

    [[nodiscard]] std::uint8_t getBindingPower() const;
    void setBindingPower(std::uint8_t bindingPower);

  private:
    std::uint8_t bindingPower{};
};
} // namespace marex::parse
#endif // MAREX_PARSE_NODE_H