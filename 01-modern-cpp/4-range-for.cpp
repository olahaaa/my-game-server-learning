#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    for(auto i : v){
        cout << "1i: " << i << endl;
    }

    for(auto &i : v){ //引用方式修改容器内元素
        i *= 5;
        cout << "2i: " << i << endl;
    }

    for(auto i : {1.2,2.3,3.4,4.5,5.6}){
        cout << "3i: " << i << endl;
    }
    
}