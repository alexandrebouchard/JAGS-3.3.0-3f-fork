/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     DATA = 259,
     MODEL = 260,
     NAME = 261,
     FUNC = 262,
     SPECIAL = 263,
     BADCHAR = 264,
     IN = 265,
     ARROW = 266,
     FOR = 267,
     GT = 268,
     GE = 269,
     LT = 270,
     LE = 271,
     EQ = 272,
     NE = 273,
     AND = 274,
     OR = 275,
     LENGTH = 276,
     DIM = 277,
     DOUBLE = 278,
     INT = 279,
     NOT = 280,
     NEG = 281,
     ENDL = 282,
     UREPCHAR = 283
   };
#endif
/* Tokens.  */
#define VAR 258
#define DATA 259
#define MODEL 260
#define NAME 261
#define FUNC 262
#define SPECIAL 263
#define BADCHAR 264
#define IN 265
#define ARROW 266
#define FOR 267
#define GT 268
#define GE 269
#define LT 270
#define LE 271
#define EQ 272
#define NE 273
#define AND 274
#define OR 275
#define LENGTH 276
#define DIM 277
#define DOUBLE 278
#define INT 279
#define NOT 280
#define NEG 281
#define ENDL 282
#define UREPCHAR 283




/* Copy the first part of user declarations.  */
#line 2 "parser.yy"

#include <compiler/ParseTree.h>
#include "remap.h"
#include "parser_extra.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

using std::malloc;
using std::free;
  
  void yyerror(const char *);
  int yylex();
  int yylex_destroy();
  extern int yylineno;
  
