#include "Parser.h"

#include "ParserPack.h"
#include "TokenStream.h"
#include <sys/types.h>
#include <utility>

namespace marex::parse {
void Parser::run(lex::TokenStream &&token_stream) {
    parse(ParserPack{std::move(token_stream)});
}

void Parser::parse([[maybe_unused]] ParserPack &&pack) {
    
}
} // namespace marex::parse
