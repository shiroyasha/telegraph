#pragma once

#include <string>
#include "ast/node.hpp"

namespace ast {
  class Event : public Node {
    std::string m_name;
  public:
    Identifier(const char* name) : m_name(name) {}

    ~Identifier() {}

    void toString() {
      return m_name;
    }
  };
}
