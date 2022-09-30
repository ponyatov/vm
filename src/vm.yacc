/// @file
%{
    #include "vm.hpp"
%}

%defines %union { Object *o; }

%token <o> SYM

%%
syntax  :
        | syntax ex

ex : SYM
