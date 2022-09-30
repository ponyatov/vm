/// @file

#pragma once

#include <assert.h>

#include <iostream>
#include <sstream>

using namespace std;

/// @defgroup graph object graph
/// @{

/// base element of the object graph
struct Object {
  /// scalar: object name, string/number value
  string value;

  /// @name constructor

  Object(char* V);
  virtual ~Object();

  /// @name dump/stringify

  /// @brief full text tree dump
  /// @param[in] depth current recursion depth -> @ref pad
  /// @param[in] prefix prefix before `<T:V>` header
  string dump(int depth = 0, string prefix = "");

  /// @brief tree padding
  /// @param[in] depth recursion depth
  string pad(int depth);

  /// @brief `<T:V>` header
  /// @param[in] prefix prefix before `<T:V>` header
  string head(string prefix = "");

  /// @brief type/class tag (lowercased class name via RTTI)
  virtual string tag();

  /// @brief value in string form
  virtual string val();
};

/// scalar elements
struct Primitive : Object {
  Primitive(char* V);
};

/// symbol
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
/// @}
