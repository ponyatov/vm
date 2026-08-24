/// @defgroup syntax syntax
/// @brief `flex`/`bison` syntax parsers interface
/// @ingroup lib
/// @{
#pragma once

#include "lib.hpp"

/// @defgroup lexer lexer
/// @{
extern int yylex();   ///< lexer
extern char* yyfile;  ///< current file name
extern char* yytext;  ///< current lexeme value
extern int yylineno;  ///< current line number
extern FILE* yyin;    ///< current file handler
                      /// @}

/// @defgroup parser parser
/// @{
extern int yyparse();                  ///< parser
extern void yyerror(const char* msg);  ///< syntax error callback
/// @}

// #include "vm.lex.hpp"
// #include "vm.yacc.hpp"

/// @}
