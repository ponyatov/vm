#include "vm.hpp"

void arg(int argc, char* argv) {
  cout << "argv[" << argc << "] = <" << argv << ">\n";
}

int main(int argc, char* argv[]) {
  arg(0, argv[0]);
  for (auto i = 1; i < argc; i++) {
    arg(i, argv[i]);
    assert(yyin = fopen(argv[i], "r"));
    yyfile = argv[i];
    yyparse();
    fclose(yyin);
  }
  return 0;
}

#define YYERR "\n\n" << yyfile<<":"<<yylineno << ":" <<yycol<<":"<< msg << "[" << yytext << "]\n\n"
void yyerror(string msg) {
  cerr << YYERR;
  exit(-1);
}
