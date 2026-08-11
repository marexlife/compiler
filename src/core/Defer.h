#ifndef MAREX_CORE_DEFER_H
#define MAREX_CORE_DEFER_H
namespace marex::core {
template <typename Functor> class Defer final {
  public:
    explicit Defer(Functor functor) : deferdFunc(functor) {}

    Defer(Defer &&) = delete;
    Defer &operator=(Defer &&) = delete;
    Defer(const Defer &) = delete;
    Defer &operator=(const Defer &) = delete;

    ~Defer() { deferdFunc(); }

  private:
    Functor deferdFunc;
};
} // namespace marex::core
#endif // MAREX_CORE_DEFER_H
