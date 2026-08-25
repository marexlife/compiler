#ifndef MAREX_PARSE_FILENODE_H
#define MAREX_PARSE_FILENODE_H
#include <memory>
#include <vector>

#include "FileItem.h"
#include "Node.h"

namespace marex::parse {
class FileNode final : private AstNode {
   public:
    [[nodiscard]] std::string as_string() override;
    void parse(ParserPack& pack) override;

   private:
    std::vector<std::unique_ptr<FileItem>> file_items;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FILENODE_H