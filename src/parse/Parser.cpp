#include "Parser.h"

#include <sys/types.h>

#include <utility>

#include "ParserPack.h"
#include "TokenStream.h"
#include "TranslationUnit.h"

namespace marex::parse {
TranslationUnit Parser::run(
    lex::TokenStream&& token_stream) {
    return parse(ParserPack{std::move(token_stream)});
}

TranslationUnit Parser::parse(ParserPack&& pack) {
    return TranslationUnit().parse(pack);
}
}  // namespace marex::parse
