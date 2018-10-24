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
     DIV_ASSIGN = 258,
     MUL_ASSIGN = 259,
     MINUS_ASSIGN = 260,
     PLUS_ASSIGN = 261,
     LOGICAL_OR = 262,
     LOGICAL_AND = 263,
     NOT_EQUAL = 264,
     EQUAL = 265,
     GREATER_OR_EQUAL = 266,
     LESS_OR_EQUAL = 267,
     UMINUS = 268,
     IDENTIFER = 269,
     INTEGER = 270,
     IDENTIFIER = 271,
     WHILE = 272,
     IF = 273,
     ELSE = 274,
     TRUE = 275,
     FALSE = 276,
     MAIN = 277,
     SWITCH = 278,
     CASE = 279,
     DEFAULT = 280,
     BREAK = 281,
     INT = 282
   };
#endif
/* Tokens.  */
#define DIV_ASSIGN 258
#define MUL_ASSIGN 259
#define MINUS_ASSIGN 260
#define PLUS_ASSIGN 261
#define LOGICAL_OR 262
#define LOGICAL_AND 263
#define NOT_EQUAL 264
#define EQUAL 265
#define GREATER_OR_EQUAL 266
#define LESS_OR_EQUAL 267
#define UMINUS 268
#define IDENTIFER 269
#define INTEGER 270
#define IDENTIFIER 271
#define WHILE 272
#define IF 273
#define ELSE 274
#define TRUE 275
#define FALSE 276
#define MAIN 277
#define SWITCH 278
#define CASE 279
#define DEFAULT 280
#define BREAK 281
#define INT 282




/* Copy the first part of user declarations.  */
#line 1 "grammer.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=1; //count for number of temporary variables
char* code[1000];
int next_inst=1;
char fill_label[10];
char* case_inst[20][2];  // used in switch case 
int no_of_cases=0;       // no of cases in switch case
int no_of_defaults=0;       // no of defaults in switch case , error if more than 1
char* identifiers[100];
int no_of_identifiers=0;

struct list
{
	int inst_no;
	struct list *next;
};


