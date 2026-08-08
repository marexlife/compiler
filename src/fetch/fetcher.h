#ifndef COMPILER_FETCH_FETCHER_H
#define COMPILER_FETCH_FETCHER_H
#include <filesystem>
#include <string>

namespace compiler::fetch 
{
class Fetcher final 
{
  public:
    static const std::size_t resultReserveAmount = 100;

    Fetcher() = delete;
    Fetcher(Fetcher&&) = delete;
    Fetcher& operator=(Fetcher&&) = delete;
    Fetcher(const Fetcher&) = delete;
    Fetcher& operator=(const Fetcher&) = delete;
    ~Fetcher() = delete;

    [[nodiscard]] static std::string run(
      std::filesystem::path&& filepath);
};
}  // namespace compiler::fetch
#endif  // COMPILER_FETCH_FETCHER_H