#pragma once

#include "ast/node"
#include "ast/identifier"
#include "ast/block"

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
