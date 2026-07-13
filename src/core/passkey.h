#ifndef COMPILER_CORE_PASSKEY_H_
#define COMPILER_CORE_PASSKEY_H_
#include <type_traits>

namespace compiler::core {
/// used for bridging between a Factory and an Object ctor
template <typename Factory>
  requires std::is_class_v<Factory>
class [[nodiscard]] Passkey final {
  friend Factory;

 public:
  Passkey(Passkey&&) = default;

  Passkey& operator=(Passkey&&) = delete;
  Passkey(const Passkey&) = delete;
  Passkey& operator=(const Passkey&) = delete;
  ~Passkey() = default;

 private:
  Passkey() = default;
};
}  // namespace compiler::core
#endif  // COMPILER_CORE_PASSKEY_H_