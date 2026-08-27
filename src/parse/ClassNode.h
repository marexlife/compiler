#ifndef MAREX_PARSE_CLASSNODE_H
#define MAREX_PARSE_CLASSNODE_H
#include <memory>
#include <string>

#include "FileItem.h"
#include "Node.h"
#include "ParserPack.h"
#include "Token.h"

namespace marex::parse {
/// There can only be one ClassNode per file
class ClassNode final : public FileItem {
   public:
    explicit ClassNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;
    void parse_class_signature(ParserPack& pack);
    void parse_class_body(ParserPack& pack);

    [[nodiscard]] static std::unique_ptr<AstNode>
    visit_class_entry(ParserPack& pack);

   private:
    std::optional<std::string> class_name;
    std::optional<std::string> parent_class_name;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_CLASSNODE_H
