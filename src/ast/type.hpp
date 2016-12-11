#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"

namespace ast {
  class Type : public Node {
    Identifier* m_name;

  public:
    Type(Identifier* name) : m_name(name) {}

    ~Type() {
      delete m_name;
    }

    std::string toString() {
      return m_name->toString();
    }
  };
}
