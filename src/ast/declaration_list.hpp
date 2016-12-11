#pragma once

#include <vector>
#include "ast/node.hpp"
#include "ast/declaration.hpp"

namespace ast {
  class DeclarationList : public Node {
    std::vector<Declaration*> m_declarations;

  public:
    DeclarationList() {}

    ~DeclarationList() {
      for(Declaration* d : m_declarations) {
        delete d;
      }
    }

    void add(Declaration* d) {
      m_declarations.push_back(d);
    }

    std::string toString() {
      std::string result;

      for(auto dec : m_declarations) {
        result += dec->toString() + ";\n";
      }

      return result;
    }
  };
}