#define YYDEBUG 1
  
  static std::vector<ParseTree *> * _pvariables = 0;
  static ParseTree *_pdata = 0;
  static ParseTree *_prelations = 0;
  
  static void setName(ParseTree *p, std::string *name);
  static void printName(ParseTree *p);
  static void setParameters(ParseTree *p, std::vector<ParseTree*> *parameters);
  static void setParameters(ParseTree *p, ParseTree *param1);
  static void setParameters(ParseTree *p, ParseTree *param1, 
			    ParseTree *param2);
  static void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2,
			    ParseTree *param3);
  static ParseTree *Truncated (ParseTree *left, ParseTree *right);
  static ParseTree *Interval(ParseTree *left, ParseTree *right);
  

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 44 "parser.yy"
{
  /*
    We can't put any C++ class that requires a constructor in
    union. In particular, we can't have strings.  To get round this
    limitation, we put a pointer to a string in the union, and then
    get the lexical analyzer to return a pointer to a dynamically
    allocated string.  The parser frees the memory when it is done.
    This is tedious, but the alternative is to copy character
    arrays using, e.g. strncpy instead.
  */
  double val;
  std::string *stringptr;
  ParseTree *ptree;
  std::vector<ParseTree*> *pvec;
}
/* Line 193 of yacc.c.  */
#line 208 "parser.cc"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 221 "parser.cc"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    28,    26,    35,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    34,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,     2,     2,     2,     2,     2,
       2,    36,     2,    37,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,    42,     2,     2,     2,
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
      25,    30,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     9,    12,    16,    19,    23,
      25,    29,    31,    36,    38,    42,    47,    52,    56,    58,
      61,    63,    65,    67,    70,    73,    76,    83,    87,    94,
      98,   103,   108,   112,   116,   120,   124,   126,   128,   133,
     138,   143,   145,   149,   151,   155,   158,   162,   166,   170,
     174,   178,   182,   186,   190,   194,   198,   202,   204,   208,
     210,   214,   215,   217,   221,   226,   230,   237,   243,   249,
     254,   261,   267,   273,   278,   280
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    -1,    53,    -1,    48,    53,    -1,    52,
      53,    -1,    48,    52,    53,    -1,     3,    49,    -1,     3,
      49,    34,    -1,    50,    -1,    49,    35,    50,    -1,     6,
      -1,     6,    36,    51,    37,    -1,    63,    -1,    51,    35,
      63,    -1,     4,    38,    55,    39,    -1,     5,    38,    55,
      39,    -1,    38,    55,    39,    -1,    56,    -1,    55,    56,
      -1,    60,    -1,    59,    -1,    57,    -1,    60,    34,    -1,
      59,    34,    -1,    58,    54,    -1,    12,    40,     6,    10,
      66,    41,    -1,    70,    11,    63,    -1,     7,    40,    70,
      41,    11,    63,    -1,    70,    42,    67,    -1,    70,    42,
      67,    68,    -1,    70,    42,    67,    69,    -1,    63,    28,
      63,    -1,    61,    28,    63,    -1,    63,    26,    63,    -1,
      62,    26,    63,    -1,    70,    -1,    23,    -1,    21,    40,
      70,    41,    -1,    22,    40,    70,    41,    -1,     7,    40,
      64,    41,    -1,    61,    -1,    63,    29,    63,    -1,    62,
      -1,    63,    27,    63,    -1,    27,    63,    -1,    63,    13,
      63,    -1,    63,    14,    63,    -1,    63,    15,    63,    -1,
      63,    16,    63,    -1,    63,    17,    63,    -1,    63,    18,
      63,    -1,    63,    19,    63,    -1,    63,    20,    63,    -1,
      63,    31,    63,    -1,    63,     8,    63,    -1,    40,    63,
      41,    -1,    63,    -1,    64,    35,    63,    -1,    66,    -1,
      65,    35,    66,    -1,    -1,    63,    -1,    63,    43,    63,
      -1,     7,    40,    64,    41,    -1,     7,    40,    41,    -1,
      44,    40,    63,    35,    63,    41,    -1,    44,    40,    35,
      63,    41,    -1,    44,    40,    63,    35,    41,    -1,    44,
      40,    35,    41,    -1,    45,    40,    63,    35,    63,    41,
      -1,    45,    40,    35,    63,    41,    -1,    45,    40,    63,
      35,    41,    -1,    45,    40,    35,    41,    -1,     6,    -1,
       6,    36,    65,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   106,   107,   108,   109,   112,   113,   116,
     117,   120,   123,   129,   130,   133,   140,   147,   153,   154,
     157,   158,   159,   160,   161,   164,   170,   176,   181,   199,
     204,   209,   216,   221,   231,   236,   245,   246,   247,   251,
     255,   259,   263,   267,   271,   275,   279,   283,   287,   291,
     295,   299,   303,   307,   311,   315,   319,   322,   323,   326,
     327,   330,   331,   332,   337,   342,   349,   350,   351,   352,
     355,   356,   357,   358,   361,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "DATA", "MODEL", "NAME", "FUNC",
  "SPECIAL", "BADCHAR", "IN", "ARROW", "FOR", "GT", "GE", "LT", "LE", "EQ",
  "NE", "AND", "OR", "LENGTH", "DIM", "DOUBLE", "INT", "NOT", "'+'", "'-'",
  "'*'", "'/'", "NEG", "'^'", "ENDL", "UREPCHAR", "';'", "','", "'['",
  "']'", "'{'", "'}'", "'('", "')'", "'~'", "':'", "'T'", "'I'", "$accept",
  "input", "var_stmt", "dec_list", "node_dec", "dim_list", "data_stmt",
  "model_stmt", "relations", "relation_list", "relation", "for_loop",
  "counter", "determ_relation", "stoch_relation", "product", "sum",
  "expression", "expression_list", "range_list", "range_element",
  "distribution", "truncated", "interval", "var", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    43,    45,    42,    47,
     281,    94,   282,   283,    59,    44,    91,    93,   123,   125,
      40,    41,   126,    58,    84,    73
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    53,    54,    55,    55,
      56,    56,    56,    56,    56,    57,    58,    59,    59,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    69,    69,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     2,     3,     2,     3,     1,
       3,     1,     4,     1,     3,     4,     4,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     6,     3,     6,     3,
       4,     4,     3,     3,     3,     3,     1,     1,     4,     4,
       4,     1,     3,     1,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     0,     1,     3,     4,     3,     6,     5,     5,     4,
       6,     5,     5,     4,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     3,    11,     7,
       9,     0,     0,     1,     0,     4,     5,     0,     8,     0,
      74,     0,     0,     0,    18,    22,     0,    21,    20,     0,
       0,     6,     0,     0,     0,    37,     0,     0,     0,    41,
      43,    13,    36,    10,    61,     0,     0,    15,    19,     0,
      25,    24,    23,     0,     0,    16,     0,     0,     0,    45,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,    59,     0,     0,     0,    27,     0,    29,    57,     0,
       0,     0,    56,    14,    33,    35,    55,    46,    47,    48,
      49,    50,    51,    52,    53,    34,    44,    32,    42,    54,
       0,    61,    75,     0,    61,    17,     0,     0,     0,    30,
      31,     0,    40,    38,    39,    63,    60,     0,     0,    65,
       0,     0,     0,    58,    28,    26,    64,     0,     0,     0,
       0,    69,     0,     0,    73,     0,     0,    67,    68,     0,
      71,    72,     0,    66,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     9,    10,    38,     6,     7,    50,    23,
      24,    25,    26,    27,    28,    39,    40,    79,    89,    80,
      81,    87,   119,   120,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -108
