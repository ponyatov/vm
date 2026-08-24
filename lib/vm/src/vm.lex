%{
    #include "syntax.hpp"
    #include "vm.yacc.hpp"
%}

%option noyywrap yylineno

%%
#[^\n]*                 {}              // line comment
[ \t\r\n]+              {}              // drop spaces

":"                     {return COLON;}
[a-zA-Z_][a-zA-Z_0-9]*  {yylval.s = new std::string(yytext); return ID;}

.                       {yyerror("");}  // any undetected char
