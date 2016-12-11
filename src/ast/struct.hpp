#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/block.hpp"

namespace ast {
  class Struct : public Node {
    Identifier* m_name;
    Block* m_block;

  public:
    Struct(Identifier* name, Block* block) : m_name(name), m_block(block) {}

    ~Struct() {
      delete m_name;
      delete m_block;
    }

    void toString() {
      return "struct " + m_name->toString() + " " + m_block->toString();
    }
  };
}
