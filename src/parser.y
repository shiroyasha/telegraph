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

%token COLON
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

%start input

%%

input:
  /* empty line */
  | statement SEMICOLON input { $$ = 1; }
  ;


statement:
  version
  | struct
  | error_def
  | event
  | function
  ;


version:
  KW_VERSION VERSION_NUMBER { std::cout << "version found" << std::endl; }
  ;


struct:
  KW_STRUCT CONSTANT block { std::cout << "struct found" << std::endl; }
  ;

error_def:
  KW_ERROR CONSTANT block { std::cout << "error found" << std::endl; }
  ;


event:
  KW_EVENT VARIABLE KW_PUBLISHES CONSTANT { std::cout << "event found" << std::endl; }
  ;


function:
  CONSTANT VARIABLE LEFT_PARENTHESIS arg_list RIGHT_PARENTHESIS throws SEMICOLON { std::cout << "function found" << std::endl; }
  VARIABLE VARIABLE LEFT_PARENTHESIS arg_list RIGHT_PARENTHESIS throws SEMICOLON { std::cout << "function found" << std::endl; }
  ;

block:
  LEFT_BRACE declaration_list RIGHT_BRACE { std::cout << "block found" << std::endl; }
  ;


declaration_list:
  /* nothing */
  | declaration SEMICOLON declaration_list
  ;


arg_list:
  /* nothing */
  | declaration COLON declaration
  ;

declaration:
  CONSTANT VARIABLE { std::cout << "declaration found" << std::endl; }


throws:
  /* nothing */
  | KW_THROWS throw_list
  ;

throw_list:
  CONSTANT
  | CONSTANT COLON throw_list
  ;

%%
