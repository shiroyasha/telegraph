#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"

namespace ast {
  class ThrowList : public Node {
  private:
    IdentifierList* m_id_list;

  public:
    ThrowList() {}
    ThrowList(IdentifierList* list) : m_id_list(list) { }

    ~ThrowList() {
      if(m_id_list) delete m_id_list;
    }

    std::string toString() {
      if(m_id_list) return m_id_list->toString();

      return "";
    }
  };
}
