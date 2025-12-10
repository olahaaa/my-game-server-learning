#include <iostream>
#include <string>
#include <memory>

class Report{
private:
    std::string str;
public:
    Report(const std::string s): str(s) {
        
        std::cout << "object created" << std::endl;
    }
    ~ Report(){
        std::cout << "object delete" << std::endl;
    }
    void comment() const{
        std::cout << str << std::endl;
    }
};

int main(){
    std::shared_ptr<Report> sp (new Report("using shared ptr"));
    sp->comment();

    std::unique_ptr<Report> up (new Report("using unique ptr"));
    up->comment();

    return 0;
}

