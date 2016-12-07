%{

#include <iostream>

%}

%option header-file="src/lexer.yy.h"
%option noyywrap

NUMBER [0-9][0-9]*

%%

"("      { std::cout << "left parenthesis: " << yytext << std::endl; }
")"      { std::cout << "right parenthesis: " << yytext << std::endl; }

"{"      { std::cout << "left brace: " << yytext << std::endl; }
"}"      { std::cout << "right brace: " << yytext << std::endl; }
";"      { std::cout << "semicolon : " << yytext << std::endl; }

"version" { std::cout << "keyword: " << yytext << std::endl; }
"struct"  { std::cout << "keyword: " << yytext << std::endl; }
"enum"    { std::cout << "keyword: " << yytext << std::endl; }
"event"   { std::cout << "keyword: " << yytext << std::endl; }
"error"   { std::cout << "keyword: " << yytext << std::endl; }
"throws"  { std::cout << "keyword: " << yytext << std::endl; }

{NUMBER}"."{NUMBER}"."{NUMBER} { std::cout << "version number: " << yytext << std::endl; }

[a-z][A-Za-z0-9_]* { std::cout << "variable: " << yytext << std::endl; }
[A-Z][A-Za-z0-9_]* { std::cout << "constant: " << yytext << std::endl; }

\n ;
[ \t] ;
. ;

%%
