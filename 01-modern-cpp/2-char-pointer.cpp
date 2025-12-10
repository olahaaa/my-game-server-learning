#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char animal[10] = "bear";
    const char *bird = "eagle";
    char* ps;

    cout << "str animal: " << animal << endl; //char指针在使用cout输出时会输出为字符串内容
    cout << "str bird: " << bird << endl;
    cout << "address of animal: " << (int *)animal << endl; //要输出地址需强制转换
    cout << "address of bird: " << (int *)bird << endl;

    ps = animal;
    cout << "cotent of ps after ps = animal:" << "->" << ps << endl;
    cout << "before strcpy address of ps: " << (int *)ps << endl;

    cin >> animal;
    cout << "new str animal: " << animal << endl;
    ps = new char[strlen(animal) + 1]; //动态分配新字符串地址,准备制作副本字符串
    //new新分配的内存现在只有ps能访问，千万不能更改ps的值，否则会内存泄漏
    //不能ps = animal;
    ps = strcpy(ps, animal); //strcpy(复制到哪里的地址，复制源地址)
    cout << "cotent of ps after strcpy:" << "->" << ps << endl;
    cout << "after strcpy address of ps: " << (int *)ps << endl;

    delete [] ps;
    return 0;
}