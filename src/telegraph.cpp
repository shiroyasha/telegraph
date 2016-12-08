#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

#include "lexer.yy.h"
#include "parser.tab.h"

int main(int argc, char** argv) {
  ++argv, --argc;  /* skip over program name */

  if (argc > 0) {
    yyin = fopen( argv[0], "r" );
  } else {
    yyin = stdin;
  }

  return yyparse();
}
