#ifndef MAREX_PARSE_FILENODE_H
#define MAREX_PARSE_FILENODE_H
#include "Node.h"
#include <memory>
#include <vector>

namespace marex::parse {
class FileNode final : private AstNode {
  public:
    [[nodiscard]] std::string as_string() override;
    void parse(ParserPack &pack) override;

  private:
    std::vector<std::unique_ptr<AstNode>> file_items;
};
} // namespace marex::parse
#endif // MAREX_PARSE_FILENODE_H