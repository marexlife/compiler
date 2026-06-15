#ifndef COMPILER_APP_APP_H_
#define COMPILER_APP_APP_H_
namespace compiler::app {
class App final {
 public:
  constexpr App() = default;
  App(App&&) = delete;
  App& operator=(App&&) = delete;
  App(const App&) = delete;
  App& operator=(const App&) = delete;
  ~App() = default;

  void Run();

 private:
};
}  // namespace compiler::app
#endif  // COMPILER_APP_APP_H_