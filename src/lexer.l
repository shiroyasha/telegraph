%{

#include <iostream>

/* #include "token_types.hpp" */

#include "parser.tab.h"
%}

%option header-file="src/lexer.yy.h"
%option noyywrap

NUMBER [0-9][0-9]*

%%

"(" { return LEFT_PARENTHESIS; }
")" { return RIGHT_PARENTHESIS;}
"{" { return LEFT_BRACE; }
"}" { return RIGHT_BRACE; }
";" { return SEMICOLON; }

"version"   { return KW_VERSION; }
"struct"    { return KW_STRUCT; }
"enum"      { return KW_ENUM; }
"event"     { return KW_EVENT; }
"publishes" { return KW_PUBLISHES; }
"error"     { return KW_ERROR; }
"throws"    { return KW_THROWS; }

{NUMBER}"."{NUMBER}"."{NUMBER} { return VERSION_NUMBER; }
[a-z][A-Za-z0-9_]*             { return VARIABLE; }
[A-Z][A-Za-z0-9_]*             { return CONSTANT; }

\n ;
[ \t] ;
. ;

%%
