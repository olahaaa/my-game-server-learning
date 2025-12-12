#include <iostream>
#include <string>
using namespace std;

int main(){
    string one("how to make a str");
    cout << one << endl;

    string two(20, '*');
    cout << one << endl;

    string three(one);
    one += " oops!";
    one += two;
    one += '!';
    cout << three[0] << endl;

    string four;
    four = one + two;
    cout << four << endl;

    char alls[] = "this is a c str";
    string five(alls,10);
    cout << five << endl;

    string six(alls, alls+6); //广义上的指针都可以
    cout << six << endl;

    //string seven(six+1, six+5); six是对象不是指针
    string seven(&six[3], &six[6]);
    cout << seven << endl;

    string eight(seven, 1, 5);
    cout << eight << endl;

    return 0;
}
