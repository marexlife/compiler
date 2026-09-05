#ifndef MAREX_PARSE_RETRUNNODE_H
#define MAREX_PARSE_RETRUNNODE_H
#include <optional>
#include <string>

#include "Token.h"
#include "nodes/FileItem.h"

namespace marex::parse {
class ReturnNode final : public FileItem {
   public:
    [[nodiscard]] std::string as_c() override;

    void parse(ParserPack& pack) override;

    explicit ReturnNode(lex::Token&& token);

   private:
    std::optional<std::string> value;
};
}  // namespace marex::parse
#endif  // MAREX_PARSE_RETRUNNODE_H