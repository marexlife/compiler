#include "FileNode.h"

#include <functional>
#include <memory>

#include "Node.h"
#include "TokenKind.h"
#include "VarNode.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
[[nodiscard]] std::string FileNode::as_string() {
    return std::string{"file"};
}

void FileNode::parse(ParserPack& pack) {
    auto result =
        std::invoke([&]() -> std::unique_ptr<AstNode> {
            switch (pack.get_kind()) {
                case lex::TokenKind::Var:
                    return std::make_unique<VarNode>(
                        pack.move_out_token());
                default:
                    throw exceptions::
                        InvalidTokenException(
                            pack.get_token().get_pos(),
                            "");
            }
        });
}
}  // namespace marex::parse