#include "WrongCaseException.h"

#include <format>
#include <string>
#include <string_view>

namespace marex::parse {
[[nodiscard]] std::string exceptions::operator*(
    ExpectedCaseKind expected_case_kind) {
    switch (expected_case_kind) {
        case marex::parse::exceptions::
            ExpectedCaseKind::SnakeCase:
            return "snake_case";
        case marex::parse::exceptions::
            ExpectedCaseKind::PascalCase:
            return "PascalCase";
        case marex::parse::exceptions::
            ExpectedCaseKind::None:
            goto end;
    }

end:
    throw std::out_of_range("no valid enum kind");
}

namespace exceptions {
WrongCaseException::WrongCaseException(
    ExpectedCaseKind expected_case_kind,
    std::string_view for_target)
    : message(std::format("{} in {}",
                          *expected_case_kind,
                          for_target)) {}
}  // namespace exceptions
}  // namespace marex::parse