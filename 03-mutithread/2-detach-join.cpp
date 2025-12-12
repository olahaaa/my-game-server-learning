#include <thread>
#include <iostream>
//启动线程后要显示的决定是等待它完成还是分离它，如果在thread对象销毁前未决定则程序会被终止
//只需在thread对象销毁前决定，而线程本身可能早就在你决定前就结束了，也可能在thread对象销毁很久后还在运行

void do_something(){};
struct func{
    int& i;
    func(int i_): i(i_){}
    void operator() (){
        for(int j=0; j < 100; j++){
            do_something();
        }
    }
};
//1
//如果不等待线程完成，需要确保在线程完成前通过该线程访问的数据有效
//在一个访问局部变量的函数中创建线程是一个糟糕的主意，你得保证在函数退出前线程完成，否可可能会访问到已销毁对象
void oops(){
    int x = 0;
    func my_func(x);
    std::thread my_thread4(my_func);
    my_thread4.detach(); //分离线程
} //创建完thread并分离后oops就结束了，其局部变量被销毁，但my_thread4仍会访问已销毁变量


//2
//将my_thread4.detach();改为my_thread4.join();可确保在oops函数退出前线程已结束

//3 在析构函数中进行join
//
class thread_guard{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):t(t_){}
    thread_guard(const thread_guard &) = delete;
    thread_guard operator= (const thread_guard &) = delete;

    ~thread_guard(){    //将join放在析构函数中，这样当对象被销毁前就能join操作
        if(t.joinable()) //每个线程只能join一次，先用joinable检查能否join；detach也用这个检查
            t.join();
    }
};

void f(){
    int x;
    func my_func(x);
    std::thread t(my_func);
    thread_guard g(t);
    do_something();
}  //当f执行完毕，销毁对象g时会在析构函数中对线程t进行join；即使因dosometing函数异常引发退出也不会影响

//4 使用detach分离线程后，无法再通过thread对象的引用获得该线程
