#ifndef MAREX_PARSE_TRANSLATIONUNIT_H
#define MAREX_PARSE_TRANSLATIONUNIT_H
#include <memory>
#include <vector>

#include "FileItem.h"
#include "ParserPack.h"

namespace marex::parse {
class TranslationUnit final {
public:
    [[nodiscard]] static std::string as_string();
    void parse(ParserPack& pack);

private:
    [[nodiscard]] static  std::unique_ptr<FileItem>
    create_file_item(ParserPack& pack);

    std::vector<std::unique_ptr<FileItem>> file_items;
};
} // namespace marex::parse
#endif // MAREX_PARSE_TRANSLATIONUNIT_H