struct list * makelist(int next_inst);
struct list * merge(struct list * l1,struct list * l2);
void backpatch(struct list* l,int target_inst);
char* new_temp();
void print_code();
void declare(char* id);
int isdeclared(char* id);



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
#line 33 "grammer.y"
{
	union 
	{
	
		int inst;
		char* addr;
		struct list* nextlist;	
		struct
		{
			struct list* truelist;
			struct list* falselist;
		};
	}
	info;
}
/* Line 193 of yacc.c.  */
#line 197 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 210 "y.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   344

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,     2,     2,    24,    13,     2,
      29,    30,    22,    20,     3,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    47,
      18,     8,    16,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    12,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    11,    46,    26,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     9,    10,    14,    15,    17,    19,    27,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    14,    25,    33,    43,    47,    50,
      52,    55,    59,    63,    65,    71,    75,    82,    88,    94,
      98,   100,   105,   110,   113,   117,   121,   125,   129,   133,
     137,   141,   143,   145,   146,   147,   152,   157,   162,   167,
     172,   176,   180,   184,   188,   192,   196,   200,   204,   208,
     212,   215,   218,   220
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    39,    51,    56,    -1,    35,    29,    55,
      30,    56,    51,    -1,    35,    29,    55,    30,    56,    51,
      36,    57,    56,    51,    -1,    34,    56,    29,    55,    30,
      56,    51,    -1,    40,    29,    59,    30,    57,    45,    53,
      46,    56,    -1,    45,    54,    46,    -1,    45,    46,    -1,
      58,    -1,    43,    47,    -1,    44,    52,    47,    -1,    52,
       3,    33,    -1,    33,    -1,    52,     3,    33,     8,    59,
      -1,    33,     8,    59,    -1,    53,    41,    59,    48,    56,
      51,    -1,    53,    42,    48,    56,    51,    -1,    41,    59,
      48,    56,    51,    -1,    54,    56,    51,    -1,    51,    -1,
      55,     9,    56,    55,    -1,    55,    10,    56,    55,    -1,
      25,    55,    -1,    29,    55,    30,    -1,    59,    15,    59,
      -1,    59,    14,    59,    -1,    59,    17,    59,    -1,    59,
      19,    59,    -1,    59,    18,    59,    -1,    59,    16,    59,
      -1,    37,    -1,    38,    -1,    -1,    -1,    33,     8,    59,
      47,    -1,    33,     7,    59,    47,    -1,    33,     6,    59,
      47,    -1,    33,     5,    59,    47,    -1,    33,     4,    59,
      47,    -1,    59,    20,    59,    -1,    59,    21,    59,    -1,
      59,    22,    59,    -1,    59,    23,    59,    -1,    59,    24,
      59,    -1,    59,    28,    59,    -1,    59,    13,    59,    -1,
      59,    12,    59,    -1,    59,    11,    59,    -1,    29,    59,
      30,    -1,    26,    59,    -1,    21,    59,    -1,    32,    -1,
      33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    82,    88,    97,   113,   146,   151,   156,
     161,   169,   178,   183,   189,   194,   199,   210,   228,   239,
     246,   254,   261,   268,   274,   280,   297,   316,   335,   351,
     368,   386,   396,   409,   415,   425,   438,   449,   460,   472,
     487,   496,   505,   514,   524,   535,   544,   554,   564,   574,
     580,   589,   598,   603
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "','", "DIV_ASSIGN", "MUL_ASSIGN",
  "MINUS_ASSIGN", "PLUS_ASSIGN", "'='", "LOGICAL_OR", "LOGICAL_AND", "'|'",
  "'^'", "'&'", "NOT_EQUAL", "EQUAL", "'>'", "GREATER_OR_EQUAL", "'<'",
  "LESS_OR_EQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "UMINUS", "'@'", "'('", "')'", "IDENTIFER", "INTEGER", "IDENTIFIER",
  "WHILE", "IF", "ELSE", "TRUE", "FALSE", "MAIN", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "INT", "'{'", "'}'", "';'", "':'", "$accept",
  "start", "S", "list", "cases", "L", "B", "M", "N", "assignment", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    44,   258,   259,   260,   261,    61,   262,
     263,   124,    94,    38,   264,   265,    62,   266,    60,   267,
      43,    45,    42,    47,    37,    33,   126,   268,    64,    40,
      41,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   123,   125,    59,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     6,    10,     7,     9,     3,     2,     1,
       2,     3,     3,     1,     5,     3,     6,     5,     5,     3,
       1,     4,     4,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     0,     0,     4,     4,     4,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
      33,     9,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    13,     0,     8,    20,    33,     2,     0,     0,
       0,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,    11,     7,
       0,    51,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    38,    37,    36,    35,     0,    23,
       0,     0,    33,    33,    33,     0,     0,     0,     0,     0,
       0,    34,    15,    12,    19,    49,    48,    47,    46,    40,
      41,    42,    43,    44,    45,    33,    24,     0,     0,     0,
      26,    25,    30,    27,    29,    28,     0,     0,     0,    21,
      22,     3,     0,    14,     5,    34,     0,     0,    33,     0,
       0,     0,    33,     0,    33,     0,    33,     6,     4,     0,
      33,     0,    18,     0,    17,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    10,    23,   117,    26,    43,    18,   106,    11,
      44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int16 yypact[] =
{
     -37,   120,     7,   139,   -55,   -21,    -8,   -27,    -6,   290,
     -55,   -55,   -55,   311,   311,   311,   311,   311,    -1,   277,
     311,   -55,    26,    -2,   -55,   -55,     0,   -55,   311,   311,
     311,   -55,   -55,   128,   146,   160,   174,   188,   277,   277,
     277,   -55,   -55,     5,   259,   202,   311,     6,   -55,   -55,
     120,    12,    12,   239,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   -55,   -55,   -55,   -55,   -55,     8,   -55,
      13,   225,   -55,   -55,   -55,   311,   311,   311,   311,   311,
     311,   -55,   273,    36,   -55,   -55,    74,   298,     9,    85,
      85,    12,    12,    12,    12,   -55,   -55,   277,   277,   120,
     273,   273,   273,   273,   273,   273,     2,   311,   120,    38,
     -55,    23,    19,   273,   -55,   -55,   311,    87,   -55,    57,
     311,     1,   -55,   120,   -55,   114,   -55,   -55,   -55,   120,
     -55,   120,   -55,   120,   -55,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,    -9,   -55,   -55,   -55,   -34,    -7,   -54,   -55,
      -4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      25,    47,     1,    27,    68,    69,    70,    12,    19,    33,
      34,    35,    36,    37,    72,    73,    45,    72,    73,    50,
      21,    20,    72,    73,    51,    52,    53,    22,    38,    57,
      58,    59,    60,    61,    46,    74,    71,    62,    95,    83,
      62,    84,    82,    96,   107,    48,    49,   112,    73,   126,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   115,
     116,   118,     0,   109,   110,    97,    98,    99,    54,    55,
      56,   100,   101,   102,   103,   104,   105,    57,    58,    59,
      60,    61,     0,     0,     0,    62,    55,    56,   108,     0,
     111,     0,     0,     0,    57,    58,    59,    60,    61,   114,
       0,     0,    62,   113,     0,   124,     0,    59,    60,    61,
       0,   123,   119,    62,   128,   127,   125,   129,     0,   131,
     132,     0,   134,   133,   135,    54,    55,    56,   120,   121,
       0,     0,     0,   122,    57,    58,    59,    60,    61,    54,
      55,    56,    62,    13,    14,    15,    16,    17,    57,    58,
      59,    60,    61,     3,     4,     5,    62,    54,    55,    56,
       6,     0,   130,     7,     8,     9,    57,    58,    59,    60,
      61,    54,    55,    56,    62,    63,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    54,    55,    56,    62,     0,
       0,     0,     0,    64,    57,    58,    59,    60,    61,    54,
      55,    56,    62,     0,     0,     0,     0,    65,    57,    58,
      59,    60,    61,    54,    55,    56,    62,     0,     0,     0,
       0,    66,    57,    58,    59,    60,    61,     0,     0,     0,
      62,     0,    81,     0,     0,    67,    54,    55,    56,    75,
      76,    77,    78,    79,    80,    57,    58,    59,    60,    61,
      54,    55,    56,    62,     0,    85,     0,     0,     0,    57,
      58,    59,    60,    61,     0,     0,     0,    62,     0,    85,
      54,    55,    56,    75,    76,    77,    78,    79,    80,    57,
      58,    59,    60,    61,    54,    55,    56,    62,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    28,     0,
       0,    62,    39,    29,     0,     0,    40,     0,     0,    31,
      32,    56,     0,     0,    41,    42,     0,     0,    57,    58,
      59,    60,    61,     3,     4,     5,    62,     0,     0,     0,
       6,     0,    28,     7,     8,     9,    24,    29,     0,     0,
      30,     0,     0,    31,    32
};

