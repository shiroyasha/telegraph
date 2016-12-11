#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/block.hpp"

namespace ast {
  class Error : public Node {
    Identifier* m_name;
    Block* m_block;

  public:
    Error(Identifier* name, Block* block) : m_name(name), m_block(block) {}

    ~Enum() {
      delete m_name;
      delete m_block;
    }

    void toString() {
      return "error " + m_name->toString() + " " + m_block->toString();
    }
  };
}
