%{
    #include "vm.hpp"
    #include "vm.parser.hpp"

    char* yyfile = nullptr;

    #define TOKEN(C, X)               \
        {                             \
            yylval.o = new C(yytext); \
            return X;                 \
        }
%}

%option noyywrap yylineno

s [+\-]
n [0-9]+
%%
#.*                     {}                      // line comment
[ \t\r\n\f]+            {}                      // drop spaces
":"                     {TOKEN(Op,COLON);}      // :
";"                     {TOKEN(Op,SEMICOLON);}  // ;
{s}{n}                  {TOKEN(Int,INT);}       // integer
[_a-zA-Z][_a-zA-Z0-9]*  {TOKEN(Sym,SYM);}       // symbol
.                       {yyerror("");}          // undetected char error
