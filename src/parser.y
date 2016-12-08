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

%start input

%%

input:
  /* empty line */
  | statement input { $$ = 1; }
  ;


statement:
  version
  | struct
  | error_def
  | enum
  | event
  | function
  ;


version:
  KW_VERSION VERSION_NUMBER { std::cout << "version found" << std::endl; }
  ;


struct:
  KW_STRUCT CONSTANT block { std::cout << "struct found" << std::endl; }
  ;

enum:
  KW_ENUM CONSTANT '{' constant_list '}' { std::cout << "enum found" << std::endl; }
  ;

error_def:
  KW_ERROR CONSTANT block { std::cout << "error found" << std::endl; }
  ;


event:
  KW_EVENT VARIABLE KW_PUBLISHES CONSTANT ';' { std::cout << "event found" << std::endl; }
  | KW_EVENT VARIABLE KW_PUBLISHES block ';' { std::cout << "event found" << std::endl; }
  ;


function:
    type VARIABLE '(' arg_list ')' throws ';' { std::cout << "function found" << std::endl; }
  | VARIABLE VARIABLE '(' arg_list ')' throws ';' { std::cout << "function found" << std::endl; }
  ;

block:
  '{' declaration_list '}' { std::cout << "block found" << std::endl; }
  ;


declaration_list:
  /* nothing */
  | declaration ';' declaration_list
  ;


arg_list:
  /* nothing */
  | declaration
  | declaration ',' arg_list
  ;

declaration:
  type VARIABLE { std::cout << "declaration found" << std::endl; }

type:
  CONSTANT
  | '[' CONSTANT ']'
  ;

throws:
  /* nothing */
  | KW_THROWS constant_list
  ;

constant_list:
  CONSTANT
  | CONSTANT ',' constant_list
  ;

%%
