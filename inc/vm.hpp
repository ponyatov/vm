#pragma once

#include <assert.h>

#include <iostream>

using namespace std;

// object graph
struct Object {};
struct Primitive : Object {};

// skelex
// lexer
extern int yylex();
extern int yylineno,yycol;
extern char* yytext;
extern char* yyfile;
extern FILE* yyin;
// parser
extern int yyparse();
extern void yyerror(string msg);
