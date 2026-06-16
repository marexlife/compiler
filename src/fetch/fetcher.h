#ifndef COMPILER_FETCH_FETCH_H_
#define COMPILER_FETCH_FETCH_H_
#include <filesystem>
#include <string>

namespace compiler::fetch {
class Fetcher final {
 public:
  Fetcher() = default;
  Fetcher(Fetcher&&) = delete;
  Fetcher& operator=(Fetcher&&) = delete;
  Fetcher(const Fetcher&) = delete;
  Fetcher& operator=(const Fetcher&) = delete;
  ~Fetcher() = default;

  [[nodiscard]] static std::basic_string<int> Fetch(
      const std::filesystem::path& filepath);
};
}  // namespace compiler::fetch
#endif  // COMPILER_FETCH_FETCH_H_