%{
#include <iostream>
/* #include <cstdlib> */
/* #include <cmath> */

#include "lexer.yy.h"

void yyerror(const char *s) {
  std::cout << "EEK, parse error!  Message: " << s << std::endl;
  exit(-1);
}

%}

%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token LEFT_BRACE
%token RIGHT_BRACE

%token SEMICOLON

%token KW_VERSION
%token KW_STRUCT
%token KW_ENUM
%token KW_EVENT
%token KW_PUBLISHES
%token KW_ERROR
%token KW_THROWS

%token VERSION_NUMBER

%token VARIABLE
%token CONSTANT

%%

input: { $$ = 1; }

%%
