#ifndef MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H
#define MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H
#include <exception>
#include <format>
#include <string>

#include "SourcePos.h"

namespace marex::parse::exceptions {
class InvalidTokenException final
    : public std::exception {
   public:
    explicit InvalidTokenException(
        lex::SourcePos source_pos,
        std::string&& message)
        : full_message(std::format(
              "at {}\n{}", source_pos.to_string(),
              message)) {}

    const char* what() const noexcept override;

   private:
    std::string full_message;
};
}  // namespace marex::parse::exceptions
#endif  // MAREX_PARSE_EXCEPTIONS_INVALIDTOKENEXCEPTION_H