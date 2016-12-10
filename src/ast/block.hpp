#pragma once

#include "ast/node"
#include "ast/declaration_list"

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
