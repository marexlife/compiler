#include "FileNode.h"

namespace marex::parse {
[[nodiscard]] std::string FileNode::as_string() {
    return std::string{"file"};
}

void FileNode::parse(ParserPack &pack) {
    
}
} // namespace marex::parse