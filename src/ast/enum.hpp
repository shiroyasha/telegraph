#pragma once

#include "ast/node.hpp"
#include "ast/identifier_list.hpp"

namespace ast {
  class Enum : public Node {
    IdentifierList* m_id_list;

  public:
    Enum(IdentifierLIst* list) : m_id_list(list) {}

    ~Enum() {
      delete m_id_list;
    }

    void toString() {
      return "{ " + m_id_list->toString() + " }";
    }
  };
}
