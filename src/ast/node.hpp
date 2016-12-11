#pragma once

#include <string>
#include <iostream>

namespace ast {
  class Node {
  public:
    virtual std::string toString() = 0;

    void display() {
      std::cout << toString() << std::endl;
    }
  };
}
