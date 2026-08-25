#ifndef MAREX_PARSE_FILENODE_H
#define MAREX_PARSE_FILENODE_H
#include <memory>
#include <vector>

#include "FileItem.h"
#include "Node.h"
#include "ParserPack.h"

namespace marex::parse {
class FileNode final : private AstNode {
   public:
    [[nodiscard]] std::string as_string() override;
    void parse(ParserPack& pack) override;

   private:
    static std::unique_ptr<FileItem> visit_token_kind(
        ParserPack& pack);

    std::vector<std::unique_ptr<FileItem>> file_items;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FILENODE_H