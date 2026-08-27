#include "Walker.h"
#include "AstNode.h"
#include <memory>

namespace marex::walk {
void Walker::run(std::vector<
    std::vector<std::unique_ptr<parse::AstNode>>>&&
        list_of_nodes)
{
    for (auto& nodes : list_of_nodes) {
        for (std::unique_ptr<parse::AstNode>& node :
            nodes) {
            auto result = node->as_string();

            std::cout << result << ",\n";
        }
    }
}
} // namespace marex::walk