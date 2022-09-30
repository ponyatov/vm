/// @file

#pragma once

#include <assert.h>

#include <iostream>
#include <sstream>

using namespace std;

/// @defgroup init system init/finalize
/// @{

/// @brief initialize data structures
extern void init(int argc, char* argv[]);

/// @brief finalize and stop system
/// @param[in] errorlevel status code to be returned into an OS
extern int fini(int errorlevel);
/// @}

/// @defgroup graph object graph
/// @{

/// base element of the object graph
struct Object {
  /// scalar: object name, string/number value
  string value;

  /// @name constructor

  Object(string V);
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

  /// @name operator

  Object* set(string key,Object* that);
};

/// scalar elements
struct Primitive : Object {
  Primitive(string V);
};

/// symbol
struct Sym : Primitive {
  Sym(string V);
};

struct Int:Primitive{
    int value;
    Int(int N);
    string val();
};

struct Container : Object {
  Container(string V);
};

struct Map : Container {
  Map(string V);
};

struct Active : Object {
  Active(string V);
};

struct VM : Active, Map {
  VM(string V);
};

extern VM* vm;

/// @}

/// @defgroup skelex lexical skeleton
/// @{

/// @name lexer (flex)

/// lexer will be called from @ref yyparse as callback
extern int yylex();
/// current source code line
extern int yylineno;
extern int yycolumn;
/// current parsed lexeme
extern char* yytext;
/// current file name
extern char* yyfile;
/// input file stream
extern FILE* yyin;
/// @brief macro used for token return from a lexer
/// @param[in] C class will be called as `new C(yytext)`
/// @param[in] X token name defined in `.yacc`
#define TOKEN(C, X)           \
  {                           \
    yylval.o = new C(yytext); \
    return X;                 \
  }

/// @name parser (bison)

/// parser entry
extern int yyparse();
/// syntax error callback
extern void yyerror(string msg);
#include "vm.parser.hpp"

/// @}
/// @}
