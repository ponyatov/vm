### cpp

```Cpp
string Object::head(string prefix) {
    std::ostringstream ret;
    ret << prefix;                               // prefix
    ret << '<' << tag() << ':' << val() << '>';  // <T:V>
    ret << " @" << this << " #" << ref;          // allocation
    return ret.str();
}
```