static const yytype_int16 yycheck[] =
{
       9,     3,    39,    10,    38,    39,    40,     0,    29,    13,
      14,    15,    16,    17,     9,    10,    20,     9,    10,    26,
      47,    29,     9,    10,    28,    29,    30,    33,    29,    20,
      21,    22,    23,    24,     8,    30,    40,    28,    30,    33,
      28,    50,    46,    30,     8,    47,    46,    45,    10,    48,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    36,
      41,   115,    -1,    97,    98,    72,    73,    74,    11,    12,
      13,    75,    76,    77,    78,    79,    80,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    12,    13,    95,    -1,
      99,    -1,    -1,    -1,    20,    21,    22,    23,    24,   108,
      -1,    -1,    28,   107,    -1,    48,    -1,    22,    23,    24,
      -1,   118,   116,    28,   123,   122,   120,   124,    -1,   126,
     129,    -1,   131,   130,   133,    11,    12,    13,    41,    42,
      -1,    -1,    -1,    46,    20,    21,    22,    23,    24,    11,
      12,    13,    28,     4,     5,     6,     7,     8,    20,    21,
      22,    23,    24,    33,    34,    35,    28,    11,    12,    13,
      40,    -1,    48,    43,    44,    45,    20,    21,    22,    23,
      24,    11,    12,    13,    28,    47,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    11,    12,    13,    28,    -1,
      -1,    -1,    -1,    47,    20,    21,    22,    23,    24,    11,
      12,    13,    28,    -1,    -1,    -1,    -1,    47,    20,    21,
      22,    23,    24,    11,    12,    13,    28,    -1,    -1,    -1,
      -1,    47,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    -1,    30,    -1,    -1,    47,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      11,    12,    13,    28,    -1,    30,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    11,    12,    13,    28,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    21,    -1,
      -1,    28,    25,    26,    -1,    -1,    29,    -1,    -1,    32,
      33,    13,    -1,    -1,    37,    38,    -1,    -1,    20,    21,
      22,    23,    24,    33,    34,    35,    28,    -1,    -1,    -1,
      40,    -1,    21,    43,    44,    45,    46,    26,    -1,    -1,
      29,    -1,    -1,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    50,    33,    34,    35,    40,    43,    44,    45,
      51,    58,     0,     4,     5,     6,     7,     8,    56,    29,
      29,    47,    33,    52,    46,    51,    54,    56,    21,    26,
      29,    32,    33,    59,    59,    59,    59,    59,    29,    25,
      29,    37,    38,    55,    59,    59,     8,     3,    47,    46,
      56,    59,    59,    59,    11,    12,    13,    20,    21,    22,
      23,    24,    28,    47,    47,    47,    47,    47,    55,    55,
      55,    59,     9,    10,    30,    14,    15,    16,    17,    18,
      19,    30,    59,    33,    51,    30,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    30,    30,    56,    56,    56,
      59,    59,    59,    59,    59,    59,    57,     8,    56,    55,
      55,    51,    45,    59,    51,    36,    41,    53,    57,    59,
      41,    42,    46,    56,    48,    59,    48,    56,    51,    56,
      48,    56,    51,    56,    51,    51
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
        case 2:
#line 75 "grammer.y"
    {
				backpatch((yyvsp[(2) - (3)].info).nextlist,(yyvsp[(3) - (3)].info).inst);
				print_code();
			}
    break;

  case 3:
#line 83 "grammer.y"
    {
				backpatch((yyvsp[(3) - (6)].info).truelist,(yyvsp[(5) - (6)].info).inst);
				(yyval.info).nextlist=merge((yyvsp[(3) - (6)].info).falselist,(yyvsp[(6) - (6)].info).nextlist);
			}
    break;

  case 4:
#line 89 "grammer.y"
    {
				backpatch((yyvsp[(3) - (10)].info).truelist,(yyvsp[(5) - (10)].info).inst);
				backpatch((yyvsp[(3) - (10)].info).falselist,(yyvsp[(9) - (10)].info).inst);
				struct list * temp = merge((yyvsp[(8) - (10)].info).nextlist,(yyvsp[(10) - (10)].info).nextlist);
				(yyval.info).nextlist=merge(temp,(yyvsp[(6) - (10)].info).nextlist);
			}
    break;

  case 5:
#line 98 "grammer.y"
    {
				backpatch((yyvsp[(7) - (7)].info).nextlist,(yyvsp[(2) - (7)].info).inst);
				backpatch((yyvsp[(4) - (7)].info).truelist,(yyvsp[(6) - (7)].info).inst);
				
				(yyval.info).nextlist=(yyvsp[(4) - (7)].info).falselist;
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
	
				sprintf(fill_label,"%d",(yyvsp[(2) - (7)].info).inst);
				strcat(code[next_inst],fill_label);
				
				next_inst++;
			}
    break;

  case 6:
#line 114 "grammer.y"
    {
			
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			
				backpatch((yyvsp[(5) - (9)].info).nextlist,next_inst);
			
			
				int i;
				for(i=1;i<=no_of_cases;i++)
				{
					code[next_inst]=(char*)malloc(50);
					if(i!=no_of_cases||case_inst[i][0]!=NULL)
					sprintf(code[next_inst],"%s%s%s%s%s%s","if ",(yyvsp[(3) - (9)].info).addr,"==",case_inst[i][0]," goto ",case_inst[i][1]);
					
					else
					sprintf(code[next_inst],"%s%s","goto ",case_inst[i][1]);
					
					next_inst++;
				}
				
				backpatch((yyvsp[(7) - (9)].info).nextlist,next_inst);
	
				sprintf(fill_label,"%d",next_inst);
				strcat(code[(yyvsp[(9) - (9)].info).inst],fill_label);
				no_of_cases=0;
				no_of_defaults=0;
				(yyval.info).nextlist=NULL;
			}
    break;

  case 7:
#line 147 "grammer.y"
    {
				(yyval.info).nextlist=(yyvsp[(2) - (3)].info).nextlist;
			}
    break;

  case 8:
#line 152 "grammer.y"
    {
				(yyval.info).nextlist=NULL;
			}
    break;

  case 9:
#line 157 "grammer.y"
    {
				(yyval.info).nextlist=NULL;
			}
    break;

  case 10:
#line 162 "grammer.y"
    {
				(yyval.info).nextlist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
    break;

  case 11:
#line 170 "grammer.y"
    {
				(yyval.info).nextlist=NULL;
			}
    break;

  case 12:
#line 179 "grammer.y"
    {
			declare((yyvsp[(3) - (3)].info).addr);
			}
    break;

  case 13:
#line 184 "grammer.y"
    {
			declare((yyvsp[(1) - (1)].info).addr);
			}
    break;

  case 14:
#line 190 "grammer.y"
    {
			declare((yyvsp[(3) - (5)].info).addr);
			}
    break;

  case 15:
#line 195 "grammer.y"
    {
			declare((yyvsp[(1) - (3)].info).addr);
		}
    break;

  case 16:
#line 200 "grammer.y"
    {
				no_of_cases++;
				case_inst[no_of_cases][0]=(yyvsp[(3) - (6)].info).addr;
				sprintf(fill_label,"%d",(yyvsp[(5) - (6)].info).inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				(yyval.info).nextlist=merge((yyvsp[(1) - (6)].info).nextlist,(yyvsp[(6) - (6)].info).nextlist);
	
			}
    break;

  case 17:
#line 211 "grammer.y"
    {
				no_of_cases++;
				no_of_defaults++;
				
				if(no_of_defaults==2)
				{
					printf("\nerror more than 1 defaults \n");
					exit(1);
				}
				
				case_inst[no_of_cases][0]=NULL;
				sprintf(fill_label,"%d",(yyvsp[(4) - (5)].info).inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				(yyval.info).nextlist=merge((yyvsp[(1) - (5)].info).nextlist,(yyvsp[(5) - (5)].info).nextlist);
			}
    break;

  case 18:
#line 229 "grammer.y"
    {
				no_of_cases++;
				case_inst[no_of_cases][0]=(yyvsp[(2) - (5)].info).addr;
				sprintf(fill_label,"%d",(yyvsp[(4) - (5)].info).inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				(yyval.info).nextlist=(yyvsp[(5) - (5)].info).nextlist;
			}
    break;

  case 19:
#line 240 "grammer.y"
    {	
				backpatch((yyvsp[(1) - (3)].info).nextlist,(yyvsp[(2) - (3)].info).inst);
				(yyval.info).nextlist=(yyvsp[(3) - (3)].info).nextlist;
				
			}
    break;

  case 20:
#line 247 "grammer.y"
    {	
				(yyval.info).nextlist=(yyvsp[(1) - (1)].info).nextlist;
				
			}
    break;

  case 21:
#line 255 "grammer.y"
    {
				backpatch((yyvsp[(1) - (4)].info).falselist,(yyvsp[(3) - (4)].info).inst);
				(yyval.info).truelist=merge((yyvsp[(1) - (4)].info).truelist,(yyvsp[(4) - (4)].info).truelist);
				(yyval.info).falselist=(yyvsp[(4) - (4)].info).falselist;
			}
    break;

  case 22:
#line 262 "grammer.y"
    {
				backpatch((yyvsp[(1) - (4)].info).truelist,(yyvsp[(3) - (4)].info).inst);
				(yyval.info).falselist=merge((yyvsp[(1) - (4)].info).falselist,(yyvsp[(4) - (4)].info).falselist);
				(yyval.info).truelist=(yyvsp[(4) - (4)].info).truelist;
			}
    break;

  case 23:
#line 269 "grammer.y"
    {
				(yyval.info).truelist = (yyvsp[(2) - (2)].info).falselist;
				(yyval.info).falselist = (yyvsp[(2) - (2)].info).truelist;
			}
    break;

  case 24:
#line 275 "grammer.y"
    {
				(yyval.info).truelist = (yyvsp[(2) - (3)].info).truelist;
				(yyval.info).falselist = (yyvsp[(2) - (3)].info).falselist;
			}
    break;

  case 25:
#line 281 "grammer.y"
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[(1) - (3)].info).addr,"==",(yyvsp[(3) - (3)].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
    break;

  case 26:
#line 298 "grammer.y"
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[(1) - (3)].info).addr,"!=",(yyvsp[(3) - (3)].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
    break;

  case 27:
#line 317 "grammer.y"
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[(1) - (3)].info).addr,">=",(yyvsp[(3) - (3)].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
    break;

  case 28:
#line 336 "grammer.y"
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[(1) - (3)].info).addr,"<=",(yyvsp[(3) - (3)].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
    break;

  case 29:
#line 352 "grammer.y"
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[(1) - (3)].info).addr,"<",(yyvsp[(3) - (3)].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
    break;

  case 30:
#line 369 "grammer.y"
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[(1) - (3)].info).addr,">",(yyvsp[(3) - (3)].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
    break;

  case 31:
#line 387 "grammer.y"
    {	
				(yyval.info).truelist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				

				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
    break;

  case 32:
#line 397 "grammer.y"
    {	
				(yyval.info).falselist=makelist(next_inst);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
    break;

  case 33:
#line 409 "grammer.y"
    {
				(yyval.info).inst=next_inst;
			}
    break;

  case 34:
#line 415 "grammer.y"
    {
				(yyval.info).nextlist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				

				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
    break;

  case 35:
#line 426 "grammer.y"
    {
				if(!isdeclared((yyvsp[(1) - (4)].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[(1) - (4)].info).addr);
				}
				
				code[next_inst]=(char*)malloc(50);				

				sprintf(code[next_inst],"%s%c%s",(yyvsp[(1) - (4)].info).addr,'=',(yyvsp[(3) - (4)].info).addr);
				next_inst++;
			}
    break;

  case 36:
#line 439 "grammer.y"
    {
				if(!isdeclared((yyvsp[(1) - (4)].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[(1) - (4)].info).addr);
				}
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyvsp[(1) - (4)].info).addr,'=',(yyvsp[(1) - (4)].info).addr,'+',(yyvsp[(3) - (4)].info).addr);
				next_inst++;
			}
    break;

  case 37:
#line 450 "grammer.y"
    {
				if(!isdeclared((yyvsp[(1) - (4)].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[(1) - (4)].info).addr);
				}
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyvsp[(1) - (4)].info).addr,'=',(yyvsp[(1) - (4)].info).addr,'-',(yyvsp[(3) - (4)].info).addr);
				next_inst++;
			}
    break;

  case 38:
#line 461 "grammer.y"
    {
				if(!isdeclared((yyvsp[(1) - (4)].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[(1) - (4)].info).addr);
				}
				
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyvsp[(1) - (4)].info).addr,'=',(yyvsp[(1) - (4)].info).addr,'*',(yyvsp[(3) - (4)].info).addr);
				next_inst++;
			}
    break;

  case 39:
#line 473 "grammer.y"
    {
				if(!isdeclared((yyvsp[(1) - (4)].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[(1) - (4)].info).addr);
				}
				
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyvsp[(1) - (4)].info).addr,'=',(yyvsp[(1) - (4)].info).addr,'/',(yyvsp[(3) - (4)].info).addr);
				next_inst++;
			}
    break;

  case 40:
