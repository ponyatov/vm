# garbage collection

##### minimal
```Cpp
class Object {
  /// @name garbage collection
  /// @{
  size_t ref;           /// reference counter
  static Object* pool;  /// global @ref Object pool
  Object* next;         /// next object in linked list
  static void gc();     /// garbage collection pass
  /// @}
```
##### 
![[metaL/constructor#C]]

- [[metaL/gc]]
	- [[metaL/ref]]
	- [[metaL/pool]]
	- [[metaL/next]]
