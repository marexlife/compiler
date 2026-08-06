#ifndef COMPILER_CORE_DEFER_H_
#define COMPILER_CORE_DEFER_H_
namespace compiler::core {
template <typename F>
class Defer final {
 public:
  explicit Defer(F&& func) : func_(func) {}

  Defer(Defer&&) = delete;
  Defer& operator=(Defer&&) = delete;
  Defer(const Defer&) = delete;
  Defer& operator=(const Defer&) = delete;

  ~Defer() { func_(); }

 private:
  F func_;
};
}  // namespace compiler::core
#endif  // COMPILER_CORE_DEFER_H_
