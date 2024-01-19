#include<iostream>
using namespace std;
const int LOGMAX = 32;
void sayHello_stack(){
    long long a = 1, b = 4, c = 7;
    cout << &a << '\n' << &b << '\n' << &c << '\n';
    cout << a << '\n' << b << '\n' << c << '\n';
}
void sayHello_heap(){
    int *p = new int{5};
    cout << p << '\n' << *p << '\n';
}
int main(){
    sayHello_stack();
    sayHello_stack();
    sayHello_stack();
    sayHello_heap();
    sayHello_heap();
    sayHello_heap();
}
