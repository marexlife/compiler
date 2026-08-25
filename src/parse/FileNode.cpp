#include "FileNode.h"

#include <functional>
#include <memory>

#include "FuncNode.h"
#include "Node.h"
#include "TokenKind.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
[[nodiscard]] std::string FileNode::as_string() {
    return std::string{"file"};
}

void FileNode::parse(ParserPack& pack) {
    auto result =
        std::invoke([&]() -> std::unique_ptr<AstNode> {
            switch (pack.get_kind()) {
                case lex::TokenKind::Func:
                    return std::make_unique<FuncNode>(
                        pack.move_out_token());
                default:
                    throw exceptions::
                        InvalidTokenException(
                            pack.get_pos(),
                            "invalid token");
            }
        });
}
}  // namespace marex::parse