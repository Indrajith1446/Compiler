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
    COMMA = 277,
    DECL = 278,
    ENDDECL = 279,
    INT = 280,
    STR = 281,
    ELSE = 282,
    WHILE = 283,
    DO = 284,
    ENDWHILE = 285,
    LT = 286,
    GT = 287,
    NOT = 288,
    VAR = 289,
    NUP = 290,
    LID = 291,
    LSB = 292,
    RSB = 293,
    STRING = 294,
    MAIN = 295,
    LCB = 296,
    RCB = 297,
    PM = 298,
    RETURN = 299
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
#define COMMA 277
#define DECL 278
#define ENDDECL 279
#define INT 280
#define STR 281
#define ELSE 282
#define WHILE 283
#define DO 284
#define ENDWHILE 285
#define LT 286
#define GT 287
#define NOT 288
#define VAR 289
#define NUP 290
#define LID 291
#define LSB 292
#define RSB 293
#define STRING 294
#define MAIN 295
#define LCB 296
#define RCB 297
#define PM 298
#define RETURN 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "t3.y" /* yacc.c:1909  */

struct tnode * tn;
struct Gsymbol * gn;
struct Lsymbol * ln;
struct Paramstruct * pn;
int i;

#line 150 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
