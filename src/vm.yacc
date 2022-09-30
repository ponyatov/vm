/// @file
%{
    #include "vm.hpp"
%}

%defines %union { Object *o; }

%type  <o> ex
%token <o> SYM

%%
syntax  :
        | syntax ex { cout << $2->dump(); }

ex : SYM
