#pragma once

#include "ast/node"
#include <string>

namespace ast {
  class VersionNumber : public Node {
    std::string m_number;
  public:
    VersionNumber(const char* number) : m_number(number) {}

    ~VersionNumber() {}

    void toString() {
      return m_number;
    }
  };
}
