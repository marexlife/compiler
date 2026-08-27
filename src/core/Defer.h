#ifndef MAREX_CORE_DEFER_H
#define MAREX_CORE_DEFER_H
namespace marex::core {
template <typename Functor> class Defer final {
public:
    /* implicit */ Defer(Functor functor)
        : defer_func(functor)
    {
    }

    Defer(Defer&&) = delete;
    Defer& operator=(Defer&&) = delete;
    Defer(const Defer&) = delete;
    Defer& operator=(const Defer&) = delete;

    ~Defer() { defer_func(); }

private:
    Functor defer_func;
};
} // namespace marex::core
#endif // MAREX_CORE_DEFER_H
