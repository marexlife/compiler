#ifndef MAREX_PARSE_FUNCNODE_H
#define MAREX_PARSE_FUNCNODE_H
#include <memory>
#include <string>
#include <vector>

#include "FileItem.h"
#include "ParserPack.h"
#include "Token.h"

namespace marex::parse {
enum class [[nodiscard]] TypeKind : std::uint8_t;

struct FuncArg final {
    std::string arg_name;
    TypeKind arg_type{};
};

class FuncNode final : public FileItem {
   public:
    explicit FuncNode(lex::Token&& token);

   protected:
    [[nodiscard]] std::string as_c() override;
    void parse(ParserPack& pack) override;

   private:
    void parse_func_signature(ParserPack& pack);
    void parse_func_body(ParserPack& pack);

    void parse_func_args(ParserPack& pack);

    std::string func_name;
    TypeKind return_type{};
    std::vector<std::unique_ptr<FileItem>> func_items;
    std::string return_value;
    std::vector<FuncArg> args;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_FUNCNODE_H