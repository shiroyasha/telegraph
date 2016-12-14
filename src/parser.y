%{
#include <iostream>
/* #include "lexer.hpp" */
#include "ast/ast.hpp"

extern int yylex();

void yyerror(ast::Telegraph* r, const char* s) {
  std::cout << "EEK, parse error!  Message: " << s << std::endl;
  exit(-1);
}

%}

%parse-param {ast::Telegraph* result}

%union {
  ast::Argument* argument;
  ast::ArgumentList* argument_list;
  ast::Array* array;
  ast::Block* block;
  ast::Declaration* declaration;
  ast::DeclarationList* declaration_list;
  ast::Enum* enumeration;
  ast::Error* error;
  ast::Event* event;
  ast::Function* function;
  ast::Identifier* identifier;
  ast::IdentifierList* identifier_list;
  ast::Node* node;
  ast::Struct* structure;
  ast::ThrowList* throw_list;
  ast::Type* type;
  ast::Version* version;
  ast::VersionNumber* version_number;
}

%token KW_VERSION
%token KW_STRUCT
%token KW_ENUM
%token KW_EVENT
%token KW_PUBLISHES
%token KW_ERROR
%token KW_THROWS

%token <version_number> VERSION_NUMBER
%token <identifier> IDENTIFIER

%type <version> version
%type <structure> struct
%type <enumeration> enum
%type <error> error_def
%type <event> event
%type <function> function
%type <block> block
%type <declaration_list> dec_list
%type <declaration> declaration
%type <argument_list> arg_list
%type <argument> arg
%type <type> type
%type <throw_list> throws
%type <identifier_list> id_list

%start telegraph

%%

telegraph   :
            /* empty line */
            | telegraph version    { result->set_version($2);  }
            | telegraph struct     { result->add_struct($2);   }
            | telegraph error_def  { result->add_error($2);    }
            | telegraph enum       { result->add_enum($2);     }
            | telegraph event      { result->add_event($2);    }
            | telegraph function   { result->add_function($2); }
            ;

version     : KW_VERSION VERSION_NUMBER { $$ = new ast::Version($2); }
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

dec_list    :
            /* nothing */           { $$ = new ast::DeclarationList(); }
            | dec_list declaration  { $1->add($2); $$ = $1; }
            ;

declaration : type IDENTIFIER ';' { $$ = new ast::Declaration($2, $1); }
            ;

arg_list    :
            /* nothing */       { $$ = new ast::ArgumentList(); }
            | arg               { $$ = new ast::ArgumentList($1); }
            | arg_list ',' arg  { $1->add($3); $$ = $1; }
            ;

arg         : type IDENTIFIER { $$ = new ast::Argument($2, $1); }
            ;


type        : IDENTIFIER          { $$ = new ast::Type($1); }
            | '[' IDENTIFIER ']'  { $$ = new ast::Array($2); }
            ;

throws      :
            /* nothing */         { $$ = new ast::ThrowList(); }
            | KW_THROWS id_list   { $$ = new ast::ThrowList($2); }
            ;

id_list     : IDENTIFIER             { $$ = new ast::IdentifierList($1); }
            | id_list ',' IDENTIFIER { $1->add($3); $$ = $1; }
            ;

%%
