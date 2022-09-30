/// @file
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

#define YYERR                                                             \
  "\n\n"                                                                  \
      << yyfile << ":" << yylineno << ":" << yycol << ": " << msg << " [" \
      << yytext << "]\n\n"
void yyerror(string msg) {
  cerr << YYERR;
  exit(-1);
}

Object::Object(char* V) { value = V; }
Object::~Object() {}

string dump(int depth, string prefix) {
  ostringstream os;
  os << pad(depth) << head(prefix);
  return os.str();
}

#include <cxxabi.h>
string Object::tag() {
  string ret = abi::__cxa_demangle(typeid(*this).name(), 0, 0, nullptr);
  for (char& c : ret) c = tolower(c);
  return ret;
}

string Object::val() { return value; }

Primitive::Primitive(char* V) : Object(V) {}
Sym::Sym(char* V) : Primitive(V) {}
