## 12.2.3 Fields
# [[attribute grammar]] fields
```Cpp
    /// @name attribute grammar fields

    /// @brief scalar: object name, string/number value
    std::string value;
    /// @brief associative array = env/namespace = AST attributes
    std::map<std::string, Object*> slot;
    /// @brief ordered container = vector = stack = queue = AST subtrees
    std::vector<Object*> nest;
```
