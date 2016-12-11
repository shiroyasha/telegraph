#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"

namespace ast {
  class ThrowList : public Node {
    std::vector<Identifier*> m_ids;

  public:
    ThrowList() {}
    ThrowList(Identifier* id) {
      m_ids.push_back(id);
    }

    ~ThrowList() {
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
