#pragma once

#include "ast/node.hpp"
#include "ast/identifier.hpp"
#include "ast/argument_list.hpp"
#include "ast/throw_list.hpp"
#include "ast/type.hpp"

namespace ast {
  class Function : public Node {
    Identifier* m_name;

    Type* m_return_type;
    ArgumentList* m_arguments;
    ThrowList* m_throws;

  public:
    Function(Identifier* name, Type* type, ArgumentList* args, ThrowList* throws) :
      m_name(name), m_return_type(type), m_arguments(args), m_throws(throws) {};

    ~Function() {
      delete m_name;
      delete m_return_type;
      delete m_arguments;
      delete m_throws;
    }

    std::string toString() {
      return m_return_type->toString() + " " + m_name->toString()
        + "(" + m_arguments->toString() + ") throws" + m_throws->toString() + ";";
    }
  };
}
