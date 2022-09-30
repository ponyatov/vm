%{
    #include "vm.hpp"
    char* yyfile;
    int yycol=1;
%}

%option noyywrap yylineno

%%
.       {yyerror("lexer");}
