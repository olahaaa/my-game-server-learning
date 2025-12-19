#include <mutex>
#include <iostream>
#include <thread>
#include <chrono>

std::mutex mtx;
int shared_data = 0;

//最简使用 lockguard生命周期在{}作用域内，离开作用域自动解锁
// void foo()
// {
//     {
//         std::lock_guard<std::mutex> lock(m); // 创建 std::lock_guard 对象
//         // 在这个代码块中，互斥锁 m 被锁定
//         // 执行一些需要互斥访问的代码
//     } // std::lock_guard 对象在这里销毁，互斥锁 m 被解锁
//     // 在这个代码块外，无法访问锁 m
// }


void worker(int id){
    
    for(int i=0;i<5;++i){
        std::lock_guard<std::mutex> lock(mtx);
        shared_data++;
        std::cout << "worker:" << id << " modified shared_data to " << shared_data << std::endl;
    }
    std::cout << "worker:" << id << " released lock." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main(){
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);

    t1.join();
    t2.join();
    std::cout << "all threads done" << std::endl;
    return 0;
}