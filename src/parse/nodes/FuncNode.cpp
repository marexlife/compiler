#include "FuncNode.h"

#include <cstddef>
#include <cstdint>
#include <format>
#include <functional>
#include <memory>
#include <string>
#include <utility>

#include "Defer.h"
#include "FileItem.h"
#include "Logging.h"
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
    auto get_func_args = [&]() -> std::string {
        std::string func_args_string;

        std::size_t count{};

        for (auto& [arg_name, arg_type] : args) {
            core::Defer iter_end = [&] { ++count; };

            func_args_string += *arg_type;
            func_args_string += ' ';
            func_args_string += arg_name;

            if (count != args.size() - 1) {
                func_args_string += ", ";
            }
        }

        if (func_args_string.empty()) {
            func_args_string = "void";
        }

        return func_args_string;
    };

    auto get_func_code = [&]() -> std::string {
        std::string func_content_string;

        for (auto& func_item : func_items) {
            func_content_string += std::format(
                "    {}", func_item->as_c());
        }

        return func_content_string;
    };

    return std::format(
        "{} {}({}) {{\n{}{}}}\n", *return_type,
        func_name, std::invoke(get_func_args),
        std::invoke(get_func_code), return_value);
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

    core::log_info("pre: parsed func args");
    uintmax_t arg_count = 1;

    if (pack.advance_if_matches(
            lex::TokenKind::CloseBracket)) {
        return;
    }

    do {
        core::Defer defer_arg_increment = [&] {
            ++arg_count;
        };

        core::log_info(
            std::format("arg count: {}", arg_count));

        auto func_arg = std::invoke([&] -> FuncArg {
            auto name =
                pack.advance_if_matches_or_throw(
                    lex::TokenKind::Identifier);
            pack.advance_if_matches_or_throw(
                lex::TokenKind::Colon);
            auto type = type_kind_from_decl(
                pack.get_kind(), pack.get_pos());
            pack.advance();

            return FuncArg{
                .arg_name = name,
                .arg_type = type,
            };
        });

        args.emplace_back(std::move(func_arg));
    } while (pack.advance_if_matches(
        lex::TokenKind::Comma));

    pack.advance_if_matches_or_throw(
        lex::TokenKind::CloseBracket);

    core::log_info("post: parsed func args");
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
