#pragma once

#include "ast/node"
#include "ast/identifier"
#include "ast/type"

namespace ast {
  class Array : public Type {
  public:
    Argument(Identifier* name) : Type(name) {}

    void toString() {
      return "[" + Type::toString() + "]";
    }
  };
}
