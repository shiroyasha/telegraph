/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_PARSER_TAB_H_INCLUDED
# define YY_YY_SRC_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LEFT_PARENTHESIS = 258,
    RIGHT_PARENTHESIS = 259,
    LEFT_BRACE = 260,
    RIGHT_BRACE = 261,
    SEMICOLON = 262,
    KW_VERSION = 263,
    KW_STRUCT = 264,
    KW_ENUM = 265,
    KW_EVENT = 266,
    KW_PUBLISHES = 267,
    KW_ERROR = 268,
    KW_THROWS = 269,
    VERSION_NUMBER = 270,
    VARIABLE = 271,
    CONSTANT = 272
  };
#endif
/* Tokens.  */
#define LEFT_PARENTHESIS 258
#define RIGHT_PARENTHESIS 259
#define LEFT_BRACE 260
#define RIGHT_BRACE 261
#define SEMICOLON 262
#define KW_VERSION 263
#define KW_STRUCT 264
#define KW_ENUM 265
#define KW_EVENT 266
#define KW_PUBLISHES 267
#define KW_ERROR 268
#define KW_THROWS 269
#define VERSION_NUMBER 270
#define VARIABLE 271
#define CONSTANT 272

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_H_INCLUDED  */
