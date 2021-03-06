#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/block.hpp"
#include "ast/type.hpp"

namespace ast {
  class Event : public Node {
    Identifier* m_name;

    Type* m_type = NULL;
    Block* m_block = NULL;

  public:
    Event(Identifier* name, Block* block) : m_name(name), m_block(block) {}
    Event(Identifier* name, Type* type) : m_name(name), m_type(type) {}

    ~Event() {
      if(m_type) delete m_type;
      if(m_block) delete m_block;

      delete m_name;
    }

    std::string toString() {
      if(m_type) {
        return "event " + m_name->toString() + " publishes " + m_type->toString();
      } else {
        return "event " + m_name->toString() + " publishes " + m_block->toString();
      }
    }
  };
}
