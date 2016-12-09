#pragma once

namespace ast {
  class Node {
  private:
    std::vector<Node*> children;

  public:
    Node() {
    }

    ~Node() {
      for(Node* node : children) {
        delete node;
      }
    }

    void add(Node* node) {
      children->push_back(node);
    }
  }
};
