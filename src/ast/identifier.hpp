#pragma once

#include <string>
#include "ast/node.hpp"

namespace ast {
  class Identifier : public Node {
    std::string m_name;
  public:
    Identifier(const char* name) : m_name(name) {}

    ~Identifier() {}

    std::string toString() {
      return m_name;
    }
  };
}
