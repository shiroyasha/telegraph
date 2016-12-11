%{
#include <iostream>
#include "lexer.yy.h"
#include "ast/ast.hpp"

void yyerror(const char *s) {
  std::cout << "EEK, parse error!  Message: " << s << std::endl;
  exit(-1);
}

#define YYSTYPE ast::Node*

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

input       :
            /* empty line */ { $$ = new ast::Telegraph(); }
            | input statement  { ((ast::Telegraph*)$1)->add($2); $$ = $1; std::cout << $$->toString() << std::endl; }
            ;

statement   : version
            | struct
            | error_def
            | enum
            | event
            | function
            ;

version     : KW_VERSION VERSION_NUMBER { $$ = new ast::Version((ast::VersionNumber*)$2); }
            ;

struct      : KW_STRUCT IDENTIFIER block { $$ = new ast::Struct((ast::Identifier*)$2, (ast::Block*)$3); }
            ;

enum        : KW_ENUM IDENTIFIER '{' id_list '}' { $$ = new ast::Enum((ast::Identifier*)$2, (ast::IdentifierList*)$4); }
            ;

error_def   : KW_ERROR IDENTIFIER block { $$ = new ast::Error((ast::Identifier*)$2, (ast::Block*)$3); }

event       : KW_EVENT IDENTIFIER KW_PUBLISHES type ';'  { $$ = new ast::Event((ast::Identifier*)$2, (ast::Type*)$4); }
            | KW_EVENT IDENTIFIER KW_PUBLISHES block ';' { $$ = new ast::Event((ast::Identifier*)$2, (ast::Block*)$4); }

function    : type IDENTIFIER '(' arg_list ')' throws ';' {
                $$ = new ast::Function((ast::Identifier*)$2,
                                       (ast::Type*)$1,
                                       (ast::ArgumentList*)$4,
                                       (ast::ThrowList*)$6);
              }
            ;

block       : '{' dec_list '}' { $$ = new ast::Block((ast::DeclarationList*)$2); }
            ;

dec_list    :
            /* nothing */           { $$ = new ast::DeclarationList(); }
            | dec_list declaration  { ((ast::DeclarationList*)$1)->add((ast::Declaration*)$2); $$ = $1; }
            ;

declaration : type IDENTIFIER ';' { $$ = new ast::Declaration((ast::Identifier*)$2, (ast::Type*)$1); }
            ;

arg_list    :
            /* nothing */       { $$ = new ast::ArgumentList(); }
            | arg               { $$ = new ast::ArgumentList((ast::Argument*)$1); }
            | arg_list ',' arg  { ((ast::ArgumentList*)$1)->add((ast::Argument*)$3); $$ = $1; }
            ;

arg         : type IDENTIFIER { $$ = new ast::Argument((ast::Identifier*)$2, (ast::Type*)$1); }
            ;


type        : IDENTIFIER          { $$ = new ast::Type((ast::Identifier*)$1); }
            | '[' IDENTIFIER ']'  { $$ = new ast::Array((ast::Identifier*)$2); }
            ;

throws      :
            /* nothing */         { $$ = new ast::ThrowList(); }
            | KW_THROWS id_list   { $$ = new ast::ThrowList((ast::IdentifierList*)$2); }
            ;

id_list     : IDENTIFIER             { $$ = new ast::IdentifierList((ast::Identifier*)$1); }
            | id_list ',' IDENTIFIER { ((ast::IdentifierList*)$1)->add((ast::Identifier*)$3); $$ = $1; }
            ;

%%
