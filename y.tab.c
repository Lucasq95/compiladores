
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "assembler.h"

void validateAsignation();
void validateType();
void validateIdDeclaration();
void validateAsignationString();
void validateCondition();
char* changeType();

char* seen[200];
int seenIndex = 0;

int flagAsigM = 0;
int flagDeclaration = 0;

int yystopparser=0;
extern yylineno;
FILE  *yyin;
ast* tree;


/* Line 189 of yacc.c  */
#line 100 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DIGITO = 258,
     LETRA = 259,
     CHAR_ESP = 260,
     COMMENT = 261,
     ID = 262,
     CTE_STRING = 263,
     CTE_ENT = 264,
     CTE_REAL = 265,
     P_A = 266,
     P_C = 267,
     C_A = 268,
     C_C = 269,
     L_A = 270,
     L_C = 271,
     PYC = 272,
     PTO = 273,
     DPTO = 274,
     COMA = 275,
     IF = 276,
     ELSE = 277,
     ENDIF = 278,
     VAR = 279,
     ENDVAR = 280,
     REPEAT = 281,
     UNTIL = 282,
     PRINT = 283,
     READ = 284,
     CONST = 285,
     INT = 286,
     FLOAT = 287,
     STRING = 288,
     OP_ASIG = 289,
     ALL_EQUALS = 290,
     OP_SUMA = 291,
     OP_RESTA = 292,
     OP_MULT = 293,
     OP_DIV = 294,
     AND = 295,
     OR = 296,
     NOT = 297,
     OP_MAX = 298,
     OP_MAXEQ = 299,
     OP_MIN = 300,
     OP_MINEQ = 301,
     OP_NEQ = 302,
     OP_EQ = 303,
     EQ = 304,
     MENOS_UNARIO = 305
   };
#endif
/* Tokens.  */
#define DIGITO 258
#define LETRA 259
#define CHAR_ESP 260
#define COMMENT 261
#define ID 262
#define CTE_STRING 263
#define CTE_ENT 264
#define CTE_REAL 265
#define P_A 266
#define P_C 267
#define C_A 268
#define C_C 269
#define L_A 270
#define L_C 271
#define PYC 272
#define PTO 273
#define DPTO 274
#define COMA 275
#define IF 276
#define ELSE 277
#define ENDIF 278
#define VAR 279
#define ENDVAR 280
#define REPEAT 281
#define UNTIL 282
#define PRINT 283
#define READ 284
#define CONST 285
#define INT 286
#define FLOAT 287
#define STRING 288
#define OP_ASIG 289
#define ALL_EQUALS 290
#define OP_SUMA 291
#define OP_RESTA 292
#define OP_MULT 293
#define OP_DIV 294
#define AND 295
#define OR 296
#define NOT 297
#define OP_MAX 298
#define OP_MAXEQ 299
#define OP_MIN 300
#define OP_MINEQ 301
#define OP_NEQ 302
#define OP_EQ 303
#define EQ 304
#define MENOS_UNARIO 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 109 "Sintactico.y"

  int integer_value;
  float float_value;
  char string_value[33];
  struct treeNode* ast;
  char* auxLogicOperator;



