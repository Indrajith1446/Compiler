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
#line 3 "t3.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "t3.h"
#include "t3.c"
int yylex();
int yywrap();
struct regpool * Reg;
FILE *outputfile;
int printval;
int loopflag[3];
int yyerror(char const *s);


#line 82 "y.tab.c" /* yacc.c:339  */

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
#line 19 "t3.y" /* yacc.c:355  */

struct tnode * tn;
struct Gsymbol * gn;
struct Lsymbol * ln;
struct Paramstruct * pn;
int i;

#line 218 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    43,    44,    46,    47,    49,    50,    52,
      54,    55,    57,    58,    59,    61,    62,    64,    75,    88,
      89,    91,    93,    94,    96,    97,    99,   100,   102,   104,
     105,   107,   108,   110,   111,   113,   114,   116,   117,   118,
     119,   120,   121,   122,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   142,   144,   145,   146,   147,   148,
     149,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "PLUS", "END", "MINUS", "DIV",
  "MUL", "ID", "BEGN", "READ", "WRITE", "EQUAL", "SEMCL", "LP", "RP", "IF",
  "THEN", "ENDIF", "BREAK", "CONTINUE", "COMMA", "DECL", "ENDDECL", "INT",
  "STR", "ELSE", "WHILE", "DO", "ENDWHILE", "LT", "GT", "NOT", "VAR",
  "NUP", "LID", "LSB", "RSB", "STRING", "MAIN", "LCB", "RCB", "PM",
  "RETURN", "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl",
  "GidList", "GID", "FdefBlock", "MainBlock", "Fdef", "ParamList", "Param",
  "Type", "LdeclBlock", "LDecList", "LDecl", "IdList", "ArgList", "Body",
  "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgStmt", "IfStmt",
  "WhileStmt", "BreakStmt", "ContinueStmt", "ReturnStmt", "E", "expr", YY_NULLPTR
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
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,   134,   -87,   -87,     9,    32,   -87,   -24,   -87,   150,
     -87,    10,   -87,    32,   -87,   -87,    -5,    14,   -87,   -87,
      -9,    20,   -87,   -87,   -87,    28,    49,    32,    39,   -87,
      10,    32,    42,    -4,   -87,    48,    51,   -87,     1,    70,
     -87,    32,   -87,   -87,    59,   168,    93,   -87,    70,   -87,
      69,   173,   -87,    87,    71,    93,   -87,    30,   -87,   -87,
     -87,   -87,    94,    99,    11,   101,   103,   106,   108,   114,
     -87,     7,   107,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   248,   -87,    88,   -87,    96,    11,    11,   141,
      11,   -87,   -87,    11,    17,   -87,   234,   -87,   -87,    11,
      11,    11,    11,    11,   -87,   -87,   209,   223,   -87,   120,
     201,   124,   -87,    38,   216,   -87,    89,    89,   -87,   -87,
     239,   130,   139,   136,   125,    46,   187,   149,   148,   -87,
      11,   -87,   -87,   -87,   167,    11,    11,   216,    11,   216,
      11,   167,   216,    67,   216,   216,   216,   216,   122,   151,
     167,   154,   -87,   152,   -87,   169,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    22,    23,     0,     0,     4,     0,     6,     0,
       8,     0,     1,     0,     3,    16,     0,     0,     5,     7,
      14,     0,    11,     2,    15,     0,     0,     0,     0,     9,
       0,     0,     0,     0,    20,     0,     0,    10,     0,     0,
      12,     0,    21,    13,     0,     0,     0,    19,     0,    25,
       0,     0,    27,     0,     0,     0,    30,     0,    24,    26,
      66,    34,     0,     0,     0,     0,     0,     0,     0,    68,
      67,     0,     0,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    17,     0,    28,     0,     0,     0,     0,
       0,    51,    52,     0,     0,    54,     0,    33,    35,     0,
       0,     0,     0,     0,    18,    29,     0,     0,    65,     0,
       0,     0,    69,     0,    32,    53,    61,    63,    64,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,    47,    45,    46,     0,     0,     0,    55,     0,    56,
       0,     0,    31,     0,    60,    57,    58,    59,     0,     0,
       0,     0,    49,     0,    50,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   172,   -87,   155,   -87,     0,   176,
     179,   162,     2,   156,   -87,   161,   -87,   -87,   163,   -86,
     -72,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   126,
     -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     9,    10,    21,    22,    13,     6,    15,
      33,    34,    35,    46,    51,    52,    57,   113,    54,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   109,
      82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      98,    89,     7,    11,    25,    14,    27,    16,    96,    12,
      60,    11,    40,    23,    60,    16,    17,    44,    41,    20,
      60,    95,    64,    41,   106,   107,    64,   110,    28,    26,
     110,   114,    64,   112,    29,    17,   116,   117,   118,   119,
     120,    69,    30,    31,    85,    69,    70,    50,   143,    60,
      70,    69,    86,    50,   129,   148,    70,     2,     3,   136,
     130,    64,   137,   139,   153,    32,     1,   142,     2,     3,
      60,    98,   144,   145,    36,   146,    98,   147,    62,    63,
      69,    98,    64,    39,    65,    70,   149,    66,    67,    43,
      60,    42,    61,    45,   150,    68,   101,   102,    62,    63,
      48,    69,    64,    53,    65,    56,    70,    66,    67,    87,
      60,    71,    97,    83,    88,    68,    90,    91,    62,    63,
      92,    69,    64,    93,    65,    60,    70,    66,    67,    94,
     104,    71,   105,    62,    63,    68,   123,    64,   135,    65,
     128,    69,    66,    67,   132,    99,    70,   100,   101,   102,
      68,    71,   151,   133,   134,    60,    69,   108,     8,     2,
       3,    70,   140,    62,    63,   152,    71,    64,   154,    65,
      60,   155,    66,    67,    18,     2,     3,   141,    62,    63,
      68,    19,    64,   156,    65,    37,    69,    66,    67,    24,
      60,    70,    49,     2,     3,    68,    71,    58,     2,     3,
     138,    69,    64,    47,    55,    99,    70,   100,   101,   102,
      38,    71,    59,    99,   124,   100,   101,   102,    84,   111,
      99,    69,   100,   101,   102,   121,    70,    99,     0,   100,
     101,   102,   125,   126,   127,     0,     0,     0,    99,   122,
     100,   101,   102,    99,     0,   100,   101,   102,   115,     0,
       0,     0,    99,   131,   100,   101,   102,     0,     0,     0,
       0,   103
};

