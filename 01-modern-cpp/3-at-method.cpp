#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "v[]:" << v[1] << endl;
    cout << "v.at():" << v.at(1) << endl;
    return 0;
}