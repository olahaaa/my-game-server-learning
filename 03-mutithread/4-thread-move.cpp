#include <thread>

void some_function(){}
void some_other_function(){}

int main(){
    std::thread t1(some_function);
    std::thread t2 = std::move(t1); //t1是左值，是具名对象，移动所有权需要显示的调用move
    t1 = std::thread(some_other_function); //对临时对象进行所有权移动是自动的
    std::thread t3;
    t3 = std::move(t1);
    //t1 = std::move(t3); 不可以转移线程所有权给经有调用对象的线程


    return 0;
}
