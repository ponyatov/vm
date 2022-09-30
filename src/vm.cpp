/// @file
#include "vm.hpp"

void arg(int argc, char* argv) {
  cout << "argv[" << argc << "] = <" << argv << ">\n";
}

int main(int argc, char* argv[]) {
  init(argc, argv);
  arg(0, argv[0]);
  for (auto i = 1; i < argc; i++) {
    arg(i, argv[i]);
    assert(yyin = fopen(argv[i], "r"));
    yyfile = argv[i];
    yyparse();
    fclose(yyin);
  }
  return fini(0);
}

#define YYERR                                                                \
  "\n\n"                                                                     \
      << yyfile << ":" << yylineno << ":" << yycolumn << ": " << msg << " [" \
      << yytext << "]\n\n"
void yyerror(string msg) {
  cerr << YYERR;
  fini(-1);
}

Object::Object(string V) { value = V; }
Object::~Object() {}

string Object::dump(int depth, string prefix) {
  ostringstream os;
  os << pad(depth) << head(prefix);
  return os.str();
}

string Object::head(string prefix) {
  ostringstream os;
  os << prefix << '<' << tag() << ':' << val() << "> @" << this;
  return os.str();
}

string Object::pad(int depth) {
  ostringstream os("\n");
  for (auto i = 0; i < depth; i++) os << '\t';
  return os.str();
}

#include <cxxabi.h>
string Object::tag() {
  string ret = abi::__cxa_demangle(typeid(*this).name(), 0, 0, nullptr);
  for (char& c : ret) c = tolower(c);
  return ret;
}

string Object::val() { return value; }

Primitive::Primitive(string V) : Object(V) {}
Sym::Sym(string V) : Primitive(V) {}

Container::Container(string V) : Object(V) {}
Map::Map(string V) : Container(V) {}

Active::Active(string V) : Object(V) {}
VM::VM(string V) : Active(V), Map(V) {}

VM* vm = nullptr;

void init(int argc, char* argv[]) {
  assert(vm = new VM("vm"));
  ((Active*)vm)->set("argc", new Int(argc));
  cout << ((Active*)vm)->dump() << "\n\n";
}

int fini(int errorlevel) { exit(errorlevel); }
