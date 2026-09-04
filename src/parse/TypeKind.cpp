#include "TypeKind.h"

#include <stdexcept>

namespace marex {
[[nodiscard]] std::string_view parse::operator*(
    TypeKind token_kind) {
    switch (token_kind) {
        case TypeKind::EmptyType:
            return "void";
        case TypeKind::IntType:
            return "int32_t";
        case TypeKind::FloatType:
            return "float";
        case TypeKind::BoolType:
            return "bool";
        case TypeKind::None:
            goto end;
    }

end:
    throw std::out_of_range("Not a valid TypeKind");
}
}  // namespace marex