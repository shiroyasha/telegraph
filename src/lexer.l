%{

#include <iostream>
#include "token_types.hpp"

%}

%option header-file="src/lexer.yy.h"
%option noyywrap

NUMBER [0-9][0-9]*

%%

"(" { std::cout << "left parenthesis: " << yytext << std::endl; return LEFT_PARENTHESIS; }
")" { std::cout << "right parenthesis: " << yytext << std::endl; return RIGHT_PARENTHESIS;}
"{" { std::cout << "left brace: " << yytext << std::endl; return LEFT_BRACE; }
"}" { std::cout << "right brace: " << yytext << std::endl; return RIGHT_BRACE; }

";" { std::cout << "semicolon : " << yytext << std::endl; return SEMICOLON; }

"version" { std::cout << "keyword: " << yytext << std::endl; return KW_VERSION; }
"struct"  { std::cout << "keyword: " << yytext << std::endl; return KW_STRUCT; }
"enum"    { std::cout << "keyword: " << yytext << std::endl; return KW_ENUM; }
"event"   { std::cout << "keyword: " << yytext << std::endl; return KW_ERROR; }
"error"   { std::cout << "keyword: " << yytext << std::endl; return KW_ERROR; }
"throws"  { std::cout << "keyword: " << yytext << std::endl; return KW_THROWS; }

{NUMBER}"."{NUMBER}"."{NUMBER} { std::cout << "version number: " << yytext << std::endl; return VERSION_NUMBER; }

[a-z][A-Za-z0-9_]* { std::cout << "variable: " << yytext << std::endl; return VARIABLE; }
[A-Z][A-Za-z0-9_]* { std::cout << "constant: " << yytext << std::endl; return CONSTANT; }

\n ;
[ \t] ;
. ;

%%
