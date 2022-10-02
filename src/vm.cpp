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

//////////////////////////////////////////////////////////////////////// Object

Object* Object::pool = nullptr;

Object::~Object() {}

Object::Object() {
  prev = pool;
  pool = this;
  ref = 0;
}

Object::Object(string V) : Object() {  //
  value = V;
}

string Object::dump(int depth, string prefix) {
  ostringstream os;
  // head
  os << pad(depth) << head(prefix);
  // slot
  for (auto const& [key, that] : slot) {
  }
  // subtree
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

Object* Object::set(string key, Object* that) {
  slot[key] = that;
  return this;
}

///////////////////////////////////////////////////////////////////// Primitive

Primitive::Primitive() : Object() {}
Primitive::Primitive(string V) : Object(V) {}

Sym::Sym(string V) : Primitive(V) {}

Int::Int(int N) : Primitive() { value = N; }
string Int::val() { return to_string(value); }

Container::Container(string V) : Object(V) {}
Map::Map(string V) : Container(V) {}

Active::Active(string V) : Object(V) {}
Env::Env(string V) : Active(V) {}

Env* glob = nullptr;

void init(int argc, char* argv[]) {
  assert(glob = new Env("global"));
  glob->set("argc", new Int(argc));
  cout << glob->dump() << "\n\n";
}

int fini(int errorlevel) { exit(errorlevel); }
