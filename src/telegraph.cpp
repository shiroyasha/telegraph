#include <iostream>

#include "lexer.yy.h"
#include "parser.tab.h"

extern int yydebug;

enum MODE { PARSE, TOKENIZE, DEBUG };

void tokenize() {
  int token;

  while ((token = yylex()) != 0) {
    printf("Token: %d (%s)\n", token, yytext);
  }
}


int main(int argc, char** argv) {
  int mode = PARSE;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--debug") == 0) {
      mode = DEBUG;
    } else if(strcmp(argv[i], "--tokens") == 0) {
      mode = TOKENIZE;
    } else {
      yyin = fopen(argv[i], "r");
    }
  }

  if (mode == PARSE) {
    return yyparse();
  }

  if (mode == DEBUG) {
    yydebug = 1;
    return yyparse();
  }

  if (mode == TOKENIZE) {
    tokenize();
    return 0;
  }

  return 0;
}
