#pragma once

#include "ast/node"
#include "ast/identifier"

namespace ast {
  class IdentifierList : public Node {
    std::vector<Identifier*> m_ids;

  public:
    IdentifierList() {}

    ~IdentifierList() {
      for(auto id : m_ids) {
        delete id;
      }
    }

    void toString() {
      if(m_ids.empty()) return "";

      std::string result;

      for(auto id : m_ids) {
        result += id->toString() + ", ";
      }

      return result.substr(0, result.size() - 1);
    }
  };
}
