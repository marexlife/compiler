#include "Walker.h"
#include "Node.h"
#include <memory>

namespace marex::walk {
void Walker::run(
    std::vector<std::vector<std::unique_ptr<parse::Node>>>
        &&list_of_nodes) {
    for (auto &nodes : list_of_nodes) {
        for (std::unique_ptr<parse::Node> &node : nodes) {
            auto result = node->as_string();

            std::cout << result << ",\n";
        }
    }
}
} // namespace marex::walk