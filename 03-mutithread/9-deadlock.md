# deadlock
通常在需要锁定两个及以上互斥元时出现

## std::lock可以同时锁定多个互斥元而没有死锁的风险
```
class some_big_object
void swap(some_big_object& lhs,some_big_object& rhs);

class X
{
private:
  some_big_object some_detail
  std::mutex m;
public:
  X(some_big_object const& sd):some_detail(sd){}

  friend void swap(X& lhs, X& rhs)
  {
    if(&lhs==&rhs)
      return true
    std::lock(lhs.m, rhs.m); //同时锁定两个互斥元
    std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock); //lockguard沿用锁不重复锁定
    std::lock_guard<std::mutex> lock_a(rhs.m, std::adopt_lock);
    swap(lhs.some_detail, rhs.some_detail);
  };
}
```
std::lock的互斥元要么全部锁定，若异常销毁则全部释放
std::adopt_lock作为lock_guard的额外参数，告诉该对象该互斥元已锁定，避免重复锁定。lockguard沿用互斥元上已有锁的所有权

## std::unique_lock灵活锁定
std::unique_lock可以被传递给std::lock对象
```
class some_big_object
void swap(some_big_object& lhs,some_big_object& rhs);

class X
{
private:
  some_big_object some_detail
  std::mutex m;
public:
  X(some_big_object const& sd):some_detail(sd){}

  friend void swap(X& lhs, X& rhs)
  {
    if(&lhs==&rhs)
      return true
    std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock); //std::defer_lock保留互斥元为未锁定态
    std::unique_lock<std::mutex> lock_a(rhs.m, std::defer_lock);
    std::lock(lock_a, lock_b)
    swap(lhs.some_detail, rhs.some_detail);
  };
}
```