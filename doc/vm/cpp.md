![[Cpp/main]]

```Cpp
QApplication* app = nullptr;

int main(int argc, char* argv[]) {
  app = new QApplication(argc, argv);
  init(argc, argv);
```
![[skelex/yyerror]]

#define YYERR "\n\n" << yylineno << ":" << msg << "[" << yytext << "]\n\n"
void yyerror(QString msg) {
  qDebug() << YYERR;
  exit(-1);
}

Object::Object(QString V) : value(V) {
  ref = 0;
  next = pool;
  pool = this;
}

Object::~Object() {}

Object* Object::pool = nullptr;

QString Object::dump(int depth, QString prefix) {
  QString ret;
  QTextStream s(&ret);
  // head
  s << pad(depth) << head(prefix);
  // slot{}s
  for (auto const& [k, v] : slot)
    s << v->dump(depth + 1, QString("%1 = ").arg(k));
  // subtree
  return ret;
}

QString Object::pad(int depth) {
  QString ret('\n');
  QTextStream s(&ret);
  for (int i = 0; i < depth; i++) s << '\t';
  return ret;
}

QString Object::head(QString prefix) {
  QString ret(prefix);
  QTextStream s(&ret);
  s << "<" << tag() << ":" << val() << ">";
  s << " @" << this << " #" << ref;
  return ret;
}
```
![[metaL/dump#cpp]]
![[metaL/tag]]
![[metaL/val]]
