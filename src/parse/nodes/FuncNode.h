#ifndef MAREX_PARSE_FUNCNODE_H
#define MAREX_PARSE_FUNCNODE_H
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "FileItem.h"
#include "Token.h"

namespace marex::parse {
enum class [[nodiscard]] TypeKind : std::uint8_t;

class FuncNode final : public FileItem {
   public:
    explicit FuncNode(lex::Token&& token);

    [[nodiscard]] std::string as_string() override;

    void parse(ParserPack& pack) override;

    void parse_func_signature(ParserPack& pack);
    void parse_func_body(ParserPack& pack);

   private:
    std::string func_name;
    TypeKind return_type{};
    std::vector<std::unique_ptr<FileItem>> func_items;
    std::optional<std::string> return_value =
        std::nullopt;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FUNCNODE_H