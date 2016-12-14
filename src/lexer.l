%{
#include <iostream>

#include "ast/ast.hpp"
#include "parser.hpp"
%}

%option header-file="lexer.hpp"
%option noyywrap

NUMBER [0-9][0-9]*

%%

"version"   { return KW_VERSION; }
"struct"    { return KW_STRUCT; }
"enum"      { return KW_ENUM; }
"event"     { return KW_EVENT; }
"publishes" { return KW_PUBLISHES; }
"error"     { return KW_ERROR; }
"throws"    { return KW_THROWS; }

{NUMBER}"."{NUMBER}"."{NUMBER} {
  yylval.version_number = new ast::VersionNumber(yytext);
  return VERSION_NUMBER;
}

[a-zA-Z_][A-Za-z0-9_]* {
  yylval.identifier = new ast::Identifier(yytext);
  return IDENTIFIER;
}

\n ;
[ \t] ;

. { return yytext[0]; };

%%
