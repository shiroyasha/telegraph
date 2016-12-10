#pragma once

#include "ast/node"
#include "ast/identifier"
#include "ast/argument_list"
#include "ast/throw_list"
#include "ast/type"

namespace ast {
  class Event : public Node {
    Identifier* m_name;

    Type* m_return_type;
    ArgumentList* m_arguments;
    ThrowList* m_throws;

  public:
    Function(Identifier* name, Type* type, ArgumentList* args, ThrowList* throws) :
      m_name(name), m_return_type(type), m_arguments(args), m_throws(throws);

    ~Event() {
      delete m_name;
      delete m_return_type;
      delete m_arguments;
      delete m_throws;
    }

    void toString() {
      return m_return_type->toString() + " " + m_name->toString()
        + "(" + m_arguments.toString() + ") throws" + m_throw_list.toString() + ";";
    }
  };
}
