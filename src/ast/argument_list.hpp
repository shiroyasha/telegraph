#pragma once

#include <vector>
#include "ast/node.hpp"
#include "ast/argument.hpp"

namespace ast {
  class ArgumentList : public Node {
    std::vector<Argument*> m_arguments;

  public:
    ArgumentList() {}
    ArgumentList(Argument* argument) {
      m_arguments.push_back(argument);
    }

    ~ArgumentList() {
      for(Argument* arg : m_arguments) {
        delete arg;
      }
    }

    void add(Argument* arg) {
      m_arguments.push_back(arg);
    }

    std::string toString() {
      if(m_arguments.empty()) return "";

      std::string result;

      for(auto arg : m_arguments) {
        result += arg->toString() + ", ";
      }

      return result.substr(0, result.size() - 1);
    }
  };
}
