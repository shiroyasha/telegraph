#pragma once

#include <vector>
#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/block.hpp"

namespace ast {
  class Telegraph : public Node {
    std::vector<Node*> m_nodes;

  public:
    Telegraph() {}

    ~Telegraph() {
      for(auto node : m_nodes) {
        delete node;
      }
    }

    void add(Node* node) {
      m_nodes.push_back(node);
    }

    std::string toString() {
      std::string result;

      for(auto node : m_nodes) {
        result += node->toString() + "\n";
      }

      return result;
    }
  };
}
