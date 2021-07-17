/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "prog.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "prog.h"
#include "prog.c"
int yylex();
int yywrap();
int classflag=1;
struct regpool * Reg;
struct Gsymbol * Ghold=NULL;
FILE *outputfile;
int printval,findex=0,size=0,deflag=0;
int loopflag[3];
int yyerror(char const *s);



#line 85 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 22 "prog.y" /* yacc.c:355  */

struct tnode * tn;
struct Gsymbol * gn;
struct Lsymbol * ln;
struct Paramstruct * pn;
struct Typetable * tyn;
struct Fieldlist * fn;
char * id;
int i;

#line 252 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 269 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   421

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    56,    58,    60,    61,    63,    70,
      71,    73,    75,    76,    77,    87,    88,    90,    91,    93,
      94,    95,    97,    98,   100,   101,   103,   105,   106,   108,
     110,   111,   115,   120,   122,   124,   125,   127,   134,   135,
     137,   138,   139,   143,   144,   148,   168,   212,   213,   214,
     216,   224,   225,   226,   228,   229,   231,   233,   234,   236,
     237,   238,   242,   243,   245,   246,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   261,   263,
     265,   276,   278,   280,   282,   284,   286,   288,   289,   291,
     300,   302,   312,   314,   330,   341,   346,   367,   371,   381,
     392,   410,   424,   425,   426,   427,   428,   429,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   454
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "PLUS", "END", "MINUS", "DIV",
  "MUL", "MOD", "ID", "BEGN", "READ", "WRITE", "EQUAL", "SEMCL", "LP",
  "RP", "IF", "THEN", "ENDIF", "BREAK", "CONTINUE", "COMMA", "DECL",
  "ENDDECL", "INT", "STR", "ELSE", "WHILE", "DO", "ENDWHILE", "LT", "GT",
  "NOT", "VAR", "NUP", "LID", "LSB", "RSB", "STRING", "MAIN", "LCB", "RCB",
  "PM", "RETURN", "TYPE", "ENDTYPE", "DOT", "ALLOC", "FREE", "INIT", "NUL",
  "CLASS", "ENDCLASS", "EXTENDS", "NEW", "SELF", "DELETE", "$accept",
  "Program", "TypeDefBlock", "TypeDefList", "TypeDef", "FieldDeclList",
  "FieldDecl", "TypeName", "ClassDefBlock", "ClassDefList", "ClassDef",
  "Cname", "FieldLists", "Fld", "MethodDecl", "MDecl", "MethodDefns",
  "GDeclBlock", "GDeclList", "GDecl", "GidList", "GID", "FdefBlock",
  "MainBlock", "Fdef", "ParamList", "Param", "LdeclBlock", "LDecList",
  "LDecl", "IdList", "ArgList", "Body", "Slist", "Stmt", "InputStmt",
  "OutputStmt", "AsgStmt", "IfStmt", "WhileStmt", "BreakStmt",
  "ContinueStmt", "ReturnStmt", "AllocStmt", "FreeStmt", "NewStmt",
  "DeleteStmt", "FIELD", "FieldFuntion", "E", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF -231

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,    20,     9,     3,    11,    -5,  -231,  -231,    33,    60,
      38,  -231,  -231,    31,    -2,  -231,    69,    66,    38,  -231,
    -231,  -231,    56,  -231,    92,   124,  -231,  -231,   113,  -231,
     148,    87,  -231,     5,    38,  -231,  -231,  -231,  -231,   145,
    -231,   155,    21,   105,  -231,  -231,  -231,   162,   168,  -231,
    -231,  -231,   186,    52,  -231,    63,  -231,    38,   181,  -231,
     148,    38,   180,   160,    38,  -231,    90,   211,    38,  -231,
     215,   115,  -231,   201,  -231,   144,   196,  -231,    38,   231,
      96,  -231,    38,   227,   146,  -231,  -231,    38,  -231,   205,
     234,   176,  -231,  -231,   159,  -231,  -231,   234,   100,   240,
     246,  -231,   240,  -231,   249,   223,  -231,   169,   220,  -231,
     221,  -231,   165,  -231,  -231,  -231,    -3,   261,   264,   267,
     270,   275,   276,    93,   277,   243,   281,   210,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,     7,  -231,  -231,  -231,   290,    23,   293,   161,   161,
     161,  -231,  -231,   161,  -231,    -4,  -231,   161,  -231,   289,
    -231,   258,   262,  -231,   357,    -7,   299,    -6,  -231,  -231,
      91,   302,  -231,   297,   298,   367,  -231,   331,   345,   301,
     313,   308,   161,   316,   351,   311,   319,   320,   161,   161,
     161,   161,   161,  -231,   -10,    -1,  -231,   284,     6,   317,
     318,   377,  -231,   324,   332,  -231,   335,   341,   348,   355,
     143,   152,   356,   347,   188,   387,   362,  -231,  -231,   363,
     364,   199,   199,  -231,  -231,  -231,   372,   373,   374,   380,
     388,  -231,   375,   382,  -231,  -231,   286,   161,   161,   387,
     161,   387,   161,   286,  -231,   161,   161,   161,   161,  -231,
    -231,  -231,   385,   384,  -231,   389,   224,   387,   387,   387,
     387,   244,   387,   193,   207,   212,  -231,   390,  -231,   391,
     286,   392,  -231,  -231,  -231,  -231,  -231,   266,  -231,   393,
    -231
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    16,     0,     0,     7,     1,     0,    34,
       0,     4,     6,    22,     0,    18,     0,     0,     0,    14,
      12,    13,     0,    10,     0,     0,    15,    17,     0,    33,
       0,     0,    36,     0,     0,     3,    44,     8,     9,     0,
      23,     0,    42,     0,    39,    32,    35,     0,     0,     2,
      43,    11,     0,     0,    25,     0,    28,    49,     0,    37,
       0,    49,     0,     0,     0,    24,     0,     0,     0,    27,
       0,     0,    48,     0,    38,     0,     0,    26,    49,     0,
       0,    31,     0,     0,     0,    50,    40,     0,    41,     0,
      53,     0,    21,    30,     0,    20,    47,    53,     0,     0,
       0,    19,     0,    52,     0,     0,    55,     0,     0,    29,
       0,    58,     0,    51,    54,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,     0,    45,    46,    56,     0,     0,     0,     0,     0,
       0,    85,    86,     0,   114,   120,    88,     0,   115,     0,
     119,     0,   116,   117,     0,     0,     0,     0,    62,    64,
       0,     0,    57,     0,     0,     0,    96,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,    98,     0,     0,     0,
       0,     0,    97,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    96,   113,   118,    98,
      97,   108,   110,   111,   109,   112,     0,     0,     0,     0,
       0,    81,     0,     0,    78,    79,     0,     0,     0,   102,
       0,   103,     0,     0,   121,     0,    61,    61,    61,    91,
      92,    95,     0,     0,    89,     0,     0,   107,   104,   105,
     106,     0,    59,     0,     0,     0,    90,     0,    93,     0,
       0,     0,   100,    99,   101,    94,    83,     0,    84,     0,
      82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,  -231,   397,  -231,   381,     0,  -231,  -231,
     395,  -231,  -231,   358,   359,    86,    36,  -231,  -231,   379,
    -231,   353,  -231,   383,     1,   -37,   327,   321,  -231,   310,
    -231,    24,   314,  -230,  -126,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -107,  -231,   268,
    -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    22,    23,    79,     9,    14,
      15,    16,    53,    54,    55,    56,    80,    18,    31,    32,
      43,    44,    34,    35,    81,    71,    72,    99,   105,   106,
     112,   214,   108,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   162,   163,   179,
     215
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     141,   169,   164,   194,   197,     4,   256,   226,    13,     7,
      24,   146,   182,   261,     1,    47,   227,    30,    33,    36,
     141,   170,    24,   228,    75,   175,   154,   177,   178,   180,
       4,    30,   180,   155,    33,    50,   184,    57,   147,   157,
     277,    91,    11,    13,   183,   147,    48,   171,    19,   201,
     125,   125,    26,    10,   171,   171,     8,    70,   195,    58,
     198,    70,    52,   158,    20,    21,    19,   221,   222,   223,
     224,   225,   173,    67,   159,   160,    19,    64,    70,   174,
     161,    93,    20,    21,    17,    93,    25,    70,    68,   239,
     241,    29,    20,    21,   154,    93,   154,    19,   104,    37,
      67,   155,    39,   155,    84,   104,    19,   157,   156,   157,
      19,    28,    45,    20,    21,    82,   257,   258,    94,   259,
      59,   260,    20,    21,   262,   103,    20,    21,    60,   141,
     169,   158,    86,   158,    40,   169,   141,    41,    87,    92,
     199,    69,   159,   160,   159,   160,   154,   200,   161,   141,
     161,   169,    69,   155,   141,   154,    19,   238,    42,   157,
      51,    89,   155,   141,   154,    52,   240,    87,   157,    19,
     141,   155,    20,    21,   115,    77,    78,   157,    61,   116,
     144,   117,   118,   158,    62,    20,    21,   119,   145,    95,
     120,   121,   158,   100,   159,   160,    63,    76,   122,    87,
     161,   158,   101,   159,   160,   244,   190,   191,   192,   161,
     272,   245,   159,   160,   123,   168,   245,    73,   161,   124,
     116,    83,   117,   118,   273,    85,   125,   126,   119,   274,
     245,   120,   121,    19,   116,   245,   117,   118,    90,   122,
      88,    47,   119,    78,   269,   120,   121,    97,   113,    20,
      21,   107,   270,   122,   116,   123,   117,   118,    98,   111,
     124,   109,   119,   142,   143,   120,   121,   125,   126,   123,
     263,   264,   265,   122,   124,   271,   116,   148,   117,   118,
     149,   125,   126,   150,   119,   151,   279,   120,   121,   123,
     152,   166,   153,   165,   124,   122,   116,   167,   117,   118,
     172,   125,   126,   176,   119,   185,   186,   120,   121,   196,
     187,   123,   202,   203,   204,   122,   124,   188,   208,   189,
     190,   191,   192,   125,   126,   213,   216,   209,   218,   219,
     220,   123,   147,   229,   230,   188,   124,   189,   190,   191,
     192,   232,   233,   125,   126,   210,   211,   212,   206,   188,
     234,   189,   190,   191,   192,   188,   235,   189,   190,   191,
     192,   188,   207,   189,   190,   191,   192,   236,   217,   237,
     242,   188,   193,   189,   190,   191,   192,   243,   246,   247,
     248,   188,   205,   189,   190,   191,   192,   249,   250,   251,
     254,   188,   231,   189,   190,   191,   192,   252,   253,   255,
     266,   267,    12,    38,   268,   275,   276,   278,   280,    27,
      46,    65,    66,    74,    96,   114,   110,    49,   102,     0,
       0,   181
};

