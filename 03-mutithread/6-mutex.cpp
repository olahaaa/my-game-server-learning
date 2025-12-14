#include <mutex>
#include <list>
#include <algorithm>

std::list<int> some_list;
std::mutex some_mutex; //互斥元mutex
//std::lock_guard模板，在构造时锁定给定的互斥元，析构时解锁

//在所有访问somelist的函数中用some_mutex标记进行保护，同样持有some_mutex的函数不能同时进行
void add_to_link(int new_value){ //写操作：加锁 → 修改 → 自动解锁
    std::lock_guard<std::mutex> my_guard(some_mutex); 
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find){ //读操作：加锁 → 读取 → 自动解锁
    std::lock_guard<std::mutex> my_guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

//如果一个函数返回受保护数据的指针或引用，那么能够访问修改该指针或引用的函数可以无需锁定互斥元而直接访问受保护的数据
//应仔细设计接口，确保任何代码访问受保护的数据前已锁定互斥元；
//确保没有任何函数通过返回值或输出参数返回受保护数据的指针/引用
//此外，还要防止向不在掌控下的函数传入受保护数据的指针/引用