static const yytype_int16 yypact[] =
{
     142,    24,    -4,    35,    94,     4,    92,  -108,    67,    42,
    -108,    63,    63,  -108,    92,  -108,  -108,   182,  -108,    24,
      77,    78,    81,    59,  -108,  -108,    85,   100,   102,    -9,
      73,  -108,    90,   109,   112,  -108,   182,   182,   -14,   128,
     131,   391,  -108,  -108,   182,   152,   154,  -108,  -108,    63,
    -108,  -108,  -108,   182,   158,  -108,   182,   152,   152,   137,
     198,   182,  -108,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,    -2,
       0,  -108,   129,   159,    80,   391,   134,    96,   391,    37,
     130,   135,  -108,   391,    -3,    14,   137,   435,   435,   435,
     435,   435,   435,   457,   413,    14,    14,    -3,    -3,   137,
     182,   182,  -108,   164,   182,  -108,    61,   145,   146,  -108,
    -108,   182,  -108,  -108,  -108,   391,  -108,   182,   136,  -108,
      54,   157,   160,   391,   391,  -108,  -108,    84,   343,   110,
     367,  -108,   227,   121,  -108,   256,   132,  -108,  -108,   285,
    -108,  -108,   314,  -108,  -108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,  -108,   171,  -108,   186,    26,  -108,   -11,
     -20,  -108,  -108,  -108,  -108,  -108,  -108,   -17,    82,  -108,
    -107,  -108,  -108,  -108,    51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      41,    30,    53,    48,   126,    65,    65,   128,     2,     3,
      48,    66,    67,    68,    69,    70,    71,    72,    73,    59,
      60,    61,    65,    62,    74,    75,    76,    77,    78,    78,
       8,    15,    16,    54,    11,   111,    85,   112,    84,    88,
      31,   110,    76,    77,    93,    78,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    29,    29,    48,    20,    21,    20,    32,    20,
      21,    22,   121,    12,    29,    22,    18,    19,   122,    20,
      21,    29,    33,    34,    35,    22,    20,    21,    36,   121,
      20,    32,    22,   125,    13,   136,    82,     3,    47,    88,
      29,    37,   129,    17,   133,    33,    34,    35,    90,    91,
     134,    36,    55,    44,   138,   140,    20,    32,    45,   115,
     142,    46,   145,    49,    37,   141,   149,    20,    32,   152,
      56,    33,    34,    35,    51,    29,    52,    36,    20,    32,
     117,   118,    33,    34,    35,     1,     2,     3,    36,    57,
      37,   144,    58,    33,    34,    35,    63,    64,    20,    36,
      83,    37,   148,    20,    32,    86,    20,    32,    78,   114,
     113,   123,    37,   151,   116,   127,   124,   135,    33,    34,
      35,    33,    34,    35,    36,   131,   132,    36,    20,    32,
      43,    14,   137,     0,     0,   139,     0,    37,   130,     0,
      37,     0,     0,    33,    34,    35,    65,     0,     0,    36,
       0,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     0,    37,     0,    74,    75,    76,    77,     0,    78,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    92,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
       0,     0,     0,    74,    75,    76,    77,     0,    78,     0,
       0,     0,     0,     0,    65,     0,     0,     0,   147,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,    74,    75,    76,    77,     0,    78,     0,     0,
       0,     0,     0,    65,     0,     0,     0,   150,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,    74,    75,    76,    77,     0,    78,     0,     0,     0,
       0,     0,    65,     0,     0,     0,   153,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,     0,     0,
      74,    75,    76,    77,     0,    78,     0,     0,     0,     0,
       0,    65,     0,     0,     0,   154,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,    74,
      75,    76,    77,     0,    78,    65,     0,     0,   143,     0,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
       0,     0,     0,    74,    75,    76,    77,     0,    78,    65,
       0,     0,   146,     0,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    65,    78,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    65,    78,     0,     0,     0,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    65,    78,     0,     0,     0,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,     0,    78
};

