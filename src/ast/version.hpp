#pragma once

#include "ast/node.hpp"
#include "ast/version_number.hpp"

namespace ast {
  class Version : public Node {
    VersionNumber* m_number;

  public:
    Version(VersionNumber* number) : m_number(number) {}

    ~Version() {
      delete m_number;
    }

    std::string number() {
      return m_number->toString();
    }

    std::string toString() {
      return "version " + m_number->toString();
    }
  };
}
