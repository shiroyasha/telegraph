#pragma once

#include "ast/node.hpp"
#include "ast/identifier_list.hpp"

namespace ast {
  class Enum : public Node {
  private:
    Identifier* m_name;
    IdentifierList* m_id_list;

  public:
    Enum(Identifier* name, IdentifierList* list) : m_name(name), m_id_list(list) {}

    ~Enum() {
      delete m_name;
      delete m_id_list;
    }

    std::string toString() {
      return "{ " + m_id_list->toString() + " }";
    }
  };
}
