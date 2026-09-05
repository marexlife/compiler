#include "FuncNode.h"

#include <format>
#include <functional>
#include <memory>
#include <string>
#include <utility>

#include "FileItem.h"
#include "ParserPack.h"
#include "PrintNode.h"
#include "TokenKind.h"
#include "TypeKind.h"
#include "VarNode.h"
#include "exceptions/InvalidTokenException.h"

namespace marex::parse {
FuncNode::FuncNode(lex::Token&& token)
    : FileItem(std::move(token)) {}

[[nodiscard]] std::string FuncNode::as_c() {
    std::string func_results;

    for (auto& func_item : func_items) {
        func_results +=
            std::format("   {}", func_item->as_c());
    }

    return std::format("{} {}(void) {{\n{}{}}}\n",
                       *return_type, func_name,
                       func_results,
                       return_value.value_or(""));
}

void FuncNode::parse(ParserPack& pack) {
    parse_func_signature(pack);
    parse_func_body(pack);
}

void FuncNode::parse_func_signature(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::Func);

    func_name = pack.advance_if_matches_or_throw(
        lex::TokenKind::Identifier);

    parse_func_args(pack);

    if (pack.advance_if_matches(
            lex::TokenKind::OpenBrace)) {
        return_type = TypeKind::EmptyType;
        return;
    }

    pack.advance_if_matches_or_throw(
        lex::TokenKind::Arrow);

    return_type = type_kind_from_decl(pack.get_kind(),
                                      pack.get_pos());

    pack.advance();

    pack.advance_if_matches_or_throw(
        lex::TokenKind::OpenBrace);
}

void FuncNode::parse_func_args(ParserPack& pack) {
    pack.advance_if_matches_or_throw(
        lex::TokenKind::OpenBracket);

    while (!pack.advance_if_matches(
        lex::TokenKind::CloseBracket)) {
        pack.advance_if_matches_or_throw(
            lex::TokenKind::Identifier);
        pack.advance_if_matches_or_throw(
            lex::TokenKind::Colon);
        argument_types.emplace_back(
            type_kind_from_decl(pack.get_kind(),
                                pack.get_pos()));
    }
}

void FuncNode::parse_func_body(ParserPack& pack) {
    while (!pack.advance_if_matches(
        lex::TokenKind::CloseBrace)) {
        if (pack.advance_if_matches(
                lex::TokenKind::Return)) {
            return_value = std::format(
                "   return {};\n", pack.get_lexeme());
            pack.advance();

            continue;
        }

        auto node = std::invoke([&] -> std::unique_ptr<
                                        FileItem> {
            switch (pack.get_kind()) {
                case marex::lex::TokenKind::Var:
                    return std::make_unique<VarNode>(
                        pack.copy_out_token());
                case marex::lex::TokenKind::Print:
                    return std::make_unique<PrintNode>(
                        pack.copy_out_token());
                default:
                    throw InvalidTokenException(
                        pack.get_pos(),
                        pack.get_kind());
            }
        });

        node->parse(pack);

        func_items.emplace_back(std::move(node));
    }
}
}  // namespace marex::parse