/* Line 214 of yacc.c  */
#line 246 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 258 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    33,    37,    38,    47,    51,
      53,    57,    59,    61,    63,    75,    83,    87,    91,    96,
      98,   100,   104,   106,   108,   110,   112,   114,   116,   121,
     124,   127,   130,   133,   137,   141,   145,   149,   153,   155,
     159,   163,   165,   167,   169,   171,   175,   179,   182,   184,
     192,   196,   198,   200,   202,   204,   209,   213,   217,   221,
     225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    74,    54,    -1,    74,    -1,
      54,    55,    -1,    55,    -1,    56,    -1,    57,    -1,    62,
      -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,     7,
      34,    71,    -1,     7,    34,     8,    -1,    -1,    13,    58,
      59,    14,    34,    13,    60,    14,    -1,    59,    20,     7,
      -1,     7,    -1,    60,    20,    61,    -1,    61,    -1,    71,
      -1,     8,    -1,    21,    11,    63,    12,    15,    54,    16,
      22,    15,    54,    16,    -1,    21,    11,    63,    12,    15,
      54,    16,    -1,    64,    40,    64,    -1,    64,    41,    64,
      -1,    42,    11,    64,    12,    -1,    64,    -1,    79,    -1,
       7,    65,    73,    -1,    43,    -1,    45,    -1,    46,    -1,
      44,    -1,    48,    -1,    47,    -1,    26,    54,    27,    63,
      -1,    28,     8,    -1,    28,     7,    -1,    29,     7,    -1,
      30,    70,    -1,     7,    34,     9,    -1,     7,    34,     8,
      -1,     7,    34,    10,    -1,    71,    36,    72,    -1,    71,
      37,    72,    -1,    72,    -1,    72,    38,    73,    -1,    72,
      39,    73,    -1,    73,    -1,     7,    -1,     9,    -1,    10,
      -1,    11,    71,    12,    -1,    24,    75,    25,    -1,    75,
      76,    -1,    76,    -1,    13,    77,    14,    19,    13,    59,
      14,    -1,    77,    20,    78,    -1,    78,    -1,    33,    -1,
      32,    -1,    31,    -1,    35,    11,    80,    12,    -1,    80,
      20,    81,    -1,    81,    20,    81,    -1,    13,    82,    14,
      -1,    82,    20,    71,    -1,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   120,   120,   122,   123,   125,   126,   128,   129,   130,
     131,   132,   133,   134,   136,   137,   139,   139,   141,   142,
     144,   145,   147,   148,   150,   151,   153,   154,   155,   156,
     157,   159,   161,   162,   163,   164,   165,   166,   168,   170,
     171,   173,   175,   177,   178,   179,   181,   182,   183,   185,
     186,   187,   189,   190,   191,   192,   194,   196,   197,   199,
     201,   202,   204,   205,   206,   208,   210,   211,   213,   215,
     217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGITO", "LETRA", "CHAR_ESP", "COMMENT",
  "ID", "CTE_STRING", "CTE_ENT", "CTE_REAL", "P_A", "P_C", "C_A", "C_C",
  "L_A", "L_C", "PYC", "PTO", "DPTO", "COMA", "IF", "ELSE", "ENDIF", "VAR",
  "ENDVAR", "REPEAT", "UNTIL", "PRINT", "READ", "CONST", "INT", "FLOAT",
  "STRING", "OP_ASIG", "ALL_EQUALS", "OP_SUMA", "OP_RESTA", "OP_MULT",
  "OP_DIV", "AND", "OR", "NOT", "OP_MAX", "OP_MAXEQ", "OP_MIN", "OP_MINEQ",
  "OP_NEQ", "OP_EQ", "EQ", "MENOS_UNARIO", "$accept", "programa",
  "program", "cuerpo_programa", "sentencia", "asignacion_s",
  "asignacion_m", "$@1", "lista_var", "lista_exp", "tipo_exp", "decision",
  "condiciones", "condicion", "operador_logico", "iteracion", "printear",
  "obtain", "cteNombre", "constExp", "expresion", "termino", "factor",
  "definiciones_variables", "definicion_variables", "def",
  "lista_de_tipos", "tipos_primitivos", "all_equals", "listas_exp",
  "lista", "items", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    58,    57,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    64,    65,    65,    65,    65,    65,    65,    66,    67,
      67,    68,    69,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    73,    73,    74,    75,    75,    76,
      77,    77,    78,    78,    78,    79,    80,    80,    81,    82,
      82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     0,     8,     3,     1,
       3,     1,     1,     1,    11,     7,     3,     3,     4,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     3,     3,     2,     1,     7,
       3,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     0,    58,     1,     0,
      16,     0,     0,     0,     0,     0,     3,     6,     7,     8,
       9,    10,    11,    12,    13,    64,    63,    62,     0,    61,
      56,    57,     0,     0,     0,     0,    40,    39,    41,     0,
      42,     5,     0,     0,    52,    15,    53,    54,     0,    14,
      48,    51,    19,     0,     0,     0,     0,     0,    29,    30,
       0,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,    32,    35,    33,    34,    37,    36,     0,     0,     0,
       0,     0,     0,    38,    44,    43,    45,     0,    55,    46,
      47,    49,    50,     0,    18,    31,     0,     0,     0,     0,
       0,    26,    27,     0,     0,    70,     0,    65,     0,     0,
      28,     0,    59,    23,     0,    21,    22,    68,     0,    66,
      67,    25,    17,     0,    69,     0,    20,     0,     0,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    16,    17,    18,    19,    33,    53,   114,
     115,    20,    57,    58,    77,    21,    22,    23,    24,    40,
     116,    50,    51,     4,     6,     7,    28,    29,    59,    97,
      98,   106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int8 yypact[] =
{
     -16,     3,    27,   -63,    64,    71,    -4,   -63,   -63,   -24,
     -63,    28,    64,    79,    36,    58,    64,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,    -7,   -63,
     -63,   -63,    65,    77,    -5,     5,   -63,   -63,   -63,     7,
     -63,   -63,    72,    71,   -63,   -63,   -63,   -63,    53,    69,
      70,   -63,   -63,    -3,    35,    84,    96,   100,    76,   -63,
      -5,    15,   101,   -63,    -8,    53,    53,    53,    53,    86,
     114,   -63,   -63,   -63,   -63,   -63,   -63,    53,   109,   116,
     110,   116,   116,   -63,   -63,   -63,   -63,    77,   -63,    70,
      70,   -63,   -63,   111,   -63,   -63,    53,     2,   106,   115,
      64,   -63,   -63,    24,    90,    69,    26,   -63,   109,   109,
     -63,    29,   -63,   -63,    34,   -63,    69,   -63,    53,   -63,
     -63,   107,   -63,    90,    69,   113,   -63,    64,    40,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -12,   -15,   -63,   -63,   -63,    43,   -63,
       8,   -63,    73,   -30,   -63,   -63,   -63,   -63,   -63,   -63,
     -29,    45,   -62,   -63,   -63,   126,   -63,    91,   -63,   -63,
      10,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,    41,    54,    49,    88,    91,    92,    42,     1,     5,
      32,    69,     9,    43,   107,    95,     5,    70,    10,    64,
      41,    30,   108,    84,    85,    86,    11,     8,    65,    66,
      55,    12,    60,    13,    14,    15,     9,    56,   112,    34,
     117,    61,    10,    38,    70,   121,   118,     9,   122,    99,
      11,   101,   102,    10,   123,    12,   129,    13,    14,    15,
      44,    11,    46,    47,    48,    39,    12,   105,    13,    14,
      15,     9,    44,    45,    46,    47,    48,    10,    71,    72,
      73,    74,    75,    76,    52,    11,    36,    37,   111,   124,
      12,    62,    13,    14,    15,    78,    41,    44,   113,    46,
      47,    48,    25,    26,    27,    65,    66,    79,    67,    68,
      89,    90,    80,    41,    87,   128,    81,    82,   119,   120,
      93,    94,    96,    54,   104,   100,   109,   110,   127,   125,
     103,   126,    31,    83,    63
};

