%{
    #include "lib.hpp"
    #include "syntax.hpp"
    #include "compiler.hpp"
    #include "debug.hpp"
%}

%defines %union { char c; std::string *s; uint8_t op; }

%token COLON
%token<s> ID
%token<op> CMD0 CMDa
%%
syntax:| syntax ex ;

ex  : COLON ID  { label($2,true);
                  if (debug) fprintf(stderr,"\n%.4X/%s\n\t",Cp,$2->c_str());
                  delete $2; }
    | ID COLON  { label($1,false);
                  if (debug) fprintf(stderr,"\n%.4X/%s\n\t",Cp,$1->c_str());
                  delete $1; }
    | CMD0      { compile($1);
                  if (debug) fprintf(stderr,"%.2X ",$1);
                }
    | CMDa ID   { compile($1); addr a = resolve($2); compile(a);
                  if (debug) fprintf(stderr,"%.2X %.4X ",$1,a);
                  delete($2); }