static const yytype_int16 yycheck[] =
{
      17,    12,    11,    23,   111,     8,     8,   114,     4,     5,
      30,    13,    14,    15,    16,    17,    18,    19,    20,    36,
      37,    35,     8,    37,    26,    27,    28,    29,    31,    31,
       6,     5,     6,    42,    38,    35,    53,    37,    49,    56,
      14,    43,    28,    29,    61,    31,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    11,    12,    84,     6,     7,     6,     7,     6,
       7,    12,    35,    38,    23,    12,    34,    35,    41,     6,
       7,    30,    21,    22,    23,    12,     6,     7,    27,    35,
       6,     7,    12,   110,     0,    41,    45,     5,    39,   116,
      49,    40,    41,    36,   121,    21,    22,    23,    57,    58,
     127,    27,    39,    36,   131,   132,     6,     7,    40,    39,
     137,    40,   139,    38,    40,    41,   143,     6,     7,   146,
      40,    21,    22,    23,    34,    84,    34,    27,     6,     7,
      44,    45,    21,    22,    23,     3,     4,     5,    27,    40,
      40,    41,    40,    21,    22,    23,    28,    26,     6,    27,
       6,    40,    41,     6,     7,     7,     6,     7,    31,    10,
      41,    41,    40,    41,    40,    11,    41,    41,    21,    22,
      23,    21,    22,    23,    27,    40,    40,    27,     6,     7,
      19,     5,    35,    -1,    -1,    35,    -1,    40,   116,    -1,
      40,    -1,    -1,    21,    22,    23,     8,    -1,    -1,    27,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    40,    -1,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    41,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    41,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    41,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    41,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    41,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    31,     8,    -1,    -1,    35,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    31,     8,
      -1,    -1,    35,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,     8,    31,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,     8,    31,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,     8,    31,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    47,    48,    52,    53,     6,    49,
      50,    38,    38,     0,    52,    53,    53,    36,    34,    35,
       6,     7,    12,    55,    56,    57,    58,    59,    60,    70,
      55,    53,     7,    21,    22,    23,    27,    40,    51,    61,
      62,    63,    70,    50,    36,    40,    40,    39,    56,    38,
      54,    34,    34,    11,    42,    39,    40,    40,    40,    63,
      63,    35,    37,    28,    26,     8,    13,    14,    15,    16,
      17,    18,    19,    20,    26,    27,    28,    29,    31,    63,
      65,    66,    70,     6,    55,    63,     7,    67,    63,    64,
      70,    70,    41,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      43,    35,    37,    41,    10,    39,    40,    44,    45,    68,
      69,    35,    41,    41,    41,    63,    66,    11,    66,    41,
      64,    40,    40,    63,    63,    41,    41,    35,    63,    35,
      63,    41,    63,    35,    41,    63,    35,    41,    41,    63,
      41,    41,    63,    41,    41
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
#line 112 "parser.yy"
    { _pvariables = (yyvsp[(2) - (2)].pvec); }
    break;

  case 8:
#line 113 "parser.yy"
    { _pvariables = (yyvsp[(2) - (3)].pvec); }
    break;

  case 9:
#line 116 "parser.yy"
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[(1) - (1)].ptree)); }
    break;

  case 10:
#line 117 "parser.yy"
    { (yyval.pvec) = (yyvsp[(1) - (3)].pvec); (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree)); }
    break;

  case 11:
#line 120 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_VAR, yylineno); setName((yyval.ptree), (yyvsp[(1) - (1)].stringptr)); 
}
    break;

  case 12:
#line 123 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_VAR, yylineno); setName((yyval.ptree), (yyvsp[(1) - (4)].stringptr));
    setParameters((yyval.ptree), (yyvsp[(3) - (4)].pvec));
}
    break;

  case 13:
#line 129 "parser.yy"
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[(1) - (1)].ptree)); }
    break;

  case 14:
#line 130 "parser.yy"
    { (yyval.pvec)=(yyvsp[(1) - (3)].pvec); (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree)); }
    break;

  case 15:
