#pragma once

#include <vector>
#include "ast/node.hpp"
#include "ast/identifier.hpp"

namespace ast {
  class IdentifierList : public Node {
  private:
    std::vector<Identifier*> m_ids;

  public:
    IdentifierList() {}
    IdentifierList(Identifier* id) {
      m_ids.push_back(id);
    }

    ~IdentifierList() {
      for(auto id : m_ids) {
        delete id;
      }
    }

    std::vector<std::string> values() {
      std::vector<std::string> result;

      for(auto id : m_ids) {
        result.push_back(id->toString());
      }

      return result;
    }

    void add(Identifier* id) {
      m_ids.push_back(id);
    }

    std::string toString() {
      if(m_ids.empty()) return "";

      std::string result;

      for(auto id : m_ids) {
        result += id->toString() + ", ";
      }

      return result.substr(0, result.size() - 1);
    }
  };
}
