#pragma once

#include "ast/node"
#include "ast/version_number"

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
