#ifndef MAREX_PARSE_FUNCNODE_H
#define MAREX_PARSE_FUNCNODE_H
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
    static void parse_func_body(ParserPack& pack);

   private:
    TypeKind type_kind{};
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FUNCNODE_H