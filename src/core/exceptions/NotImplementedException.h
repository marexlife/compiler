#ifndef MAREX_CORE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H
#define MAREX_CORE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H
#include <exception>

namespace marex::core::exceptions {
class NotImplementedException final
    : public std::exception {
   public:
    NotImplementedException();
};
}  // namespace marex::core::exceptions
#endif  // MAREX_CORE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H