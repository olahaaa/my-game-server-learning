#include <iostream>
#include <vector>

int main() {
    std::vector<int> v(5);
    int n;
    std::cin >> n;
    std::vector<int> v2(n); //动态内存分配
    v2[0] = 1;
    for(auto i: v2){
        std::cout << i;
    }
    std::cout << std::endl;

    std::vector<double> v3(5);
    std::vector<double>::iterator it = v3.begin(); //声明一个迭代器
    // auto it = v3.begin(); 直接auto
    for(it = v3.begin(); it != v3.end(); it++){ //end是超尾，即容器最后一个元素的后一个元素
        std::cout << *it;
    }
    std::cout << std::endl;

    std::vector<double> vd; //自动扩容
    double temp;
    while(std::cin >> temp && temp >= 0){
        vd.push_back(temp);
    }
    std::cout << "size of vd: " << vd.size() << std::endl;

    std::vector<int> vold = {1,2,3,4,5};
    std::vector<int> vnew = {1,4,9,16,25};
    vold.erase(vold.begin(), vold.begin()+2);
    for(auto i : vold){
        std::cout << i;
    }
    std::cout << std::endl;
    vnew.insert(vnew.end(), vold.begin(), vold.end());
    for(auto i : vnew){
        std::cout << i;
    }

    return 0;
}