#line 133 "parser.yy"
    {
    ParseTree *p = new ParseTree(P_RELATIONS, yylineno);
    setParameters(p, (yyvsp[(3) - (4)].pvec));
    _pdata = p;
}
    break;

  case 16:
#line 140 "parser.yy"
    { 
    ParseTree *p = new ParseTree(P_RELATIONS, yylineno);
    setParameters(p, (yyvsp[(3) - (4)].pvec));
    _prelations = p;
}
    break;

  case 17:
#line 147 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_RELATIONS, yylineno);
    setParameters((yyval.ptree), (yyvsp[(2) - (3)].pvec));
}
    break;

  case 18:
#line 153 "parser.yy"
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[(1) - (1)].ptree)); }
    break;

  case 19:
#line 154 "parser.yy"
    { (yyval.pvec)=(yyvsp[(1) - (2)].pvec); (yyval.pvec)->push_back((yyvsp[(2) - (2)].ptree)); }
    break;

  case 25:
#line 164 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FOR, yylineno);
    setParameters((yyval.ptree), (yyvsp[(1) - (2)].ptree), (yyvsp[(2) - (2)].ptree));
}
    break;

  case 26:
#line 170 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_COUNTER, yylineno); setName((yyval.ptree), (yyvsp[(3) - (6)].stringptr));
    setParameters((yyval.ptree), (yyvsp[(5) - (6)].ptree));
}
    break;

  case 27:
#line 176 "parser.yy"
    {
    printName((yyvsp[(1) - (3)].ptree));
    (yyval.ptree) = new ParseTree(P_DETRMREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
}
    break;

  case 28:
#line 181 "parser.yy"
    {

    printName((yyvsp[(3) - (6)].ptree));

  /* 
     The link function is given using an S-style replacement function
     notation.  We need to turn this round so the inverse link
     function is applied to the RHS of the deterministic relation
  */
     
    ParseTree *p = new ParseTree(P_LINK, yylineno); setName(p, (yyvsp[(1) - (6)].stringptr));
    setParameters(p, (yyvsp[(6) - (6)].ptree));
    
    (yyval.ptree) = new ParseTree(P_DETRMREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[(3) - (6)].ptree), p);
}
    break;

  case 29:
#line 199 "parser.yy"
    {
    printName((yyvsp[(1) - (3)].ptree));
    (yyval.ptree) = new ParseTree(P_STOCHREL, yylineno); 
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
 }
    break;

  case 30:
#line 204 "parser.yy"
    {
    printName((yyvsp[(1) - (4)].ptree));
    (yyval.ptree) = new ParseTree(P_STOCHREL, yylineno); 
    setParameters((yyval.ptree), (yyvsp[(1) - (4)].ptree), (yyvsp[(3) - (4)].ptree), (yyvsp[(4) - (4)].ptree));
}
    break;

  case 31:
#line 209 "parser.yy"
    {
    printName((yyvsp[(1) - (4)].ptree));
    (yyval.ptree) = new ParseTree(P_STOCHREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[(1) - (4)].ptree), (yyvsp[(3) - (4)].ptree), (yyvsp[(4) - (4)].ptree));
}
    break;

  case 32:
#line 216 "parser.yy"
    {
  (yyval.pvec) = new std::vector<ParseTree*>;
  (yyval.pvec)->push_back((yyvsp[(1) - (3)].ptree));
  (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree));
}
    break;

  case 33:
#line 221 "parser.yy"
    {
  //  This creates a shift-reduce conflict because in the expression
  //  A*B*C, (A*B) is a valid expression. By default, bison shifts,
  //  which is what we want. The warning is suppressed with the %expect
  //  declaration (See also sum: below).
  (yyval.pvec) = (yyvsp[(1) - (3)].pvec);
  (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree));
}
    break;

  case 34:
#line 231 "parser.yy"
    {
  (yyval.pvec) = new std::vector<ParseTree*>;
  (yyval.pvec)->push_back((yyvsp[(1) - (3)].ptree));
  (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree));
}
    break;

  case 35:
#line 236 "parser.yy"
    {
  //  This creates a shift-reduce conflict. By default, bison shifts,
  //  which is what we want. The warning is suppressed with the %expect
  //  declaration (See also product: above).
  (yyval.pvec) = (yyvsp[(1) - (3)].pvec);
  (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree));
}
    break;

  case 37:
