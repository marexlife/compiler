#include "Walker.h"
#include "Node.h"
#include <memory>

namespace marex::walk {
void Walker::run(
    std::vector<std::vector<std::unique_ptr<parse::Node>>>
        &&listOfNodes) {
    for (auto &nodes : listOfNodes) {
        for (std::unique_ptr<parse::Node> &node : nodes) {
            node->print();
        }
    }
}
} // namespace marex::walk