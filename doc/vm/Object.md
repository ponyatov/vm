# `Object`
## base object (hyper)graph node

```Cpp
/// @defgroup core core
/// @brief object (hyper)graph core
```
```Cpp
/// @brief base object (hyper)graph node
/// @ingroup core
struct Object {
};
```
![[Object.hpp]]
![[metaL/fields]]
![[gc/hpp]]

```py
class Object:
```
![[metaL/gc]]
![[metaL/constructor]]
![[metaL/dump]]
![[metaL/stringify]]
![[metaL/operator]]


### js

```js
class Object {
  constructor(V) {
    return {
      /// type/class tag
      type: Object.name.toLowerCase(),
      /// scalar: object name, number/string value
      value: V,
      /// ordered container = vector = stack = nested AST subtree
      nest: []
    }
  }
}
```
