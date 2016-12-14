#include <iostream>
#include <cstring>

#include "ast/ast.hpp"

extern int yydebug;
extern int yylex();
extern FILE* yyin;
extern char* yytext;
extern int yyparse(ast::Telegraph*);

enum MODE { PARSE, TOKENIZE, DEBUG };

void tokenize() {
  int token;

  while ((token = yylex()) != 0) {
    printf("Token: %d (%s)\n", token, yytext);
  }
}

void parse() {
  ast::Telegraph* result = new ast::Telegraph();

  yyparse(result);

  result->display();

  delete result;
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
    parse();
    return 0;
  }

  if (mode == DEBUG) {
    yydebug = 1;
    parse();
    return 0;
  }

  if (mode == TOKENIZE) {
    tokenize();
    return 0;
  }

  return 0;
}