static const yytype_int16 yycheck[] =
{
     107,   127,   123,    10,    10,    10,   236,    17,    10,     0,
      10,    14,    16,   243,    46,    10,    17,    17,    18,    18,
     127,    14,    22,    17,    61,   146,     3,   148,   149,   150,
      10,    31,   153,    10,    34,    34,   157,    16,    48,    16,
     270,    78,    47,    10,    48,    48,    41,    48,    10,   170,
      57,    57,    54,    42,    48,    48,    53,    57,   165,    38,
     167,    61,    10,    40,    26,    27,    10,   188,   189,   190,
     191,   192,    49,    10,    51,    52,    10,    25,    78,    56,
      57,    80,    26,    27,    24,    84,    55,    87,    25,   210,
     211,    25,    26,    27,     3,    94,     3,    10,    98,    43,
      10,    10,    10,    10,    68,   105,    10,    16,    15,    16,
      10,    42,    25,    26,    27,    25,   237,   238,    82,   240,
      15,   242,    26,    27,   245,    25,    26,    27,    23,   236,
     256,    40,    17,    40,    10,   261,   243,    24,    23,    43,
      49,    55,    51,    52,    51,    52,     3,    56,    57,   256,
      57,   277,    66,    10,   261,     3,    10,    14,    10,    16,
      15,    17,    10,   270,     3,    10,    14,    23,    16,    10,
     277,    10,    26,    27,     5,    15,    16,    16,    16,    10,
      15,    12,    13,    40,    16,    26,    27,    18,    23,    43,
      21,    22,    40,    17,    51,    52,    10,    17,    29,    23,
      57,    40,    43,    51,    52,    17,     7,     8,     9,    57,
      17,    23,    51,    52,    45,     5,    23,    36,    57,    50,
      10,    10,    12,    13,    17,    10,    57,    58,    18,    17,
      23,    21,    22,    10,    10,    23,    12,    13,    42,    29,
      39,    10,    18,    16,    20,    21,    22,    42,    25,    26,
      27,    11,    28,    29,    10,    45,    12,    13,    24,    10,
      50,    15,    18,    43,    43,    21,    22,    57,    58,    45,
     246,   247,   248,    29,    50,    31,    10,    16,    12,    13,
      16,    57,    58,    16,    18,    15,    20,    21,    22,    45,
      15,    48,    16,    16,    50,    29,    10,    16,    12,    13,
      10,    57,    58,    10,    18,    16,    48,    21,    22,    10,
      48,    45,    10,    16,    16,    29,    50,     4,    17,     6,
       7,     8,     9,    57,    58,    17,    10,    14,    17,    10,
      10,    45,    48,    16,    16,     4,    50,     6,     7,     8,
       9,    17,    10,    57,    58,    32,    33,    34,    17,     4,
      15,     6,     7,     8,     9,     4,    15,     6,     7,     8,
       9,     4,    17,     6,     7,     8,     9,    19,    17,    14,
      14,     4,    15,     6,     7,     8,     9,    30,    16,    16,
      16,     4,    15,     6,     7,     8,     9,    15,    15,    15,
      15,     4,    15,     6,     7,     8,     9,    17,    10,    17,
      15,    17,     5,    22,    15,    15,    15,    15,    15,    14,
      31,    53,    53,    60,    87,   105,   102,    34,    97,    -1,
      -1,   153
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    60,    61,    10,    62,    63,     0,    53,    67,
      42,    47,    63,    10,    68,    69,    70,    24,    76,    10,
      26,    27,    64,    65,    66,    55,    54,    69,    42,    25,
      66,    77,    78,    66,    81,    82,    83,    43,    65,    10,
      10,    24,    10,    79,    80,    25,    78,    10,    41,    82,
      83,    15,    10,    71,    72,    73,    74,    16,    38,    15,
      23,    16,    16,    10,    25,    72,    73,    10,    25,    74,
      66,    84,    85,    36,    80,    84,    17,    15,    16,    66,
      75,    83,    25,    10,    75,    10,    17,    23,    39,    17,
      42,    84,    43,    83,    75,    43,    85,    42,    24,    86,
      17,    43,    86,    25,    66,    87,    88,    11,    91,    15,
      91,    10,    89,    25,    88,     5,    10,    12,    13,    18,
      21,    22,    29,    45,    50,    57,    58,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    43,    43,    15,    23,    14,    48,    16,    16,
      16,    15,    15,    16,     3,    10,    15,    16,    40,    51,
      52,    57,   106,   107,   109,    16,    48,    16,     5,    93,
      14,    48,    10,    49,    56,   109,    10,   109,   109,   108,
     109,   108,    16,    48,   109,    16,    48,    48,     4,     6,
       7,     8,     9,    15,    10,   106,    10,    10,   106,    49,
      56,   109,    10,    16,    16,    15,    17,    17,    17,    14,
      32,    33,    34,    17,    90,   109,    10,    17,    17,    10,
      10,   109,   109,   109,   109,   109,    17,    17,    17,    16,
      16,    15,    17,    10,    15,    15,    19,    14,    14,   109,
      14,   109,    14,    30,    17,    23,    16,    16,    16,    15,
      15,    15,    17,    10,    15,    17,    92,   109,   109,   109,
     109,    92,   109,    90,    90,    90,    15,    17,    15,    20,
      28,    31,    17,    17,    17,    15,    15,    92,    15,    20,
      15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    63,    64,
      64,    65,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    70,    70,    71,    71,    72,    73,    73,    74,
      75,    75,    76,    76,    76,    77,    77,    78,    79,    79,
      80,    80,    80,    81,    81,    82,    83,    84,    84,    84,
      85,    86,    86,    86,    87,    87,    88,    89,    89,    90,
      90,    90,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    95,
      96,    96,    97,    97,    98,    99,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     0,     2,     1,     4,     2,
       1,     3,     1,     1,     1,     3,     0,     2,     1,     8,
       7,     7,     1,     3,     2,     1,     3,     2,     1,     6,
       2,     1,     3,     2,     0,     2,     1,     3,     3,     1,
       4,     4,     1,     2,     1,     8,     9,     3,     1,     0,
       2,     3,     2,     0,     2,     1,     3,     3,     1,     3,
       1,     0,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       4,     4,    10,     8,     8,     2,     2,     3,     2,     6,
       6,     5,     5,     7,     7,     5,     3,     3,     3,     6,
       6,     6,     3,     3,     4,     4,     4,     4,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 51 "prog.y" /* yacc.c:1646  */
    {printf(" y1 ");}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "prog.y" /* yacc.c:1646  */
    {printf(" y2 ");}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "prog.y" /* yacc.c:1646  */
    {printf(" n1 ");printtype();
                                          fprintf(outputfile,"CALL L0\nINT 10\n");}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "prog.y" /* yacc.c:1646  */
    {printf(" Typ ");fprintf(outputfile,"CALL L0\nINT 10\n");}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "prog.y" /* yacc.c:1646  */
    {printf(" n2 ");}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "prog.y" /* yacc.c:1646  */
    {printf(" n3 ");}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "prog.y" /* yacc.c:1646  */
    {printf(" n4 ");
                              struct Typetable *temp;
                              temp=gettype((yyvsp[-3].gn)->name);
                              temp->fields=(yyvsp[-1].fn);
                              temp->size=findex;
                              Fieldnode=NULL;findex=0;}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 70 "prog.y" /* yacc.c:1646  */
    {printf(" n5 ");(yyval.fn)=(yyvsp[0].fn);}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "prog.y" /* yacc.c:1646  */
    {printf(" n6 ");(yyval.fn)=(yyvsp[0].fn);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 73 "prog.y" /* yacc.c:1646  */
    {printf(" n7 ");fieldinstall((yyvsp[-1].gn)->name,findex,(yyvsp[-2].tyn));findex+=1;(yyval.fn)=Fieldnode;}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 75 "prog.y" /* yacc.c:1646  */
    {printf(" n8 ");(yyval.tyn)=gettype("int");}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 76 "prog.y" /* yacc.c:1646  */
    {printf(" n9 ");(yyval.tyn)=gettype("str");}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 77 "prog.y" /* yacc.c:1646  */
    {printf(" n10 ");if(gettype((yyvsp[0].gn)->name)!=NULL)
                              (yyval.tyn)=gettype((yyvsp[0].gn)->name);
                            else
                            {
                              (yyval.tyn)=NULL;
                              Ghold=(yyvsp[0].gn);
                              }}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 87 "prog.y" /* yacc.c:1646  */
    {printf(" c1 ");printclass();classflag=0;}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 88 "prog.y" /* yacc.c:1646  */
    {printf(" c2 ");}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "prog.y" /* yacc.c:1646  */
    {printf(" c3 ");}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 91 "prog.y" /* yacc.c:1646  */
    {printf(" c4 ");}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 93 "prog.y" /* yacc.c:1646  */
    {printf(" c5 ");}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 94 "prog.y" /* yacc.c:1646  */
    {printf(" c5 ");}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 95 "prog.y" /* yacc.c:1646  */
    {printf(" c5 ");}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 97 "prog.y" /* yacc.c:1646  */
    {printf(" c6 ");Cptr=Cinstall((yyvsp[0].gn)->name,NULL);}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 98 "prog.y" /* yacc.c:1646  */
    {printf(" c7 ");Cptr=Cinstall((yyvsp[-2].gn)->name,(yyvsp[0].gn)->name);}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 100 "prog.y" /* yacc.c:1646  */
    {printf(" c8 ");}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 101 "prog.y" /* yacc.c:1646  */
    {printf(" c9 ");}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 103 "prog.y" /* yacc.c:1646  */
    {printf(" c10 ");ClassFinstall(Cptr,(yyvsp[-2].gn)->name,(yyvsp[-1].gn)->name);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 105 "prog.y" /* yacc.c:1646  */
    {printf(" c11 ");}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 106 "prog.y" /* yacc.c:1646  */
    {printf(" c12 ");}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 108 "prog.y" /* yacc.c:1646  */
    {printf(" c13 ");ClassMinstall(Cptr,(yyvsp[-4].gn)->name,gettype((yyvsp[-5].gn)->name),(yyvsp[-2].pn));}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 110 "prog.y" /* yacc.c:1646  */
    {printf(" c14 ");}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 111 "prog.y" /* yacc.c:1646  */
    {printf(" c15 ");}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 115 "prog.y" /* yacc.c:1646  */
    {printf(" y4 ");
                                    Symbolhead=(yyvsp[-1].gn);Symbolhead->next=(yyvsp[-1].gn)->next;
                                    printsymbols(Symbolhead);deflag=1;lhead=NULL;nlbindval=bindval;lbindval=1;

                                    }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 120 "prog.y" /* yacc.c:1646  */
    {printf(" y5 ");Symbolhead=NULL;lhead=NULL;nlbindval=bindval;lbindval=1;
                        fprintf(outputfile,"CALL L0\nINT 10\n");}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 122 "prog.y" /* yacc.c:1646  */
    {printf(" global ");}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 124 "prog.y" /* yacc.c:1646  */
    {printf(" y6 ");(yyval.gn)=concatid((yyvsp[-1].gn),(yyvsp[0].gn));bindval++;}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 125 "prog.y" /* yacc.c:1646  */
    {printf(" y7 ");(yyval.gn)=(yyvsp[0].gn);bindval++;}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 127 "prog.y" /* yacc.c:1646  */
    {printf(" y8 ");
                                updatetypelist((yyvsp[-1].gn),(yyvsp[-2].tyn));
                                if((yyvsp[-2].tyn)==NULL)
                                {
                                  updatectypelist((yyvsp[-1].gn),Ghold);
                                }(yyval.gn)=(yyvsp[-1].gn);}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 134 "prog.y" /* yacc.c:1646  */
    {printf(" y9 ");(yyval.gn)=concatid((yyvsp[-2].gn),(yyvsp[0].gn));}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 135 "prog.y" /* yacc.c:1646  */
    {printf(" y10 ");(yyval.gn)=(yyvsp[0].gn);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 137 "prog.y" /* yacc.c:1646  */
    {printf(" y11 ");(yyvsp[-3].gn)->paramlist=(yyvsp[-1].pn);(yyval.gn)=(yyvsp[-3].gn);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 138 "prog.y" /* yacc.c:1646  */
    {printf(" y12 ");sizeupdate((yyvsp[-3].gn),(yyvsp[-1].i));(yyval.gn)=(yyvsp[-3].gn);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 139 "prog.y" /* yacc.c:1646  */
    {printf(" y13 ");(yyval.gn)=(yyvsp[0].gn);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 143 "prog.y" /* yacc.c:1646  */
    {printf(" y14 ");lhead=NULL;lbindval=1;}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 144 "prog.y" /* yacc.c:1646  */
    {printf(" y15 ");lhead=NULL;lbindval=1;}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 148 "prog.y" /* yacc.c:1646  */
    {printf(" y16 ");int l=0;
                                  fprintf(outputfile,"L%d:\n",l);
                                  ml=1;
                                  strcpy(currentfname,"main");
                                  int i;
                                  for(i=0;i<bindval;i++)
                                    fprintf(outputfile,"PUSH R0\n");

                                  generate((yyvsp[-1].tn));

                                  fprintf(outputfile,"L%d:\n",ml);
                                  lpop();

                                  for(int j=i;j>0;j--)
                                    fprintf(outputfile,"POP R0\n");

                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 168 "prog.y" /* yacc.c:1646  */
    {printf(" y17 ");
                                  if(classflag==0)
                                  {
                                  int l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  struct Gsymbol *gn;
                                  gn=lookup((yyvsp[-7].gn)->name);
                                  gn->binding=l;
                                  l=getlabel();
                                  strcpy(currentfname,(yyvsp[-7].gn)->name);

                                  generate((yyvsp[-1].tn));

                                  fprintf(outputfile,"L%d:\n",l);
                                  lpop();
                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  resetreg();
                                  }
                                  else
                                  {

                                  struct Memberfunlist *mem;
                                  mem=ClassMlookup(Cptr,(yyvsp[-7].gn)->name);

                                  int l=getlabel();
                                  mem->flabel=l;
                                  fprintf(outputfile,"L%d:\n",l);
                                  l=getlabel();
                                  strcpy(currentfname,(yyvsp[-7].gn)->name);

                                  generate((yyvsp[-1].tn));

                                  fprintf(outputfile,"L%d:\n",l);
                                  lpop();
                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  resetreg();
                                  }lhead=NULL;lbindval=1;}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 212 "prog.y" /* yacc.c:1646  */
    {printf(" y18 ");(yyval.pn)=concatpid((yyvsp[-2].pn),(yyvsp[0].pn));}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 213 "prog.y" /* yacc.c:1646  */
    {printf(" y19 ");(yyval.pn)=(yyvsp[0].pn);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 214 "prog.y" /* yacc.c:1646  */
    {(yyval.pn)=NULL;lhead=NULL;}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 216 "prog.y" /* yacc.c:1646  */
    {printf(" y20 ");
                      (yyval.pn)=makepnode((yyvsp[0].gn)->name,(yyvsp[-1].tyn),0);

                        makelocalentry((yyval.pn),0-nlbindval);nlbindval--;
                      }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 224 "prog.y" /* yacc.c:1646  */
    {printf(" y23 ");printlsymbols((yyvsp[-1].ln));}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 225 "prog.y" /* yacc.c:1646  */
    {printf(" y24 ");lhead=NULL;}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 226 "prog.y" /* yacc.c:1646  */
    {(yyval.ln)=NULL;}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 228 "prog.y" /* yacc.c:1646  */
    {printf(" y25 ");(yyval.ln)=lhead;}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 229 "prog.y" /* yacc.c:1646  */
    {printf(" y26 ");(yyval.ln)=(yyvsp[0].ln);}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 231 "prog.y" /* yacc.c:1646  */
    {printf(" y27 ");updateltypelist((yyvsp[-1].ln),(yyvsp[-2].tyn));(yyval.ln)=lhead;}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 233 "prog.y" /* yacc.c:1646  */
    {printf(" y28 ");linstall((yyvsp[0].gn)->name,NULL,lbindval);lbindval++;(yyval.ln)=lhead;}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 234 "prog.y" /* yacc.c:1646  */
    {printf(" y29 ");linstall((yyvsp[0].gn)->name,NULL,lbindval);lbindval++;(yyval.ln)=lhead;}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 236 "prog.y" /* yacc.c:1646  */
    {printf(" y30 ");(yyvsp[-2].tn)->Arglist=(yyvsp[0].tn);}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 237 "prog.y" /* yacc.c:1646  */
    {printf(" y31 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 238 "prog.y" /* yacc.c:1646  */
    {(yyval.tn)=NULL;}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 242 "prog.y" /* yacc.c:1646  */
    {printf(" y32 ");generate_flag=0;(yyval.tn)=(yyvsp[-1].tn);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 243 "prog.y" /* yacc.c:1646  */
    {printf(" y33 ");(yyval.tn)=NULL;}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 245 "prog.y" /* yacc.c:1646  */
    {printf(" y34 ");(yyval.tn)=connector((yyvsp[-1].tn),(yyvsp[0].tn));}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 246 "prog.y" /* yacc.c:1646  */
    {printf(" y35 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 248 "prog.y" /* yacc.c:1646  */
    {printf(" y36 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 249 "prog.y" /* yacc.c:1646  */
    {printf(" y37 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 250 "prog.y" /* yacc.c:1646  */
    {printf(" y38 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 251 "prog.y" /* yacc.c:1646  */
    {printf(" y39 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 252 "prog.y" /* yacc.c:1646  */
    {printf(" y40 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 253 "prog.y" /* yacc.c:1646  */
    {printf(" y41 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 254 "prog.y" /* yacc.c:1646  */
    {printf(" y42 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 255 "prog.y" /* yacc.c:1646  */
    {printf(" yr ");(yyval.tn)=(yyvsp[0].tn);}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 256 "prog.y" /* yacc.c:1646  */
    {printf(" n11 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 257 "prog.y" /* yacc.c:1646  */
    {printf(" n12 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 258 "prog.y" /* yacc.c:1646  */
    {printf(" c16 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 259 "prog.y" /* yacc.c:1646  */
    {printf(" c17 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 261 "prog.y" /* yacc.c:1646  */
    {printf(" y43 ");(yyval.tn)=Inode((yyvsp[-2].tn));}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 263 "prog.y" /* yacc.c:1646  */
    {printf(" y44 ");(yyval.tn)=Onode((yyvsp[-2].tn));}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 265 "prog.y" /* yacc.c:1646  */
    {printf(" y45 ");
                               struct tnode *t;
                               struct Gsymbol *gt;
                               struct Lsymbol *lt;
                               lt=llookup((yyvsp[-3].gn)->name);
                               if(lt==NULL)
                                 gt=lookup((yyvsp[-3].gn)->name);
                               else
                                 gt=NULL;
                               t=varnode((yyvsp[-3].gn)->name,lt,gt);
                               (yyval.tn)=opnode('=',t,(yyvsp[-1].tn));}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 276 "prog.y" /* yacc.c:1646  */
    {printf(" n13 ");(yyval.tn)=opnode('=',(yyvsp[-3].tn),(yyvsp[-1].tn));}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 278 "prog.y" /* yacc.c:1646  */
    {printf(" y46 ");struct tnode *t;
        t=connector((yyvsp[-4].tn),(yyvsp[-2].tn));(yyval.tn)=ifelsenode((yyvsp[-7].tn),t);}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 280 "prog.y" /* yacc.c:1646  */
    {printf(" y47 ");(yyval.tn)=ifnode((yyvsp[-5].tn),(yyvsp[-2].tn));}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 282 "prog.y" /* yacc.c:1646  */
    {printf(" y48 ");(yyval.tn)=whilenode((yyvsp[-5].tn),(yyvsp[-2].tn));}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 284 "prog.y" /* yacc.c:1646  */
    {printf(" y49 ");(yyval.tn)=breaknode();}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 286 "prog.y" /* yacc.c:1646  */
    {printf(" y50 ");(yyval.tn)=continuenode();}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 288 "prog.y" /* yacc.c:1646  */
    {(yyval.tn)=retnode((yyvsp[-1].tn));}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 289 "prog.y" /* yacc.c:1646  */
    {(yyval.tn)=retnode(NULL);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 291 "prog.y" /* yacc.c:1646  */
    {printf(" n14 ");struct tnode *t;
                                        struct Gsymbol *gt;
                                        struct Lsymbol *lt;
                                        lt=llookup((yyvsp[-5].gn)->name);
                                        if(lt==NULL)
                                          gt=lookup((yyvsp[-5].gn)->name);
                                        else
                                          gt=NULL;
                                        t=varnode((yyvsp[-5].gn)->name,lt,gt);(yyval.tn)=allocnode(t);}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 300 "prog.y" /* yacc.c:1646  */
    {printf(" n15 ");(yyval.tn)=allocnode((yyvsp[-5].tn));}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 302 "prog.y" /* yacc.c:1646  */
    {printf(" n16 ");
                                struct tnode *t;
                                struct Gsymbol *gt;
                                struct Lsymbol *lt;
                                lt=llookup((yyvsp[-2].gn)->name);
                                if(lt==NULL)
                                  gt=lookup((yyvsp[-2].gn)->name);
                                else
                                  gt=NULL;
                                t=varnode((yyvsp[-2].gn)->name,lt,gt);(yyval.tn)=freenode(t);}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 312 "prog.y" /* yacc.c:1646  */
    {printf(" n17 ");(yyval.tn)=freenode((yyvsp[-2].tn));}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 314 "prog.y" /* yacc.c:1646  */
    {printf(" c18 ");struct tnode *t1,*t2;
                                        struct Gsymbol *gt;
                                        struct Lsymbol *lt;
                                        lt=llookup((yyvsp[-6].gn)->name);
                                        if(lt==NULL)
                                          gt=lookup((yyvsp[-6].gn)->name);
                                        else
                                          gt=NULL;
                                        t1=varnode((yyvsp[-6].gn)->name,lt,gt);
                                        lt=llookup((yyvsp[-2].gn)->name);
                                        if(lt==NULL)
                                          gt=lookup((yyvsp[-2].gn)->name);
                                        else
                                          gt=NULL;
                                        t2=varnode((yyvsp[-2].gn)->name,lt,gt);
                                        (yyval.tn)=newnode(t1,t2);}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 330 "prog.y" /* yacc.c:1646  */
    {printf(" c19 ");struct tnode *t;
                                        struct Gsymbol *gt;
                                        struct Lsymbol *lt;
                                        lt=llookup((yyvsp[-2].gn)->name);
                                        if(lt==NULL)
                                          gt=lookup((yyvsp[-2].gn)->name);
                                        else
                                          gt=NULL;
                                        t=varnode((yyvsp[-2].gn)->name,lt,gt);
                                        (yyval.tn)=newnode((yyvsp[-6].tn),t);}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 341 "prog.y" /* yacc.c:1646  */
    {printf(" c20 ");
                                        (yyval.tn)=deletenode((yyvsp[-2].tn));}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 346 "prog.y" /* yacc.c:1646  */
    {printf(" n18 ");
                    struct tnode *t;
                    struct Gsymbol *gt;
                    struct Lsymbol *lt;
                    struct Typetable *tp;
                    lt=llookup((yyvsp[-2].gn)->name);
                    if(lt==NULL)
                    {
                      gt=lookup((yyvsp[-2].gn)->name);
                      tp=gt->type;
                    }
                    else
                    {
                      tp=lt->type;
                      gt=NULL;
                    }
                    t=varnode((yyvsp[-2].gn)->name,lt,gt);
                    t->type=tp;
                    (yyval.tn)=fldnode((yyvsp[0].gn)->name,t);
                    (yyval.tn)->type=getfieldtype((yyvsp[0].gn)->name,tp);
                    }
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 367 "prog.y" /* yacc.c:1646  */
    {printf(" n19 ");
                      (yyval.tn)=fldnode((yyvsp[0].gn)->name,(yyvsp[-2].tn));
                      (yyval.tn)->type=getfieldtype((yyvsp[0].gn)->name,(yyvsp[-2].tn)->type);
                      }
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 371 "prog.y" /* yacc.c:1646  */
    {printf(" c21 ");struct tnode *s;
                      s=selfnode();
                      (yyval.tn)=fldnode((yyvsp[0].gn)->name,s);
                      struct Typetable *tp;
                      struct Fieldlist *fl;
                      fl=ClassFlookup(Cptr,(yyvsp[0].gn)->name);
                      tp=fl->type;
                      (yyval.tn)->type=tp;}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 381 "prog.y" /* yacc.c:1646  */
    {printf(" c22 ");struct tnode *s,*t;
                                          s=selfnode();
                                          struct Gsymbol *gt;
                                          struct Lsymbol *lt;
                                          lt=llookup((yyvsp[-3].gn)->name);
                                          if(lt==NULL)
                                            gt=lookup((yyvsp[-3].gn)->name);
                                          else
                                            gt=NULL;
                                          t=varnode((yyvsp[-3].gn)->name,lt,gt);
                                          (yyval.tn)=fieldfunnode(s,t,(yyvsp[-1].tn));}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 392 "prog.y" /* yacc.c:1646  */
    {printf(" c23 ");
                                  struct tnode *t1,*t2;
                                  struct Gsymbol *gt;
                                  struct Lsymbol *lt;
                                  lt=llookup((yyvsp[-5].gn)->name);
                                  if(lt==NULL)
                                    gt=lookup((yyvsp[-5].gn)->name);
                                  else
                                    gt=NULL;
                                  t1=varnode((yyvsp[-5].gn)->name,lt,gt);
                                  lt=llookup((yyvsp[-3].gn)->name);
                                  if(lt==NULL)
                                    gt=lookup((yyvsp[-3].gn)->name);
                                  else
                                    gt=NULL;
                                  t2=varnode((yyvsp[-3].gn)->name,lt,gt);
                                  (yyval.tn)=fieldfunnode(t1,t2,(yyvsp[-1].tn));
                                  }
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 410 "prog.y" /* yacc.c:1646  */
    {printf(" c24 ");
                                    struct tnode *t;
                                    struct Gsymbol *gt;
                                    struct Lsymbol *lt;
                                    lt=llookup((yyvsp[-3].gn)->name);
                                    if(lt==NULL)
                                      gt=lookup((yyvsp[-3].gn)->name);
                                    else
                                      gt=NULL;
                                    t=varnode((yyvsp[-3].gn)->name,lt,gt);
                                    (yyval.tn)=fieldfunnode((yyvsp[-5].tn),t,(yyvsp[-1].tn));}
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 424 "prog.y" /* yacc.c:1646  */
    {printf(" y51 ");(yyval.tn)=relnode("<",(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 425 "prog.y" /* yacc.c:1646  */
    {printf(" y52 ");(yyval.tn)=relnode(">",(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 426 "prog.y" /* yacc.c:1646  */
    {printf(" y53 ");(yyval.tn)=relnode("<=",(yyvsp[-3].tn),(yyvsp[0].tn));}
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 427 "prog.y" /* yacc.c:1646  */
    {printf(" y54 ");(yyval.tn)=relnode(">=",(yyvsp[-3].tn),(yyvsp[0].tn));}
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 428 "prog.y" /* yacc.c:1646  */
    {printf(" y55 ");(yyval.tn)=relnode("!=",(yyvsp[-3].tn),(yyvsp[0].tn));}
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 429 "prog.y" /* yacc.c:1646  */
    {printf(" y56 ");(yyval.tn)=relnode("==",(yyvsp[-3].tn),(yyvsp[0].tn));}
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 431 "prog.y" /* yacc.c:1646  */
    {printf(" y57 ");(yyval.tn)=opnode('+',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 432 "prog.y" /* yacc.c:1646  */
    {printf(" y58 ");(yyval.tn)=opnode('*',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 433 "prog.y" /* yacc.c:1646  */
    {printf(" y59 ");(yyval.tn)=opnode('-',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 434 "prog.y" /* yacc.c:1646  */
    {printf(" y60 ");(yyval.tn)=opnode('/',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 435 "prog.y" /* yacc.c:1646  */
    {printf(" y60.1 ");(yyval.tn)=opnode('%',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 436 "prog.y" /* yacc.c:1646  */
    {printf(" y61 ");(yyval.tn)=(yyvsp[-1].tn);}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 437 "prog.y" /* yacc.c:1646  */
    {printf(" y62 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 438 "prog.y" /* yacc.c:1646  */
    {printf(" y63 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 439 "prog.y" /* yacc.c:1646  */
    {printf(" n20 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 440 "prog.y" /* yacc.c:1646  */
    {printf(" c25 ");(yyval.tn)=(yyvsp[0].tn);}
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 441 "prog.y" /* yacc.c:1646  */
    {printf(" n21 ");(yyval.tn)=(yyvsp[-2].tn);}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 442 "prog.y" /* yacc.c:1646  */
    {printf(" n22 ");(yyval.tn)=NULL;}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 443 "prog.y" /* yacc.c:1646  */
    {printf(" y64 ");
                      struct Lsymbol *lt;
                      struct Gsymbol *gt;
                      lt=llookup((yyvsp[0].gn)->name);
                      if(lt==NULL)
                        gt=lookup((yyvsp[0].gn)->name);
                      else
                        gt=NULL;
                      if(lt==NULL&&gt==NULL)
                        printf(" \\no entry found//");
                      (yyval.tn)=varnode((yyvsp[0].gn)->name ,lt ,gt);}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 454 "prog.y" /* yacc.c:1646  */
    {printf(" y66 ");
                          struct Lsymbol *lt;
                          struct Gsymbol *gt;
                          lt=llookup((yyvsp[-3].gn)->name);
                          if(lt==NULL)
                            gt=lookup((yyvsp[-3].gn)->name);
                          else
                            gt=NULL;
                          (yyval.tn)=funnode((yyvsp[-3].gn)->name ,lt ,gt ,(yyvsp[-1].tn));}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2513 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 465 "prog.y" /* yacc.c:1906  */


int yyerror(char const *s)
{
  printf("yyerror %s",s);
}
int main()
{
  loopflag[0]=0;
  lhead=NULL;
  ci=0;
  outputfile=fopen("input.xsm","w");
  Reg=(struct regpool *)malloc(sizeof(struct regpool));
  Reg->reg=-1;
  Reg->label=1;
  fprintf(outputfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP,4095\nMOV BP,4096\nPUSH R0\n",0,2056,0,0,0,0,0,0);
  inp();
  yyparse();
  return 0;
}