static const yytype_int16 yycheck[] =
{
      72,    64,     0,     1,     9,     5,    15,     5,    71,     0,
       3,     9,    16,    13,     3,    13,    40,    16,    22,     9,
       3,    14,    15,    22,    87,    88,    15,    90,    37,    15,
      93,    94,    15,    16,    14,    40,    99,   100,   101,   102,
     103,    34,    22,    15,    14,    34,    39,    45,   134,     3,
      39,    34,    22,    51,    16,   141,    39,    25,    26,    13,
      22,    15,   125,   126,   150,    16,    23,   130,    25,    26,
       3,   143,   135,   136,    35,   138,   148,   140,    11,    12,
      34,   153,    15,    41,    17,    39,    19,    20,    21,    38,
       3,    43,     5,    23,    27,    28,     7,     8,    11,    12,
      41,    34,    15,    10,    17,    36,    39,    20,    21,    15,
       3,    44,     5,    42,    15,    28,    15,    14,    11,    12,
      14,    34,    15,    15,    17,     3,    39,    20,    21,    15,
      42,    44,    36,    11,    12,    28,    16,    15,    13,    17,
      16,    34,    20,    21,    14,     4,    39,     6,     7,     8,
      28,    44,    30,    14,    18,     3,    34,    16,    24,    25,
      26,    39,    13,    11,    12,    14,    44,    15,    14,    17,
       3,    19,    20,    21,    24,    25,    26,    29,    11,    12,
      28,     9,    15,    14,    17,    30,    34,    20,    21,    13,
       3,    39,    24,    25,    26,    28,    44,    24,    25,    26,
      13,    34,    15,    41,    48,     4,    39,     6,     7,     8,
      31,    44,    51,     4,    13,     6,     7,     8,    55,    93,
       4,    34,     6,     7,     8,    16,    39,     4,    -1,     6,
       7,     8,    31,    32,    33,    -1,    -1,    -1,     4,    16,
       6,     7,     8,     4,    -1,     6,     7,     8,    14,    -1,
      -1,    -1,     4,    14,     6,     7,     8,    -1,    -1,    -1,
      -1,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    25,    26,    46,    47,    53,    57,    24,    48,
      49,    57,     0,    52,    53,    54,    57,    40,    24,    49,
       9,    50,    51,    53,    54,     9,    15,    15,    37,    14,
      22,    15,    16,    55,    56,    57,    35,    51,    55,    41,
      16,    22,    43,    38,    16,    23,    58,    56,    41,    24,
      57,    59,    60,    10,    63,    58,    36,    61,    24,    60,
       3,     5,    11,    12,    15,    17,    20,    21,    28,    34,
      39,    44,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    75,    42,    63,    14,    22,    15,    15,    75,
      15,    14,    14,    15,    15,    14,    75,     5,    65,     4,
       6,     7,     8,    13,    42,    36,    75,    75,    16,    74,
      75,    74,    16,    62,    75,    14,    75,    75,    75,    75,
      75,    16,    16,    16,    13,    31,    32,    33,    16,    16,
      22,    14,    14,    14,    18,    13,    13,    75,    13,    75,
      13,    29,    75,    64,    75,    75,    75,    75,    64,    19,
      27,    30,    14,    64,    14,    19,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    46,    47,    47,    48,    48,    49,
      50,    50,    51,    51,    51,    52,    52,    53,    54,    55,
      55,    56,    57,    57,    58,    58,    59,    59,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    68,    69,    69,
      70,    71,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     4,     4,     1,     2,     1,     8,     9,     3,
       1,     2,     1,     1,     3,     2,     2,     1,     3,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     4,    10,     8,
       8,     2,     2,     3,     2,     3,     3,     4,     4,     4,
       4,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       4
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
#line 42 "t3.y" /* yacc.c:1646  */
    {printf(" y1 ");}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 43 "t3.y" /* yacc.c:1646  */
    {printf(" y2 ");}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 44 "t3.y" /* yacc.c:1646  */
    {printf(" y3 ");}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 46 "t3.y" /* yacc.c:1646  */
    {printsymbols((yyvsp[-1].gn));printf(" y4 ");(yyval.gn)=(yyvsp[-1].gn);}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 47 "t3.y" /* yacc.c:1646  */
    {printf(" y5 ");}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "t3.y" /* yacc.c:1646  */
    {printf(" y6 ");(yyval.gn)=(yyvsp[0].gn);}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "t3.y" /* yacc.c:1646  */
    {printf(" y7 ");(yyval.gn)=(yyvsp[0].gn);}
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 52 "t3.y" /* yacc.c:1646  */
    {printf(" y8 ");updatetype((yyvsp[-1].gn),(yyvsp[-2].i));(yyval.gn)=(yyvsp[-1].gn);}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 54 "t3.y" /* yacc.c:1646  */
    {printf(" y9 ");(yyval.gn)=(yyvsp[0].gn);}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 55 "t3.y" /* yacc.c:1646  */
    {printf(" y10 ");(yyval.gn)=(yyvsp[0].gn);}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 57 "t3.y" /* yacc.c:1646  */
    {printf(" y11 ");(yyvsp[-3].gn)->paramlist=(yyvsp[-1].pn);(yyval.gn)=(yyvsp[-3].gn);}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 58 "t3.y" /* yacc.c:1646  */
    {printf(" y12 ");sizeupdate((yyvsp[-3].gn),(yyvsp[-1].i));(yyval.gn)=(yyvsp[-3].gn);}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 59 "t3.y" /* yacc.c:1646  */
    {printf(" y13 ");(yyval.gn)=(yyvsp[0].gn);}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 61 "t3.y" /* yacc.c:1646  */
    {printf(" y14 ");}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 62 "t3.y" /* yacc.c:1646  */
    {printf(" y15 ");}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 64 "t3.y" /* yacc.c:1646  */
    {printf(" y16 ");int l=0;
                                  fprintf(outputfile,"L%d:\n",l);
                                  ml=1;
                                  strcpy(currentfname,"main");
                                  generate((yyvsp[-1].tn));
                                  fprintf(outputfile,"L%d:\n",ml);
                                  lpop();
                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "t3.y" /* yacc.c:1646  */
    {printf(" y17 ");int l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  (yyvsp[-7].gn)->binding=l;
                                  l=getlabel();
                                  strcpy(currentfname,(yyvsp[-7].gn)->name);
                                  generate((yyvsp[-1].tn));
                                  fprintf(outputfile,"L%d:\n",l);
                                  lpop();
                                  fprintf(outputfile,"RET\n");
                                  l=getlabel();
                                  fprintf(outputfile,"L%d:\n",l);
                                  resetreg();}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 88 "t3.y" /* yacc.c:1646  */
    {printf(" y18 ");(yyval.pn)=(yyvsp[0].pn);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "t3.y" /* yacc.c:1646  */
    {printf(" y19 ");(yyval.pn)=(yyvsp[0].pn);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 91 "t3.y" /* yacc.c:1646  */
    {printf(" y20 ");(yyval.pn)=(yyvsp[0].pn);}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 93 "t3.y" /* yacc.c:1646  */
    {printf(" y21 ");(yyval.i)=1;}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 94 "t3.y" /* yacc.c:1646  */
    {printf(" y22 ");(yyval.i)=2;}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 96 "t3.y" /* yacc.c:1646  */
    {printf(" y23 ");printlsymbols(lhead);(yyval.ln)=(yyvsp[-1].ln);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 97 "t3.y" /* yacc.c:1646  */
    {printf(" y24 ");(yyval.ln)=NULL;}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 99 "t3.y" /* yacc.c:1646  */
    {printf(" y25 ");(yyval.ln)=(yyvsp[0].ln);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 100 "t3.y" /* yacc.c:1646  */
    {printf(" y26 ");(yyval.ln)=(yyvsp[0].ln);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 102 "t3.y" /* yacc.c:1646  */
    {printf(" y27 ");updateltype((yyvsp[-1].ln),(yyvsp[-2].i));(yyval.ln)=(yyvsp[-1].ln);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 104 "t3.y" /* yacc.c:1646  */
    {printf(" y28 ");(yyval.ln)=(yyvsp[0].ln);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 105 "t3.y" /* yacc.c:1646  */
    {printf(" y29 ");(yyval.ln)=(yyvsp[0].ln);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 107 "t3.y" /* yacc.c:1646  */
    {printf(" y30 ");(yyvsp[-2].tn)->Arglist=(yyvsp[0].tn);(yyval.tn)=(yyvsp[-2].tn);}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 108 "t3.y" /* yacc.c:1646  */
    {printf(" y31 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 110 "t3.y" /* yacc.c:1646  */
    {printf(" y32 ");generate_flag=0;(yyval.tn)=(yyvsp[-1].tn);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 111 "t3.y" /* yacc.c:1646  */
    {printf(" y33 ");(yyval.tn)=NULL;}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 113 "t3.y" /* yacc.c:1646  */
    {printf(" y34 ");(yyval.tn)=connector((yyvsp[-1].tn),(yyvsp[0].tn));}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 114 "t3.y" /* yacc.c:1646  */
    {printf(" y35 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 116 "t3.y" /* yacc.c:1646  */
    {printf(" y36 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 117 "t3.y" /* yacc.c:1646  */
    {printf(" y37 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 118 "t3.y" /* yacc.c:1646  */
    {printf(" y38 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 119 "t3.y" /* yacc.c:1646  */
    {printf(" y39 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 120 "t3.y" /* yacc.c:1646  */
    {printf(" y40 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 121 "t3.y" /* yacc.c:1646  */
    {printf(" y41 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 122 "t3.y" /* yacc.c:1646  */
    {printf(" y42 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 123 "t3.y" /* yacc.c:1646  */
    {printf(" yr ");(yyval.tn)=(yyvsp[0].tn);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 125 "t3.y" /* yacc.c:1646  */
    {printf(" y43 ");(yyval.tn)=Inode((yyvsp[-2].tn));}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 127 "t3.y" /* yacc.c:1646  */
    {printf(" y44 ");(yyval.tn)=Onode((yyvsp[-2].tn));}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 129 "t3.y" /* yacc.c:1646  */
    {printf(" y45 ");(yyval.tn)=opnode('=',(yyvsp[-3].tn),(yyvsp[-1].tn));}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 131 "t3.y" /* yacc.c:1646  */
    {printf(" y46 ");struct tnode *t;
        t=connector((yyvsp[-4].tn),(yyvsp[-2].tn));(yyval.tn)=ifelsenode((yyvsp[-7].tn),t);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 133 "t3.y" /* yacc.c:1646  */
    {printf(" y47 ");(yyval.tn)=ifnode((yyvsp[-5].tn),(yyvsp[-2].tn));}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 135 "t3.y" /* yacc.c:1646  */
    {printf(" y48 ");(yyval.tn)=whilenode((yyvsp[-5].tn),(yyvsp[-2].tn));}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 137 "t3.y" /* yacc.c:1646  */
    {printf(" y49 ");(yyval.tn)=breaknode();}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 139 "t3.y" /* yacc.c:1646  */
    {printf(" y50 ");(yyval.tn)=continuenode();}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 141 "t3.y" /* yacc.c:1646  */
    {(yyval.tn)=retnode((yyvsp[-1].tn));}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 142 "t3.y" /* yacc.c:1646  */
    {(yyval.tn)=retnode(NULL);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 144 "t3.y" /* yacc.c:1646  */
    {printf(" y51 ");(yyval.tn)=relnode("<",(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 145 "t3.y" /* yacc.c:1646  */
    {printf(" y52 ");(yyval.tn)=relnode(">",(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 146 "t3.y" /* yacc.c:1646  */
    {printf(" y53 ");(yyval.tn)=relnode("<=",(yyvsp[-3].tn),(yyvsp[0].tn));}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 147 "t3.y" /* yacc.c:1646  */
    {printf(" y54 ");(yyval.tn)=relnode(">=",(yyvsp[-3].tn),(yyvsp[0].tn));}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 148 "t3.y" /* yacc.c:1646  */
    {printf(" y55 ");(yyval.tn)=relnode("!=",(yyvsp[-3].tn),(yyvsp[0].tn));}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 149 "t3.y" /* yacc.c:1646  */
    {printf(" y56 ");(yyval.tn)=relnode("==",(yyvsp[-3].tn),(yyvsp[0].tn));}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 151 "t3.y" /* yacc.c:1646  */
    {printf(" y57 ");(yyval.tn)=opnode('+',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 152 "t3.y" /* yacc.c:1646  */
    {printf(" y58 ");(yyval.tn)=opnode('*',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 153 "t3.y" /* yacc.c:1646  */
    {printf(" y59 ");(yyval.tn)=opnode('-',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 154 "t3.y" /* yacc.c:1646  */
    {printf(" y60 ");(yyval.tn)=opnode('/',(yyvsp[-2].tn),(yyvsp[0].tn));}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 155 "t3.y" /* yacc.c:1646  */
    {printf(" y61 ");(yyval.tn)=(yyvsp[-1].tn);}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 156 "t3.y" /* yacc.c:1646  */
    {printf(" y62 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 157 "t3.y" /* yacc.c:1646  */
    {printf(" y63 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 158 "t3.y" /* yacc.c:1646  */
    {printf(" y64 ");(yyval.tn)=(yyvsp[0].tn);}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 159 "t3.y" /* yacc.c:1646  */
    {printf(" y65 ");(yyval.tn)=(yyvsp[-2].tn);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 160 "t3.y" /* yacc.c:1646  */
    {printf(" y66 ");(yyvsp[-3].tn)->Arglist=(yyvsp[-1].tn);(yyval.tn)=(yyvsp[-3].tn);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1873 "y.tab.c" /* yacc.c:1646  */
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
#line 163 "t3.y" /* yacc.c:1906  */


int yyerror(char const *s)
{
  printf("yyerror %s",s);
}
int main()
{
  loopflag[0]=0;
  outputfile=fopen("input.xsm","w");
  Reg=(struct regpool *)malloc(sizeof(struct regpool));
  Reg->reg=-1;
  Reg->label=1;
  fprintf(outputfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP,4095\nMOV BP,4096\nPUSH R0\nCALL L0\nINT 10\n",0,2056,0,0,0,0,0,0);
  inp();
  yyparse();
  return 0;
}
