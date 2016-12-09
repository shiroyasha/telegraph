%{
#include <iostream>
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
%token IDENTIFIER

%start input

%%

input       : /* empty line */
            | input statement { $$ = 1; }
            ;

statement   : version
            | struct
            | error_def
            | enum
            | event
            | function
            ;

version     : KW_VERSION VERSION_NUMBER { std::cout << "version found" << std::endl; } ;

struct      : KW_STRUCT IDENTIFIER block { std::cout << "struct found" << std::endl; } ;

enum        : KW_ENUM IDENTIFIER '{' id_list '}' { std::cout << "enum found" << std::endl; } ;

error_def   : KW_ERROR IDENTIFIER block { std::cout << "error found" << std::endl; } ;

event       : KW_EVENT IDENTIFIER KW_PUBLISHES type ';' { std::cout << "event found" << std::endl; }
            | KW_EVENT IDENTIFIER KW_PUBLISHES block ';' { std::cout << "event found" << std::endl; } ;


function    : type IDENTIFIER '(' arg_list ')' throws ';' { std::cout << "function found" << std::endl; } ;


block       : '{' dec_list '}' { std::cout << "block found" << std::endl; } ;


dec_list    : /* nothing */
            | dec_list declaration
            ;

declaration : type IDENTIFIER ';' { std::cout << "declaration found" << std::endl; }
            ;

arg_list    : /* nothing */
            | arg
            | arg_list ',' arg
            ;

arg         : type IDENTIFIER { std::cout << "argument found" << std::endl; }
            ;


type        : IDENTIFIER
            | '[' IDENTIFIER ']'
            ;

throws      : /* nothing */
            | KW_THROWS id_list
            ;

id_list     : IDENTIFIER
            | id_list ',' IDENTIFIER
            ;

%%
