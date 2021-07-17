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
    MOD = 264,
    ID = 265,
    BEGN = 266,
    READ = 267,
    WRITE = 268,
    EQUAL = 269,
    SEMCL = 270,
    LP = 271,
    RP = 272,
    IF = 273,
    THEN = 274,
    ENDIF = 275,
    BREAK = 276,
    CONTINUE = 277,
    COMMA = 278,
    DECL = 279,
    ENDDECL = 280,
    INT = 281,
    STR = 282,
    ELSE = 283,
    WHILE = 284,
    DO = 285,
    ENDWHILE = 286,
    LT = 287,
    GT = 288,
    NOT = 289,
    VAR = 290,
    NUP = 291,
    LID = 292,
    LSB = 293,
    RSB = 294,
    STRING = 295,
    MAIN = 296,
    LCB = 297,
    RCB = 298,
    PM = 299,
    RETURN = 300,
    TYPE = 301,
    ENDTYPE = 302,
    DOT = 303,
    ALLOC = 304,
    FREE = 305,
    INIT = 306,
    NUL = 307,
    CLASS = 308,
    ENDCLASS = 309,
    EXTENDS = 310,
    NEW = 311,
    SELF = 312,
    DELETE = 313
  };
#endif
/* Tokens.  */
#define NUM 258
#define PLUS 259
#define END 260
#define MINUS 261
#define DIV 262
#define MUL 263
#define MOD 264
#define ID 265
#define BEGN 266
#define READ 267
#define WRITE 268
#define EQUAL 269
#define SEMCL 270
#define LP 271
#define RP 272
#define IF 273
#define THEN 274
#define ENDIF 275
#define BREAK 276
#define CONTINUE 277
#define COMMA 278
#define DECL 279
#define ENDDECL 280
#define INT 281
#define STR 282
#define ELSE 283
#define WHILE 284
#define DO 285
#define ENDWHILE 286
#define LT 287
#define GT 288
#define NOT 289
#define VAR 290
#define NUP 291
#define LID 292
#define LSB 293
#define RSB 294
#define STRING 295
#define MAIN 296
#define LCB 297
#define RCB 298
#define PM 299
#define RETURN 300
#define TYPE 301
#define ENDTYPE 302
#define DOT 303
#define ALLOC 304
#define FREE 305
#define INIT 306
#define NUL 307
#define CLASS 308
#define ENDCLASS 309
#define EXTENDS 310
#define NEW 311
#define SELF 312
#define DELETE 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "t1.y" /* yacc.c:1909  */

struct tnode * tn;
struct Gsymbol * gn;
struct Lsymbol * ln;
struct Paramstruct * pn;
struct Typetable * tyn;
struct Fieldlist * fn;
char * id;
int i;

#line 181 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
