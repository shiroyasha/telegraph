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

    void toString() {
      return "version " + m_number->toString();
    }
  };
}
