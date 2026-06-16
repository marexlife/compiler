#ifndef COMPILER_APP_APP_H_
#define COMPILER_APP_APP_H_
namespace compiler::app {
class App final {
 public:
  App() = delete;
  App(App&&) = delete;
  App& operator=(App&&) = delete;
  App(const App&) = delete;
  App& operator=(const App&) = delete;
  ~App() = delete;

  [[nodiscard]] static int Run(int argc, const char* const* argv);
};
}  // namespace compiler::app
#endif  // COMPILER_APP_APP_H_