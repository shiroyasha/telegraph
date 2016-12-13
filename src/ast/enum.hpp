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

    std::string name() {
      return m_name->toString();
    }

    std::vector<std::string> values() {
      return m_id_list->values();
    }

    std::string toString() {
      return "enum " + m_name->toString() + "{ " + m_id_list->toString() + " }";
    }
  };
}
