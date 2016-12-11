#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/type.hpp"

namespace ast {
  class Array : public Type {
  public:
    Array(Identifier* name) : Type(name) {}

    std::string toString() {
      return "[" + Type::toString() + "]";
    }
  };
}
