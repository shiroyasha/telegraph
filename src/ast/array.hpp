#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/type.hpp"

namespace ast {
  class Array : public Type {
  public:
    Argument(Identifier* name) : Type(name) {}

    void toString() {
      return "[" + Type::toString() + "]";
    }
  };
}
