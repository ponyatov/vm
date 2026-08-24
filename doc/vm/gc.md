# gc
## garbage collector

## principles

- allocates heap in a [[VAT]] memory
- thread-local [[vm/gc|gc]] in every isolated thread (no memory shared between threads)
- single & very fast heap drop for every thread stop

## 

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
