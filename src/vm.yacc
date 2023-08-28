/// @file
/// @brief syntax parser (`bison`)
%{
    #include "vm.hpp"
%}

%defines %union { Object *o; }

%type  <o> ex
%token <o> SYM

%%
syntax  :
        | syntax ex { std::cout << $2->dump() << std::endl; }

ex : SYM
