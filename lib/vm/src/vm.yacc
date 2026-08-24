%{
    #include "syntax.hpp"
    #include "compiler.hpp"
    #include "debug.hpp"
%}

%defines %union { char c; std::string *s; uint8_t op; }

%token COLON
%token<s> ID
%token<op> CMD0
%%
syntax:| syntax ex ;

ex  : COLON ID  { label[*$2] = Cp;
                  if (debug) fprintf(stderr,"\n%.4X: %s\t",Cp,$2->c_str());
                  delete $2; }
    | CMD0      { compile($1);
                  if (debug) fprintf(stderr,"%.2X ",$1);
                }
