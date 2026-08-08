#ifndef COMPILER_CORE_DEFER_H
#define COMPILER_CORE_DEFER_H
namespace compiler::core {
template <typename Functor> class Defer final {
public:
    explicit Defer(Functor functor)
        : deferdFunc(functor)
    {
    }

    Defer(Defer&&) = delete;
    Defer& operator=(Defer&&) = delete;
    Defer(const Defer&) = delete;
    Defer& operator=(const Defer&) = delete;

    ~Defer() { deferdFunc(); }

private:
    Functor deferdFunc;
};
} // namespace compiler::core
#endif // COMPILER_CORE_DEFER_H
