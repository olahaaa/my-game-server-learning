#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(double x){
        cout << x << ' ';
    }

int main(){
    vector<double> v = {1, 12.4, 6.28, 28.26, 3.14};
    
    for_each(v.begin(), v.end(), show); //for_each第三个参数为函数对象，必须是不能修改容器元素值的函数
    cout << endl;
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), show);
    return 0;
}