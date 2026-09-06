#ifndef MAREX_PARSE_TRANSLATIONUNIT_H
#define MAREX_PARSE_TRANSLATIONUNIT_H
#include <memory>
#include <vector>

#include "ParserPack.h"
#include "nodes/Parsable.h"

namespace marex::parse {
class TranslationUnit final {
   public:
    [[nodiscard]] std::string as_c();
    void parse(ParserPack& pack);

   private:
    [[nodiscard]] static std::unique_ptr<AstNode>
    create_file_item(ParserPack& pack);

    std::vector<std::unique_ptr<AstNode>> file_items;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_TRANSLATIONUNIT_H