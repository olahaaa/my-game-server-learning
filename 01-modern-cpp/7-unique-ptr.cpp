#include <iostream>
#include <string>
#include <memory>

int main(){
    std::unique_ptr<std::string> pu(new std::string("uniqueptr-str"));
    std::unique_ptr<std::string> pu2;
    //pu2 = pu; uniqueptr是独享指针，不能同时指向同一内存
    std::cout << *pu << std::endl;
    pu2 = std::move(pu); //move转移指针所有权
    //pu为空指针
    std::cout << *pu2 << std::endl;

    //使用new时 才能使用sharedptr, uniqueptr
    //使用new []时，才能使用uniqueptr，不能使用sharedptr

    return 0;
}

