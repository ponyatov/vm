%{
    #include "vm.hpp"
    char* yyfile;
    int yycol=1;
%}

%option noyywrap yylineno

%%
#.*             {}                      // line comment
[ \t\r\n]+      {}                      // drop spaces
[^ \t\r\n]+    TOKEN(Sym,SYM)          // symbol
.               {yyerror("lexer");}     // any undetected char
