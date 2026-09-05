#ifndef MAREX_PARSE_TRANSLATIONUNIT_H
#define MAREX_PARSE_TRANSLATIONUNIT_H
#include <memory>
#include <vector>

#include "ParserPack.h"
#include "nodes/AstNode.h"
#include "nodes/FileItem.h"

namespace marex::parse {
class TranslationUnit final : private AstNode {
   public:
    [[nodiscard]] std::string as_c() override;
    void parse(ParserPack& pack) override;

   private:
    [[nodiscard]] static std::unique_ptr<FileItem>
    create_file_item(ParserPack& pack);

    std::vector<std::unique_ptr<FileItem>> file_items;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_TRANSLATIONUNIT_H