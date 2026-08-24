### cpp
```Cpp
string Object::pad(size_t depth) {
    ostringstream ret;
    ret << endl;
    for (int i = 0; i < depth; i++) ret << '\t';
    return ret.str();
}
```
