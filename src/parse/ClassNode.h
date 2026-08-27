#ifndef MAREX_PARSE_CLASSNODE_H
#define MAREX_PARSE_CLASSNODE_H
#include <string>

#include "FileItem.h"
#include "Token.h"

namespace marex::parse {
/// There can only be one ClassNode per file
class ClassNode final : public FileItem {
   public:
    explicit ClassNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;
    void parse_class_head(ParserPack& pack);
    void parse_class_signature(ParserPack& pack);

   private:
    std::optional<std::string> class_name;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_CLASSNODE_H
