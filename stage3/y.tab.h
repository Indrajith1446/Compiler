/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    PLUS = 259,
    END = 260,
    MINUS = 261,
    DIV = 262,
    MUL = 263,
    ID = 264,
    BEGN = 265,
    READ = 266,
    WRITE = 267,
    EQUAL = 268,
    SEMCL = 269,
    LP = 270,
    RP = 271,
    IF = 272,
    THEN = 273,
    ENDIF = 274,
    BREAK = 275,
    CONTINUE = 276,
    ELSE = 277,
    WHILE = 278,
    DO = 279,
    ENDWHILE = 280,
    LT = 281,
    GT = 282,
    NOT = 283
  };
#endif
/* Tokens.  */
#define NUM 258
#define PLUS 259
#define END 260
#define MINUS 261
#define DIV 262
#define MUL 263
#define ID 264
#define BEGN 265
#define READ 266
#define WRITE 267
#define EQUAL 268
#define SEMCL 269
#define LP 270
#define RP 271
#define IF 272
#define THEN 273
#define ENDIF 274
#define BREAK 275
#define CONTINUE 276
#define ELSE 277
#define WHILE 278
#define DO 279
#define ENDWHILE 280
#define LT 281
#define GT 282
#define NOT 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "t4.y" /* yacc.c:1909  */

struct tnode * tn;

#line 114 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