#line 246 "parser.yy"
    {(yyval.ptree) = new ParseTree(P_VALUE, yylineno); (yyval.ptree)->setValue((yyvsp[(1) - (1)].val));}
    break;

  case 38:
#line 247 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_LENGTH, yylineno);
    setParameters((yyval.ptree),(yyvsp[(3) - (4)].ptree));
}
    break;

  case 39:
#line 251 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_DIM, yylineno);
    setParameters((yyval.ptree),(yyvsp[(3) - (4)].ptree));
}
    break;

  case 40:
#line 255 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); setName((yyval.ptree), (yyvsp[(1) - (4)].stringptr));
  setParameters((yyval.ptree), (yyvsp[(3) - (4)].pvec));
}
    break;

  case 41:
#line 259 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("*");
    setParameters((yyval.ptree), (yyvsp[(1) - (1)].pvec));
}
    break;

  case 42:
#line 263 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("/");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
}
    break;

  case 43:
#line 267 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("+");
    setParameters((yyval.ptree), (yyvsp[(1) - (1)].pvec));
}
    break;

  case 44:
#line 271 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("-");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
}
    break;

  case 45:
#line 275 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("NEG");
    setParameters((yyval.ptree), (yyvsp[(2) - (2)].ptree));
}
    break;

  case 46:
#line 279 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName(">");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
 }
    break;

  case 47:
#line 283 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName(">=");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
 }
    break;

  case 48:
#line 287 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("<");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
 }
    break;

  case 49:
#line 291 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("<=");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
 }
    break;

  case 50:
#line 295 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("==");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
 }
    break;

  case 51:
#line 299 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("!=");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
}
    break;

  case 52:
#line 303 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("&&");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
 }
    break;

  case 53:
#line 307 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("||");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
}
    break;

  case 54:
#line 311 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); (yyval.ptree)->setName("^");
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
  }
    break;

  case 55:
#line 315 "parser.yy"
    {
    (yyval.ptree) = new ParseTree(P_FUNCTION, yylineno); setName((yyval.ptree), (yyvsp[(2) - (3)].stringptr));
    setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
 }
    break;

  case 56:
#line 319 "parser.yy"
    { (yyval.ptree) = (yyvsp[(2) - (3)].ptree); }
    break;

  case 57:
#line 322 "parser.yy"
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[(1) - (1)].ptree)); }
    break;

  case 58:
#line 323 "parser.yy"
    { (yyval.pvec)=(yyvsp[(1) - (3)].pvec); (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree)); }
    break;

  case 59:
#line 326 "parser.yy"
    { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[(1) - (1)].ptree)); }
    break;

  case 60:
#line 327 "parser.yy"
    { (yyval.pvec)=(yyvsp[(1) - (3)].pvec); (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree)); }
    break;

  case 61:
#line 330 "parser.yy"
    {(yyval.ptree) = new ParseTree(P_RANGE, yylineno);}
    break;

  case 62:
#line 331 "parser.yy"
    {(yyval.ptree) = new ParseTree(P_RANGE, yylineno); setParameters((yyval.ptree),(yyvsp[(1) - (1)].ptree));}
    break;

  case 63:
#line 332 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_RANGE, yylineno); setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
}
    break;

  case 64:
#line 338 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_DENSITY, yylineno); setName((yyval.ptree), (yyvsp[(1) - (4)].stringptr));
  setParameters((yyval.ptree), (yyvsp[(3) - (4)].pvec));
}
    break;

  case 65:
#line 343 "parser.yy"
    {
    //BUGS has a dflat() distribution with no parameters
    (yyval.ptree) = new ParseTree(P_DENSITY, yylineno); setName((yyval.ptree), (yyvsp[(1) - (3)].stringptr));
}
    break;

  case 66:
#line 349 "parser.yy"
    {(yyval.ptree) = Truncated((yyvsp[(3) - (6)].ptree),(yyvsp[(5) - (6)].ptree));}
    break;

  case 67:
#line 350 "parser.yy"
    {(yyval.ptree) = Truncated(0,(yyvsp[(4) - (5)].ptree));}
    break;

  case 68:
#line 351 "parser.yy"
    {(yyval.ptree) = Truncated((yyvsp[(3) - (5)].ptree),0);}
    break;

  case 69:
