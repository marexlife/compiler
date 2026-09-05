#ifndef MAREX_PARSE_FUNCNODE_H
#define MAREX_PARSE_FUNCNODE_H
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "FileItem.h"
#include "ParserPack.h"
#include "Token.h"

namespace marex::parse {
enum class [[nodiscard]] TypeKind : std::uint8_t;

class FuncNode final : public FileItem {
   public:
    explicit FuncNode(lex::Token&& token);

   protected:
    [[nodiscard]] std::string as_c() override;
    void parse(ParserPack& pack) override;

   private:
    [[nodiscard]] std::string func_args_as_c();

    void parse_func_signature(ParserPack& pack);
    void parse_func_body(ParserPack& pack);

    void parse_func_args(ParserPack& pack);

    std::string func_name;
    TypeKind return_type{};
    std::vector<std::unique_ptr<FileItem>> func_items;
    std::optional<std::string> return_value =
        std::nullopt;
    std::vector<TypeKind> argument_types;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FUNCNODE_H