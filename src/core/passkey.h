#ifndef COMPILER_CORE_PASSKEY_H_
#define COMPILER_CORE_PASSKEY_H_
#include <type_traits>

namespace compiler::lex {
template <typename Factory>
  requires std::is_class_v<Factory>
class Passkey final {
  friend Factory;

 public:
  Passkey(Passkey&&) = delete;
  Passkey& operator=(Passkey&&) = delete;
  Passkey(const Passkey&) = delete;
  Passkey& operator=(const Passkey&) = delete;
  ~Passkey() = default;

 private:
  Passkey() = default;
};
}  // namespace compiler::lex
#endif  // COMPILER_CORE_PASSKEY_H_