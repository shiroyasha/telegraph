#pragma once

#include <vector>
#include "ast/node.hpp"

#include "ast/version.hpp"
#include "ast/struct.hpp"
#include "ast/function.hpp"
#include "ast/enum.hpp"
#include "ast/event.hpp"
#include "ast/error.hpp"

namespace ast {
  class Telegraph : public Node {
    Version* m_version = NULL;

    std::vector<Struct*>   m_structures;
    std::vector<Function*> m_functions;
    std::vector<Enum*>     m_enums;
    std::vector<Event*>    m_events;
    std::vector<Error*>    m_errors;

  public:
    Telegraph() {}

    ~Telegraph() {
      if(m_version) delete m_version;

      for(auto n : m_structures) { delete n; }
      for(auto n : m_functions) { delete n; }
      for(auto n : m_enums) { delete n; }
      for(auto n : m_events) { delete n; }
      for(auto n : m_errors) { delete n; }
    }

    void set_version(Version* v) { m_version = v; }

    void add_struct(Struct* s)     { m_structures.push_back(s); }
    void add_function(Function* f) { m_functions.push_back(f); }
    void add_enum(Enum* e)         { m_enums.push_back(e); }
    void add_event(Event* e)       { m_events.push_back(e); }
    void add_error(Error* e)       { m_errors.push_back(e); }

    std::string version() {
      return m_version->number();
    }

    std::vector<Enum*> const &enums() const {
      return m_enums;
    }

    std::string toString() {
      std::string result;

      if(m_version) {
        result += m_version->toString() + "\n\n";
      }

      for(auto n : m_enums)      { result += n->toString() + "\n"; }
      result += "\n";

      for(auto n : m_errors)     { result += n->toString() + "\n"; }
      result += "\n";

      for(auto n : m_structures) { result += n->toString() + "\n"; }
      result += "\n";

      for(auto n : m_events)     { result += n->toString() + "\n"; }
      result += "\n";

      for(auto n : m_functions)  { result += n->toString() + "\n"; }

      return result;
    }
  };
}
