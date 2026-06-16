#include "app.h"

#include "cli.h"
#include "fetcher.h"

using compiler::cl::Cli;

namespace compiler::app {
void App::Run(const int argc, const char* const* const argv) {
  const auto user_file_path = Cli::GetUserFilesPath(argc, argv);

  fetch::Fetcher::Fetch();
}
}  // namespace compiler::app