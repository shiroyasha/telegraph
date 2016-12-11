#pragma once

#include <string>
#include "ast/node.hpp"

namespace ast {
  class VersionNumber : public Node {
    std::string m_number;
  public:
    VersionNumber(const char* number) : m_number(number) {}

    ~VersionNumber() {}

    std::string toString() {
      return m_number;
    }
  };
}
