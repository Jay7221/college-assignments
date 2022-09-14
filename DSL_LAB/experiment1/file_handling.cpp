#include<iostream>
#include<curses.h>
using namespace std;
int main(){
    FILE* f = fopen("text.txt", "r");
    char ch = getc(f);
    while(ch != EOF){
        cout << ch;
        ch = getc(f);
    }
    cout << endl;
}