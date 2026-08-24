# Object.hpp

![[gc/ref/hpp#head]]
```Cpp
/// @ingroup metal
/// @brief   Graph node
struct Object {
    /// @name fields

    /// scalar: object name, string/number value
    QString value;
    /// ordered container = vector = stack = queue = AST subtrees
    vector<Object*> nest;
    /// associative array: map = AST attributes
    map<QString, Object*> slot;
```
![[gc/ref/hpp#vm/Object Object]]
```Cpp
    /// @name constructor
    
    Object();               ///< construct with empty @ref value
    Object(QString value);  ///< construct with name
    virtual ~Object();      ///< clean up for nested elements
```
![[vm/stringify#hpp]]
![[vm/operator#hpp]]
###
```Cpp
};
```

[[metaL/object graph]]

```Cpp

public:
  /// @name attributed grammar fields

  /// scalar: object name, string/number value
  QString value;

  /// associative array = env/namespace = AST attributes
  map<QString, Object*> slot;

  /// ordered container = vector = stack = queue = AST subtrees
  vector<Object*> nest;

```
