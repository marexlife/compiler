#ifndef MAREX_PARSE_FUNCNODE_H
#define MAREX_PARSE_FUNCNODE_H
#include "FileItem.h"
#include "Token.h"

namespace marex::parse {
class FuncNode final : public FileItem {
public:
    explicit FuncNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;
};
} // namespace marex::parse
#endif // MAREX_PARSE_FUNCNODE_H