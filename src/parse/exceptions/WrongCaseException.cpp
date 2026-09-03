#include "WrongCaseException.h"

#include <format>
#include <string>
#include <string_view>

namespace marex::parse {
[[nodiscard]] std::string exceptions::operator*(
    ExpectedCaseKind expected_case_kind) {
    switch (expected_case_kind) {
        case marex::parse::ExpectedCaseKind::SnakeCase:
            return "snake_case";
        case marex::parse::ExpectedCaseKind::
            PascalCase:
            return "PascalCase";
        case marex::parse::ExpectedCaseKind::None:
            goto end;
    }

end:
    throw std::out_of_range(
        "not a valid case enum kind");
}

namespace exceptions {
WrongCaseException::WrongCaseException(
    ExpectedCaseKind expected_case_kind,
    std::string_view for_target)
    : message(std::format(
          "WrongCasing: Expected {} for {}",
          *expected_case_kind, for_target)) {}
}  // namespace exceptions
}  // namespace marex::parse