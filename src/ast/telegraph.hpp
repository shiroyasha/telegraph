#pragma once

#include "ast/node"
#include "ast/identifier"
#include "ast/block"

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

    void toString() {
      std::string result;

      for(auto node : m_nodes) {
        result += node->toString() + "\n";
      }

      return result;
    }
  };
}
