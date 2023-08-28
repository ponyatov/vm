/// @file

#pragma once

#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

/// @defgroup init init
/// @brief system init/finalize
/// @{
extern int main(int argc, char* argv[]);    ///< program entry point
extern void init(int& argc, char* argv[]);  ///< system initialize
extern int fini(int err = 0);               ///< system finalize & exit
extern void arg(int argc, char* argv);      ///< print command line argument
/// @}

/// @defgroup core core
/// @brief object (hyper)graph core

/// @defgroup object Object
/// @ingroup core

/// @defgroup gc Garbage Collection
/// @brief garbage collection & object pool management

/// @brief base class for all (hyper)graph elements
/// @ingroup object
struct Object {
    /// @name attribute grammar fields

    /// @brief scalar: object name, string/number value
    std::string value;

    /// @brief associative array = env/namespace = AST attributes
    std::map<std::string, Object*> slot;

    /// @brief ordered container = vector = stack = queue = AST subtrees
    std::vector<Object*> nest;

    /// @ingroup gc
    /// @{

    size_t ref;           ///< reference counter
    static Object* pool;  ///< linked list of all objects in a system
    Object* prev;         ///< previous object in @ref pool
    static void gc();     ///< single gc pass

    /// @}

    /// @name constructor

    /// @brief construct without @ref value setup
    /// (for cases with *value type override* -- see @ref Int as a sample)
    /// @details only object pool fields will be initialized (@ref gc)
    Object();
    Object(std::string V);
    virtual ~Object();

    /// @name dump/stringify

    /// @brief full text tree dump
    /// @param[in] depth current recursion depth -> @ref pad
    /// @param[in] prefix prefix before `<T:V>` header
    std::string dump(int depth = 0, std::string prefix = "");

    /// @brief tree padding
    /// @param[in] depth recursion depth
    std::string pad(int depth);

    /// @brief `<T:V>` header
    /// @param[in] prefix prefix before `<T:V>` header
    std::string head(std::string prefix = "");

    /// @brief type/class tag (lowercased class name via RTTI)
    virtual std::string tag();

    /// @brief value in string form
    virtual std::string val();

    /// @name operator

    Object* set(std::string key, Object* that);
};

/// scalar elements
struct Primitive : Object {
    Primitive();
    Primitive(std::string V);
};

/// symbol
struct Sym : Primitive {
    Sym(std::string V);
};

struct Int : Primitive {
    int value;
    Int(int N);
    std::string val();
};

struct Container : Object {
    Container(std::string V = "");
};

struct Vector : Container {
    Vector(std::string V = "");
};

struct Map : Container {
    Map(std::string V = "");
};

/// @defgroup eds Executable Data Structures
/// @brief (c) homoiconic behaviour for any data structure (code=data)
/// @{

struct Active : Object {
    Active(std::string V);
};

struct Env : Active {
    Env(std::string V);
};

/// @brief global environment
/// (vocabulary + stack + async message queue)
extern Env* glob;

/// @}

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
#define TOKEN(C, X)               \
    {                             \
        yylval.o = new C(yytext); \
        return X;                 \
    }

/// @name parser (bison)

/// parser entry
extern int yyparse();
/// syntax error callback
extern void yyerror(std::string msg);
#include "vm.parser.hpp"

/// @}
/// @}
