#include <thread>
#include <iostream>

//线程从构造一个thread类开始，该类指定了线程上运行的任务
//1 最简单的线程
void do_some_work();
std::thread my_thread(do_some_work);

//2 thread可以和任何可调用类型工作，所以可以传递给thread一个重载了函数操作符的类的实例
//函数对象被复制到新线程的存储器中，并从那里调用
class background_task{
public:
    void operator()() const{
        do_some_work();
    }
};
background_task f;
std::thread my_thread2(f);
//std::thread my_thread(background_task()); 不要传递临时未命名的变量，容易有歧义(可解释为一个函数声明)
//可使用std::thread my_thread{background_task()};

//3 lamda表达式
std::thread my_thread3([] () {do_some_work();});

