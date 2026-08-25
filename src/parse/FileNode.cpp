#include "FileNode.h"

#include <functional>
#include <memory>

#include "FileItem.h"
#include "FuncNode.h"
#include "TokenKind.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
[[nodiscard]] std::string FileNode::as_string() {
    return std::string{"file"};
}

void FileNode::parse(ParserPack& pack) {
    for (;;) {
        auto result = std::invoke(
            [&]() -> std::unique_ptr<FileItem> {
                switch (pack.get_kind()) {
                    case lex::TokenKind::Func:
                        return std::make_unique<
                            FuncNode>(
                            pack.move_out_token());
                    case lex::TokenKind::Var:
                        throw exceptions::
                            InvalidTokenException(
                                pack.get_pos(),
                                "no global variables "
                                "allowed");
                    default:
                        throw exceptions::
                            InvalidTokenException(
                                pack.get_pos(),
                                "invalid token");
                }
            });
    }
}
}  // namespace marex::parse