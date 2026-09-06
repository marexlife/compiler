#ifndef MAREX_PARSE_ASSIGNMENT_H
#define MAREX_PARSE_ASSIGNMENT_H
#include "Token.h"
#include "nodes/DuoOpNode.h"

namespace marex::parse {
class Assignment final : public DuoOpNode {
   public:
    explicit Assignment(lex::Token&& token);

    [[nodiscard]] std::string as_c() override;

    void parse(ParserPack& pack) override;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_ASSIGNMENT_H