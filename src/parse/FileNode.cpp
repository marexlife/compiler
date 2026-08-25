#include "FileNode.h"
#include "IdentNode.h"
#include "Node.h"
#include "TokenKind.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "exceptions/InvalidTokenException.h"
#include <format>
#include <functional>
#include <memory>
#include <utility>

namespace marex::parse {
[[nodiscard]] std::string FileNode::as_string() {
    return std::string{"file"};
}

void FileNode::parse(ParserPack &pack) {
    const auto result =
        std::invoke([&]() -> std::unique_ptr<AstNode> {
            switch (pack.get_kind()) {
            case lex::TokenKind::Identifier:
                return std::make_unique<IdentNode>(
                    pack.move_out_token());
            }

            throw exceptions::InvalidTokenException(std::format(""));
        });
}
} // namespace marex::parse