/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 119 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

