#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/type.hpp"

namespace ast {
  class Argument : public Node {
  private:
    Identifier* m_name;
    Type* m_type;

  public:
    Argument(Identifier* name, Type* type) : m_name(name), m_type(type) { }

    ~Argument() {
      delete m_name;
      delete m_type;
    }

    std::string toString() {
      return m_type->toString() + " " + m_name->toString();
    }
  };
}
