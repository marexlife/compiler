#ifndef MAREX_CORE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H
#define MAREX_CORE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H
#include <exception>

namespace marex::core {
class NotImplementedException final
    : public std::exception {
   public:
    NotImplementedException();
};
}  // namespace marex::core
#endif  // MAREX_CORE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H