#line 488 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'+',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 41:
#line 497 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'-',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 42:
#line 506 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'*',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 43:
#line 515 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'/',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 44:
#line 525 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'%',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 45:
#line 536 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'@',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 46:
#line 545 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'&',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 47:
#line 555 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'^',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 48:
#line 565 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[(1) - (3)].info).addr,'|',(yyvsp[(3) - (3)].info).addr);
				next_inst++;
			}
    break;

  case 49:
#line 575 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,(yyvsp[(2) - (3)].info).addr);
			}
    break;

  case 50:
#line 581 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%c%s",(yyval.info).addr,'=','~',(yyvsp[(2) - (2)].info).addr);
				next_inst++;
			}
    break;

  case 51:
#line 590 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%c%s",(yyval.info).addr,'=','-',(yyvsp[(2) - (2)].info).addr);
				next_inst++;
			}
    break;

  case 52:
#line 599 "grammer.y"
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,(yyvsp[(1) - (1)].info).addr);
			}
    break;

  case 53:
#line 604 "grammer.y"
    {
				if(!isdeclared((yyvsp[(1) - (1)].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[(1) - (1)].info).addr);
				}
				
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,(yyvsp[(1) - (1)].info).addr);
			}
    break;


/* Line 1267 of yacc.c.  */
#line 2169 "y.tab.c"
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


