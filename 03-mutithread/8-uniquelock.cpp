#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;

void worker1() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for the duration of this scope
    std::cout << "Worker 1 has acquired the lock." << std::endl;
    // do something
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Worker 1 is releasing the lock." << std::endl;
} //lockguard不支持手动解锁，离开作用域自动解锁

void worker2() {
    std::unique_lock<std::mutex> ulock(mtx); // Lock the mutex with unique_lock
    std::cout << "Worker 2 has acquired the lock." << std::endl;
    // do something
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Worker 2 is releasing the lock." << std::endl;
    ulock.unlock(); //uniquelock支持手动解锁
} //若没有手动解锁，离开作用域也会自动解锁

int main() {
    std::thread t1(worker1);
    std::thread t2(worker2);

    t1.join();
    t2.join();

    std::cout << "Both workers have finished." << std::endl;
    return 0;
}

/*
unique_lock 可以实现比 lock_guard 更灵活的锁操作。
lock_guard 是不可移动的（moveable），即不能拷贝、赋值、移动，只能通过构造函数初始化和析构函数销毁，
unique_lock 是可移动的，可以拷贝、赋值、移动。
unique_lock 提供了更多的控制锁的行为，比如锁超时、不锁定、条件变量等。
unique_lock 比 lock_guard 更重,有更多的功能，更多的开销。
如果只需要简单的互斥保护，使用 lock_guard 更好。*/