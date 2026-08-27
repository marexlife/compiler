#include "TranslationUnit.h"

#include <memory>
#include <utility>

#include "ClassNode.h"
#include "FileItem.h"
#include "FuncNode.h"
#include "Logger.h"
#include "TokenKind.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
std::string TranslationUnit::as_string() {
    return std::string{"file"};
}

void TranslationUnit::parse(ParserPack& pack) {
    while (!pack.is_at_end()) {
        std::unique_ptr<FileItem> file_item =
            create_file_item(pack);

        file_item->parse(pack);

        file_items.emplace_back(std::move(file_item));
    }
}

std::unique_ptr<FileItem>
TranslationUnit::create_file_item(ParserPack& pack) {
    switch (pack.get_kind()) {
        case lex::TokenKind::Func:
            return std::make_unique<FuncNode>(
                pack.copy_out_token());
        case lex::TokenKind::Class:
            core::Logger::log_info("Class\n");
            return std::make_unique<ClassNode>(
                pack.copy_out_token());
        case lex::TokenKind::Var:
            throw exceptions::InvalidTokenException(
                pack.get_pos(),
                "no global variables allowed");
        default:
            throw exceptions::InvalidTokenException(
                pack.get_pos(), pack.get_kind());
    }
}
}  // namespace marex::parse
