/// @file

#pragma once

#include <assert.h>

#include <iostream>

using namespace std;

/// @defgroup graph object graph
/// @{

/// base element of the object graph
struct Object {
  string value;
  Object(char* V);
  virtual ~Object();
};

struct Primitive : Object {
  Primitive(char* V);
};

struct Sym : Primitive {
  Sym(char* V);
};

/// @}

/// @defgroup skelex lexical skeleton
/// @{

/// @name lexer
extern int yylex();
extern int yylineno, yycol;
extern char* yytext;
extern char* yyfile;
extern FILE* yyin;
#define TOKEN(C, X)           \
  {                           \
    yylval.o = new C(yytext); \
    return X;                 \
  }

/// @name parser
extern int yyparse();
extern void yyerror(string msg);
#include "vm.parser.hpp"

/// @}
