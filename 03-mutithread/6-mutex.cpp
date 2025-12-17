#include <mutex>
#include <list>
#include <algorithm>

//1
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

//2
//如果一个函数返回受保护数据的指针或引用，那么能够访问修改该指针或引用的函数可以无需锁定互斥元而直接访问受保护的数据
//应仔细设计接口，确保任何代码访问受保护的数据前已锁定互斥元；
//确保没有任何函数通过返回值或输出参数返回受保护数据的指针/引用
//此外，还要防止向不在掌控下的函数传入受保护数据的指针/引用

class some_data{
    int a;
    std::string b;
public:
    void do_something(); //...
};

class data_wrapper{
    some_data data;
    std::mutex m;
public:
    template<typename Function>
    void process_data(Function func){ //通过回调函数访问受保护数据
        std::lock_guard<std::mutex> my_guard(m);
        func(data); //func又没有将受保护的数据的引用/指针传出去？使得其他函数不用所就可以访问data
    }
};

some_data* unprotected_data;
void malicious_function(some_data & protected_data){
    unprotected_data = &protected_data; //保存受保护数据的指针
}

data_wrapper x;
void foo(){
    x.process_data(malicious_function); //传入恶意函数
    //现在unprotected_data指向受保护的数据，可以在没有锁定互斥元的情况下访问它
    unprotected_data->do_something();
}