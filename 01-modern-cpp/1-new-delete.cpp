#include <iostream>
using namespace std;

int main(){
    int a = 1; //a是编译时分配在栈的有名称的内存，可以通过变量名访问，也可以通过指针访问
    int* pt = new int; //new在运行时分配无名称的内存，此时仅能通过指针访问
    *pt = 2;
    double* pd = new double;
    *pd = 3.14;

    //usage:
    //typename * name = new typename;  delete name;
    //typename * name[] = new typename[size];  delete name[];

    cout << "a: " << a << "->" << &a << endl;
    cout << "pt: " << *pt << "->" << pt << endl;
    cout << "pd: " << *pd << "->" << pd << endl;
    
    delete pt; //配合new使用，释放new分配的内存
    delete pd; //不要用delete释放不是new分配的内存，不要重复释放，对空指针使用delete是安全的

    //动态数组
    int array[10]; //编译时分配数组，不论用没用都存在 静态联编
    int *parr = new int[10]; //动态联编

    cout << "静态数组头指针: " << array << endl;
    cout << "动态数组头指针: " << parr << endl;

    delete[] parr; //释放new[]分配的内存时要用delete[]

    return 0;
}