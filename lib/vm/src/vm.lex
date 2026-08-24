%{
    #include "lib.hpp"
    #include "syntax.hpp"
    #include "vm.yacc.hpp"
    #include "command.hpp"
%}

%option noyywrap yylineno

%%
#[^\n]*                 {}              // line comment
[ \t\r\n]+              {}              // drop spaces

"nop"                   { yylval.op = (uint8_t)Op::nop ; return CMD0; }
"halt"                  { yylval.op = (uint8_t)Op::halt; return CMD0; }
"dump"                  { yylval.op = (uint8_t)Op::dump; return CMD0; }
"?"                     { yylval.op = (uint8_t)Op::dump; return CMD0; }

"jmp"                   { yylval.op = (uint8_t)Op::jmp ; return CMDa; }

":"                     {return COLON;}
[a-zA-Z_][a-zA-Z_0-9]*  {yylval.s = new std::string(yytext); return ID;}

.                       {yyerror("");}  // any undetected char
