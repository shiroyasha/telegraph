#pragma once

#include "ast/node"
#include "ast/identifier"

namespace ast {
  class Type : public Node {
    Identifier* m_name;

  public:
    Type(Identifier* name) : m_name(name) {}

    ~Struct() {
      delete m_name;
    }

    void toString() {
      return m_name->toString();
    }
  };
}