#line 615 "grammer.y"

#include "lex.yy.c"

int main(int argc,char** argv)
{
	if(argc==2)
	yyin=fopen(argv[1],"r");

	else
	yyin=fopen("internal/input.cpp","r");
	
	yyparse();
	
}

struct list * makelist(int next_inst)
{
	struct list * new=malloc(sizeof(struct list));
	new->inst_no=next_inst;
	new->next=NULL;
	return new;
}

struct list * merge(struct list * l1,struct list * l2)
{
	if(l1!=NULL)
	{
		struct list * new=l1;
		while(l1->next!=NULL)
		l1=l1->next;
		l1->next=l2;
		return new;
	}
	
	else return l2; 

}

void backpatch(struct list* l,int target_inst)
{
	while(l!=NULL)
	{
		sprintf(fill_label,"%d",target_inst);
		strcat(code[l->inst_no],fill_label);
		l=l->next;
	}
}

char* new_temp()
{
	char *temp;
	temp=malloc(5);
	sprintf(temp,"%c%d",'t',count++);
	return temp;
}


void print_code()
{
	int i;
	for(i=1;i<next_inst;i++)
	{
		if(i<100) printf(" ");
		if(i<10) printf(" ");
		printf("%d : %s\n",i,code[i]);
	}
}


void declare(char* id)
{
	identifiers[no_of_identifiers++]=id;
}

int isdeclared(char* id)
{
	int i;
	
	for(i=0;i<no_of_identifiers;i++)
	if(strcmp(identifiers[i],id)==0)
	return 1;
	
	return 0;
	
}

