#ifndef MAREX_PARSE_EXCEPTIONS_WRONGCASEEXCEPTION_H
#define MAREX_PARSE_EXCEPTIONS_WRONGCASEEXCEPTION_H
#include <exception>
#include <string>
#include <string_view>

#include "linter/ExpectedCaseKind.h"

namespace marex::parse::exceptions {
[[nodiscard]] std::string operator*(
    ExpectedCaseKind expected_case_kind);

class WrongCaseException final
    : public std::exception {
   public:
    explicit WrongCaseException(
        ExpectedCaseKind expected_case_kind,
        std::string_view for_target);

    const char* what() const noexcept override {
        return message.data();
    }

   private:
    std::string message;
};
}  // namespace marex::parse::exceptions
#endif  // MAREX_PARSE_EXCEPTIONS_WRONGCASEEXCEPTION_H