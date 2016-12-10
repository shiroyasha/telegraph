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

input       : /* empty line */ { $$ = new ast::Telegraph(); }
            | input statement  { $$ = $1.add($2); std::cout << $$.toString() << std::endl; }
            ;

statement   : version
            | struct
            | error_def
            | enum
            | event
            | function
            ;

version     : KW_VERSION VERSION_NUMBER { $$ = new ast::Version($1) }
            ;

struct      : KW_STRUCT IDENTIFIER block { $$ = new ast::Struct($2, $3); }
            ;

enum        : KW_ENUM IDENTIFIER '{' id_list '}' { $$ = new ast::Enum($2, $4); }
            ;

error_def   : KW_ERROR IDENTIFIER block { $$ = new ast::Error($2, $3); }

event       : KW_EVENT IDENTIFIER KW_PUBLISHES type ';'  { $$ = new ast::Event($2, $4); }
            | KW_EVENT IDENTIFIER KW_PUBLISHES block ';' { $$ = new ast::Event($2, $4); }

function    : type IDENTIFIER '(' arg_list ')' throws ';' { $$ = new ast::Function($2, $1, $4, $6); }
            ;

block       : '{' dec_list '}' { $$ = new ast::Block($2); }
            ;

dec_list    : /* nothing */         { $$ = new ast::DeclarationList(); }
            | dec_list declaration  { $$ = $1.add($2); }
            ;

declaration : type IDENTIFIER ';' { $$ = new ast::Declaration($1, $2); }
            ;

arg_list    : /* nothing */     { $$ = new ast::ArgumentList(); }
            | arg               { $$ = new ast::ArgumentList($1); }
            | arg_list ',' arg  { $$ = $1.add($3); }
            ;

arg         : type IDENTIFIER { $$ = new ast::Argument($2, $1); }
            ;


type        : IDENTIFIER          { $$ = new ast::Type($1); }
            | '[' IDENTIFIER ']'  { $$ = new ast::Array($2); }
            ;

throws      : /* nothing */       { $$ = new ast::ThrowList(); }
            | KW_THROWS id_list   { $$ = new ast::ThrowList($2); }
            ;

id_list     : IDENTIFIER             { $$ = new ast::IdentifierList($1); }
            | id_list ',' IDENTIFIER { $$ = $1.add($3); }
            ;

%%