static const yytype_uint8 yycheck[] =
{
      12,    16,     7,    32,    12,    67,    68,    14,    24,    13,
      34,    14,     7,    20,    12,    77,    13,    20,    13,    48,
      35,    25,    20,     8,     9,    10,    21,     0,    36,    37,
      35,    26,    27,    28,    29,    30,     7,    42,    14,    11,
      14,    34,    13,     7,    20,    16,    20,     7,    14,    79,
      21,    81,    82,    13,    20,    26,    16,    28,    29,    30,
       7,    21,     9,    10,    11,     7,    26,    96,    28,    29,
      30,     7,     7,     8,     9,    10,    11,    13,    43,    44,
      45,    46,    47,    48,     7,    21,     7,     8,   100,   118,
      26,    19,    28,    29,    30,    11,   111,     7,     8,     9,
      10,    11,    31,    32,    33,    36,    37,    11,    38,    39,
      65,    66,    12,   128,    13,   127,    40,    41,   108,   109,
      34,     7,    13,     7,    13,    15,    20,    12,    15,    22,
      87,   123,     6,    60,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    52,    53,    74,    13,    75,    76,     0,     7,
      13,    21,    26,    28,    29,    30,    54,    55,    56,    57,
      62,    66,    67,    68,    69,    31,    32,    33,    77,    78,
      25,    76,    34,    58,    11,    54,     7,     8,     7,     7,
      70,    55,    14,    20,     7,     8,     9,    10,    11,    71,
      72,    73,     7,    59,     7,    35,    42,    63,    64,    79,
      27,    34,    19,    78,    71,    36,    37,    38,    39,    14,
      20,    43,    44,    45,    46,    47,    48,    65,    11,    11,
      12,    40,    41,    63,     8,     9,    10,    13,    12,    72,
      72,    73,    73,    34,     7,    73,    13,    80,    81,    64,
      15,    64,    64,    59,    13,    71,    82,    12,    20,    20,
      12,    54,    14,     8,    60,    61,    71,    14,    20,    81,
      81,    16,    14,    20,    71,    22,    61,    15,    54,    16
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 120 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); tree = (yyval.ast); printf("\nRegla 00 : Compilacion Ok\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 122 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(2) - (2)].ast); printf("\nRegla 1 : Definicion Variables + program\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 123 "Sintactico.y"
    {printf("\nRegla 2 : Definicion Variables\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 125 "Sintactico.y"
    {flagDeclaration = 1; (yyval.ast) = newNode("Cuerpo_Programa",(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast)); printf("\nRegla 3 : Program Sentencia\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 126 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); printf("\nRegla 4 : Sentencia\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 128 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); printf("\nRegla 5 : Asignacion Simple\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 129 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); printf("\nRegla 6 : Asignacion Multiple\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 130 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); printf("\nRegla 7 : Decision\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 131 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); printf("\nRegla 8 : Iteracion\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 132 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); printf("\nRegla 9 : Print\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 133 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); printf("\nRegla 10 : READ\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 134 "Sintactico.y"
    {(yyval.ast) = NULL; printf("\nRegla 11 : Constante Nombre\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 136 "Sintactico.y"
    {validateAsignation((yyvsp[(1) - (3)].string_value),(yyvsp[(3) - (3)].ast)); (yyval.ast) = newNode(":=",newLeaf((yyvsp[(1) - (3)].string_value)),(yyvsp[(3) - (3)].ast)); printf("\nRegla 12 : Asig Simple ID := EXPRESION\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 137 "Sintactico.y"
    {validateAsignationString((yyvsp[(1) - (3)].string_value)); (yyval.ast) = newNode(":=",newLeaf((yyvsp[(1) - (3)].string_value)),newLeaf(getSymbolName((yyvsp[(3) - (3)].string_value),3))); printf("\nRegla 13 : Asig Simple ID := STRING\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 139 "Sintactico.y"
    {flagAsigM = 1;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 139 "Sintactico.y"
    {flagAsigM =0; (yyval.ast) = incrustarArbol(); clearAsigMList(); printf("\nRegla 14 : Asignacion Multiple Lista\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {if(flagDeclaration == 0){validateIdDeclaration((yyvsp[(3) - (3)].string_value)); insertIdentifier((yyvsp[(3) - (3)].string_value));} if(flagAsigM == 1){insertAsigM((yyvsp[(3) - (3)].string_value),1,0,0,0);} printf("\nRegla 15 : Lista, ID\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 142 "Sintactico.y"
    {if(flagDeclaration == 0){validateIdDeclaration((yyvsp[(1) - (1)].string_value)); insertIdentifier((yyvsp[(1) - (1)].string_value));} if(flagAsigM == 1){insertAsigM((yyvsp[(1) - (1)].string_value),1,0,0,0);} printf("\nRegla 16 : Lista ID\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 144 "Sintactico.y"
    {printf("\nRegla 17 : Lista_EXP, Expresion\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 145 "Sintactico.y"
    {printf("\nRegla 18 : tipo_exp\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 147 "Sintactico.y"
    {printf("\nRegla 19 : Expresion\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 148 "Sintactico.y"
    {insertAsigM((yyvsp[(1) - (1)].string_value),2,0,0,1); printf("\nRegla 20 : String\n");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 150 "Sintactico.y"
    {(yyval.ast) = newNode("IF", (yyvsp[(3) - (11)].ast), newNode("CUERPO_IF",(yyvsp[(6) - (11)].ast),(yyvsp[(10) - (11)].ast))); printf("\nRegla 21 : Decision con Else\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 151 "Sintactico.y"
    {(yyval.ast) = newNode("IF", (yyvsp[(3) - (7)].ast), (yyvsp[(6) - (7)].ast)); printf("\nRegla 22 : Decision\n");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 153 "Sintactico.y"
    {(yyval.ast) = newNode("AND", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); printf("\nRegla 23 : cond AND cond\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    {(yyval.ast) = newNode("OR", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)); printf("\nRegla 24 : cond OR cond\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 155 "Sintactico.y"
    {(yyval.ast) = newNode("NOT", (yyvsp[(3) - (4)].ast), NULL); printf("\nRegla 25 : NOT cond\n");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 156 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast); printf("\nRegla 26 : Condicion\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 157 "Sintactico.y"
    {printf("\nRegla 63: AllEquals condicion\n");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 159 "Sintactico.y"
    {validateCondition((yyvsp[(1) - (3)].string_value),(yyvsp[(3) - (3)].ast),1); (yyval.ast) = newNode((yyvsp[(2) - (3)].auxLogicOperator),newLeaf((yyvsp[(1) - (3)].string_value)),(yyvsp[(3) - (3)].ast)); printf("\nRegla 27 : ID Operador Logico Comparado\n");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 161 "Sintactico.y"
    {(yyval.auxLogicOperator) = ">"; printf("\nRegla 28 : >\n");}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    {(yyval.auxLogicOperator) = "<"; printf("\nRegla 29 : <\n");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 163 "Sintactico.y"
    {(yyval.auxLogicOperator) = "<="; printf("\nRegla 30 : <=\n");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 164 "Sintactico.y"
    {(yyval.auxLogicOperator) = ">="; printf("\nRegla 31 : >=\n");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 165 "Sintactico.y"
    {(yyval.auxLogicOperator) = "=="; printf("\nRegla 32 : ==\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 166 "Sintactico.y"
    {(yyval.auxLogicOperator) = "!="; printf("\nRegla 33 : !=\n");}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 168 "Sintactico.y"
    {(yyval.ast) = newNode("REPEAT",newNode("UNTIL",(yyvsp[(4) - (4)].ast),NULL),(yyvsp[(2) - (4)].ast));printf("\nRegla 34 : Repeat\n");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 170 "Sintactico.y"
    {(yyval.ast) = newNode("PRINT",newLeaf(getSymbolName((yyvsp[(2) - (2)].string_value),3)),NULL);printf("\nRegla 36 : Print String\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 171 "Sintactico.y"
    {(yyval.ast) = newNode("PRINT",newLeaf((yyvsp[(2) - (2)].string_value)),NULL); printf("\nRegla 37 : Print ID\n");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 173 "Sintactico.y"
    {(yyval.ast) = newNode("READ",newLeaf((yyvsp[(2) - (2)].string_value)),NULL); printf("\nRegla 38 : Read Variable\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 175 "Sintactico.y"
    {printf("\nRegla 38' CONST constExp\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 177 "Sintactico.y"
    {validateIdDeclaration((yyvsp[(1) - (3)].string_value)); putConstOnSymbolTable((yyvsp[(1) - (3)].string_value), "", (yyvsp[(3) - (3)].integer_value), 0, "CONST_ENT", 1); printf("\nRegla 39 : Cte Con Nombre Entero\n");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 178 "Sintactico.y"
    {validateIdDeclaration((yyvsp[(1) - (3)].string_value)); putConstOnSymbolTable((yyvsp[(1) - (3)].string_value), (yyvsp[(3) - (3)].string_value), 0, 0, "CONST_STRING", 2); printf("\nRegla 40 : Cte Con Nombre String\n");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 179 "Sintactico.y"
    {validateIdDeclaration((yyvsp[(1) - (3)].string_value)); putConstOnSymbolTable((yyvsp[(1) - (3)].string_value), "", 0, (yyvsp[(3) - (3)].float_value), "CONST_FLOAT", 3); printf("\nRegla 41 : Cte Con Nombre Float\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 181 "Sintactico.y"
    {(yyval.ast) = newNode("+",(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast)); printf("\nRegla 42 : E + T\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 182 "Sintactico.y"
    {(yyval.ast) = newNode("-",(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast)); printf("\nRegla 43 : E - T\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 183 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 185 "Sintactico.y"
    {(yyval.ast) = newNode("*",(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast)); printf("\nRegla 44 : T * F\n");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 186 "Sintactico.y"
    {(yyval.ast) = newNode("/",(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast)); printf("\nRegla 45 : T / F\n");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 187 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 189 "Sintactico.y"
    {(yyval.ast) = newLeaf((yyvsp[(1) - (1)].string_value)); if(flagAsigM == 1){insertAsigM((yyvsp[(1) - (1)].string_value),2,0,0,1);} printf("\nRegla 46 : ID\n");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 190 "Sintactico.y"
    {(yyval.ast) = newLeaf(getSymbolName(&((yyvsp[(1) - (1)].integer_value)),1)); if(flagAsigM == 1){insertAsigM("",2,0,(yyvsp[(1) - (1)].integer_value),2);} printf("\nRegla 47 : Entero\n");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 191 "Sintactico.y"
    {(yyval.ast) = newLeaf(getSymbolName(&((yyvsp[(1) - (1)].float_value)),2)); if(flagAsigM == 1){insertAsigM("",2,(yyvsp[(1) - (1)].float_value),0,3);} printf("\nRegla 48 : Real\n");}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 192 "Sintactico.y"
    {(yyval.ast) = (yyvsp[(2) - (3)].ast); printf("\nRegla 49 : (E)\n");}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 194 "Sintactico.y"
    {printf("\nRegla 50 : VAR def_Var ENDVAR\n");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 196 "Sintactico.y"
    {printf("\nRegla 51 : Def Variable Multiple Linea\n");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 197 "Sintactico.y"
    {printf("\nRegla 52 : Def Variable Simple Linea\n");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 199 "Sintactico.y"
    {putTypeIdentifierOnSymbolTable(); printf("\nRegla 53 : Lista Tipos - Lista Vars\n");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 201 "Sintactico.y"
    {printf("\nRegla 54 : Lista_Tipos, Tipo_Primitivo\n");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 202 "Sintactico.y"
    {printf("\nRegla 55 : Tipo_Primitivo\n");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 204 "Sintactico.y"
    {insertTypeIdentifier((yyvsp[(1) - (1)].string_value)); printf("\nRegla 56 : Tipo_Primitivo String\n");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 205 "Sintactico.y"
    {insertTypeIdentifier((yyvsp[(1) - (1)].string_value)); printf("\nRegla 57 : Tipo_Primitivo Float\n");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 206 "Sintactico.y"
    {insertTypeIdentifier((yyvsp[(1) - (1)].string_value)); printf("\nRegla 58 : Tipo_Primitivo Int\n");}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 208 "Sintactico.y"
    {crearNodosCondicionAllEqual(); printf("\nRegla 59: AllEquals\n");}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 210 "Sintactico.y"
    {printf("\nRegla 60: Listas de Expresiones\n");}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 211 "Sintactico.y"
    {printf("\nRegla 61: Dos listas de expresiones\n");}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 213 "Sintactico.y"
    {cerrarListaAllEqual(); printf("\nRegla 62: Lista de expresiones\n");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 215 "Sintactico.y"
    {insertarNodoEnListaAllEqual((yyvsp[(3) - (3)].ast)); printf("\nRegla 63: Mas de un Item en la lista de expresiones\n");}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 217 "Sintactico.y"
    {insertarNodoEnListaAllEqual((yyvsp[(1) - (1)].ast)); printf("\nRegla 64: Un item en la lista de expresiones\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2058 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 220 "Sintactico.y"


int main(int argc,char *argv[]){
    if ((yyin = fopen(argv[1], "rt")) == NULL) {
	    printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    } else {
        symbolTable = NULL;
            do {
                yyparse();
            } while(!feof(yyin));
        saveTable();
        ast treeCopy = *tree;
        printAndSaveAST(tree);
        printf("\n");
        printf("\n");
        generateAssembler(tree);
        printf("\n");
        printf("\n");
    }
    fclose(yyin);
    return 0;
}

int yyerror(void) {
    printf("\n[E] Syntax Error - line %d\n\n", yylineno);
	system ("Pause");
	exit (1);
}

void validateIdDeclaration(char* id) {
    int i = 0;
    for(i = 0; i < seenIndex; i++) {
        if(strcmp(seen[i], id) == 0) {
            fprintf(stderr, "\n[E] Identifier invalid: '%s' it has been already declared in the line: %d\n",id, yylineno);
            exit(1);
        }
    }
    seen[seenIndex] = strdup(id);
    seenIndex++;
}

void validateAsignation(char* id, ast* exp) {
    symbolNode* symbol = findSymbol(id);
    symbolNode* treeValue;
    if (strcmp(exp->value,"-") != 0) {
        treeValue = findSymbol(exp->value);
    } else {
        treeValue = findSymbol("+");
    }
    if (symbol != NULL && treeValue != NULL) {
        if((strcmp(symbol->type, "INT") == 0 || strcmp(symbol->type, "FLOAT") == 0) && (strcmp(treeValue->type, "STRING") == 0 || strcmp(treeValue->type, "CONST_STRING") == 0 )) {
            fprintf(stderr, "\n[E] Incompatible assignment, line: %d\n", yylineno);
            exit(1);
        }
        if((strcmp(symbol->type, "STRING") == 0) && (strcmp(treeValue->type, "INTEGER_CTE") == 0 || strcmp(treeValue->type, "CTE_REAL") == 0  || strcmp(treeValue->type, "CTE_ENT") == 0 || strcmp(treeValue->type, "FLOAT_CTE") == 0 || strcmp(treeValue->type, "INT") == 0 || strcmp(treeValue->type, "FLOAT") == 0 )) {
            fprintf(stderr, "\n[E] Incompatible assignment, line: %d\n", yylineno);
            exit(1);
        }
        if((strcmp(symbol->type, "INT") == 0 && (strcmp(treeValue->type, "FLOAT") == 0 || strcmp(treeValue->type, "FLOAT_CTE") == 0 || strcmp(treeValue->type, "CTE_REAL") == 0))
        || strcmp(symbol->type, "FLOAT") == 0 && (strcmp(treeValue->type, "INT") == 0 || strcmp(treeValue->type, "INTEGER_CTE") == 0 || strcmp(treeValue->type, "CTE_ENT") == 0)) {
            fprintf(stderr, "\n[E] Incompatible assignment, line: %d\n", yylineno);
            exit(1);
        }
    }
}

void validateAsignationString(char* id){
    symbolNode* symbol = findSymbol(id);
    if (strcmp(symbol->type, "STRING") != 0){
        fprintf(stderr, "\n[E] Incompatible string assignment, line: %d\n", yylineno);
        exit(1);
    }
}

void validateCondition(char* left, ast* right, int fail) {
    if(right->value != NULL) {
        symbolNode* symbolLeft = findSymbol(left);
        symbolNode* symbolRight = findSymbol(right->value);
        if(symbolRight != NULL && symbolLeft != NULL) {
            if(fail == 1 && (
                strcmp(symbolLeft->type, changeType(symbolRight->type)) != 0 ||
                strcmp(symbolLeft->type, "STRING") == 0 ||
                strcmp(changeType(symbolRight->type), "STRING") == 0)) {
                fprintf(stderr, "\n[E] Different types in condition, line: %d\n", yylineno);
                exit(1);
            }
        }
    }
}

char* changeType(char* t) {
    char* value;
    if(strcmp(t,"STRING") == 0 || strcmp(t,"INT") == 0 || strcmp(t,"FLOAT") == 0) {
        value = t;
    }else{
        if(strcmp(t,"CTE_STRING") == 0 || strcmp(t,"STRING_CTE") == 0){
            value = "STRING";
        }else if(strcmp(t,"CTE_ENT") == 0 || strcmp(t,"INTEGER_CTE") == 0){
            value = "INT";
        }else if(strcmp(t,"CTE_REAL") == 0 || strcmp(t,"FLOAT_CTE") == 0){
            value = "FLOAT";
        }
    }
    return value;
}

