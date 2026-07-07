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

  static void Run(int argc, char** argv);
};
}  // namespace compiler::app
#endif  // COMPILER_APP_APP_H_
