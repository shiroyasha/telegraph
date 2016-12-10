#pragma once

#include "ast/node"
#include "ast/identifier"
#include "ast/type"

namespace ast {
  class Declaration : public Node {
    Identifier* m_name;
    Type* m_type;

  public:
    Declaration(Identifier* name, Type* type) : m_name(name), m_type(type) { }

    ~Declaration() {
      delete m_name;
      delete m_type;
    }

    void toString() {
      return m_type->toString() + " " + m_name->toString();
    }
  };
}
