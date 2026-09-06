#ifndef MAREX_PARSE_RETRUNNODE_H
#define MAREX_PARSE_RETRUNNODE_H
#include <optional>
#include <string>

#include "Token.h"
#include "nodes/FileItem.h"

namespace marex::parse {
enum struct ExpressionKind : std::uint8_t;

class ReturnNode final : public FileItem {
   public:
    explicit ReturnNode(lex::Token&& token);

    [[nodiscard]] std::string as_c() override;

    void parse(ParserPack& pack) override;

   private:
    ExpressionKind type_kind{};
    std::optional<std::string> value;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_RETRUNNODE_H