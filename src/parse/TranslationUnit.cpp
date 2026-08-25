#include "TranslationUnit.h"

#include <memory>

#include "ClassNode.h"
#include "FileItem.h"
#include "FuncNode.h"
#include "Logger.h"
#include "TokenKind.h"

namespace marex::parse {
std::string TranslationUnit::as_string() {
    return std::string{"file"};
}

void TranslationUnit::parse(ParserPack& pack) {
    while (!pack.is_at_end()) {
        file_items.emplace_back(
            create_file_item(pack));
    }
}

std::unique_ptr<FileItem>
TranslationUnit::create_file_item(ParserPack& pack) {
    switch (pack.get_kind()) {
        case lex::TokenKind::Func:
            return std::make_unique<FuncNode>(
                pack.move_out_token());
        case lex::TokenKind::Class:
            return std::make_unique<ClassNode>(
                pack.move_out_token());
        case lex::TokenKind::Var:
            core::Logger::log_fatal_error(
                "no global variables allowed");
        default:
            core::Logger::log_fatal_error(
                "invalid Token");
    }
}
}  // namespace marex::parse