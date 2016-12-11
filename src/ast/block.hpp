#pragma once

#include "ast/node.hpp"
#include "ast/declaration_list.hpp"

namespace ast {
  class Block : public Node {
    DeclarationList* m_declaration_list;

  public:
    Block(DeclarationList* list) : m_declaration_list(list) {}

    ~Block() {
      delete m_declaration_list;
    }

    void toString() {
      return "{\n" + m_declaration_list->toString() + "}";
    }
  };
}
