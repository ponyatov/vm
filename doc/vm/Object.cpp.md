## [[lang/garbage collection|garbage collection]]

```Cpp
Object* Object::pool = nullptr;
```
```Cpp
Object::Object() { ref = 0; next = pool; pool = this; }
```
```Cpp
Object::Object(string value) : Object() { this->value = value; }
```
```Cpp
Object::~Object() { pool = next; }
```

## operator

```Cpp
Object* Object::set(QString key, Object* o) {
    slot[key] = o;
    return this;
}
```
```Cpp
Object* Object::get(QString key) { return slot[key]; }
```
### index
```Cpp
Object* Object::operator[](const std::string& key) {
    return slot[QString::fromStdString(key)];
}
```