#line 352 "parser.yy"
    {(yyval.ptree) = Truncated(0,0);}
    break;

  case 70:
#line 355 "parser.yy"
    {(yyval.ptree) = Interval((yyvsp[(3) - (6)].ptree),(yyvsp[(5) - (6)].ptree));}
    break;

  case 71:
#line 356 "parser.yy"
    {(yyval.ptree) = Interval(0,(yyvsp[(4) - (5)].ptree));}
    break;

  case 72:
#line 357 "parser.yy"
    {(yyval.ptree) = Interval((yyvsp[(3) - (5)].ptree),0);}
    break;

  case 73:
#line 358 "parser.yy"
    {(yyval.ptree) = Interval(0,0);}
    break;

  case 74:
#line 361 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_VAR, yylineno); setName((yyval.ptree), (yyvsp[(1) - (1)].stringptr));
}
    break;

  case 75:
#line 364 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_VAR, yylineno); setName((yyval.ptree), (yyvsp[(1) - (4)].stringptr));
  setParameters((yyval.ptree), (yyvsp[(3) - (4)].pvec));
}
    break;


/* Line 1267 of yacc.c.  */
#line 2072 "parser.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 370 "parser.yy"


static std::string error_buf;

void yyerror (const char *s)
{
    extern char * yytext;
    extern int yylineno;

    std::ostringstream msg;
    msg << std::string(s) << " on line " << yylineno << " near \"" << 
           std::string(yytext) << "\"";
    error_buf = msg.str();
}

static ParseTree *Truncated (ParseTree *left, ParseTree *right)
{
    //JAGS-Style truncation notation
    ParseTree *p = new ParseTree(P_BOUNDS, yylineno);
    setParameters(p, left, right);
    return p;
}

static ParseTree *Interval (ParseTree *left, ParseTree *right)
{
    //BUGS-Style interval censoring notation
    ParseTree *p = new ParseTree(P_INTERVAL, yylineno);
    setParameters(p, left, right);
    return p;
}

void setName(ParseTree *p, std::string *name)
{
  /* 
     The scanner cannot return a string, because a string cannot be
     part of a union.  So instead the scanner returns a pointer to
     a newly allocated string.  This memory must be freed as soon
     as it is used.
  */
  p->setName(*name);
  delete name;
}

void printName(ParseTree *p)
{
    cout << "variable: " << p->name() << "\n";
}
	

void setParameters(ParseTree *p, std::vector<ParseTree*> *parameters)
{
  /* 
     Same as setName (above).  The parser dynamically allocates
     vectors of (pointers to) parameters. These vectors must be
     deleted when we are done with them.
  */
  p->setParameters(*parameters);
  delete parameters; 
}

void setParameters(ParseTree *p, ParseTree *param1)
{
  /*
    Wrapper function that creates a vector containing param1
    to be passed to ParseTree::setParameters.
  */
  std::vector<ParseTree *> parameters(1, param1);
  p->setParameters(parameters);
}

void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2)
{
  /*
    Wrapper function that creates a vector containing param1
    and param2, to be passed to ParseTree::setParameters
  */
  std::vector<ParseTree *> parameters;
  parameters.push_back(param1);
  parameters.push_back(param2);
  p->setParameters(parameters);
}

void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2,
		   ParseTree *param3)
{
  /*
    Wrapper function that creates a vector containing param1, param2
    and param3, to be passed to ParseTree::setParameters
  */
  std::vector<ParseTree *> parameters;
  parameters.push_back(param1);
  parameters.push_back(param2);
  parameters.push_back(param3);
  p->setParameters(parameters);
}

int parse_bugs (std::FILE *file, std::vector<ParseTree*> * &dec_list, 
                ParseTree * &data, ParseTree * &relations,
		std::string &message)
{
    extern std::FILE *yyin;
    yyin = file;
    
    int val = 0;
    error_buf.clear();

    if (yyparse() == 0) {
	dec_list = _pvariables; 
	data = _pdata; 
	relations = _prelations;
    }
    else {
	message = error_buf;
	delete _pvariables; 
	delete _prelations; 
	delete _pdata;
	val = 1;
    }
    _pvariables = 0;
    _prelations = 0;
    _pdata = 0;

    yylex_destroy();

    return val;
}

