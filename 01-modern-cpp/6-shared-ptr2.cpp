#include <iostream>
#include <string>
#include <memory>


int main(){
    double* preg = new double;
    std::shared_ptr<double> pd;
    //pd = preg; 隐式转换不合法，sharedptr的构造有explict修饰
    pd = std::shared_ptr<double>(preg); //sharedptr构造函数的参数是指针

    //std::shared_ptr<double> pshared = preg; 同上，explict不允许隐式转换
    std::shared_ptr<double> pshared(preg);
    //智能指针是一个模板，指针是一个类型
    //相同类型的sharedptr可以赋值
    std::shared_ptr<double> pshared2 = pshared;

    return 0;
}

