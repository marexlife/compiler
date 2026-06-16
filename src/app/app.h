#ifndef COMPILER_APP_APP_H_
#define COMPILER_APP_APP_H_
namespace compiler::app {
class app final {
 public:
  app() = delete;
  app(app&&) = delete;
  app& operator=(app&&) = delete;
  app(const app&) = delete;
  app& operator=(const app&) = delete;
  ~app() = delete;

  static auto run(int argc, const char* const* argv) noexcept -> void;
};
}  // namespace compiler::app
#endif  // COMPILER_APP_APP_H_