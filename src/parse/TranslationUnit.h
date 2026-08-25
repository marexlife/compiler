#ifndef MAREX_PARSE_FILENODE_H
#define MAREX_PARSE_FILENODE_H
#include <memory>
#include <vector>

#include "FileItem.h"
#include "ParserPack.h"

namespace marex::parse {
class TranslationUnit final {
   public:
    [[nodiscard]] static std::string as_string();
    TranslationUnit parse(ParserPack& pack);

   private:
    static std::unique_ptr<FileItem> create_file_item(
        ParserPack& pack);

    std::vector<std::unique_ptr<FileItem>> file_items;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FILENODE_H