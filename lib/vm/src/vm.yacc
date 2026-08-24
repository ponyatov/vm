%{
    #include "syntax.hpp"
    #include "compiler.hpp"
    #include "debug.hpp"
%}

%defines %union { char c; std::string *s; }

%token COLON
%token<s> ID
%%
syntax:| syntax ex ;

ex  : COLON ID  { label[*$2] = Cp;
                  if (debug) fprintf(stderr,"%.4X: %s\n",Cp,$2->c_str());
                  delete $2; }
