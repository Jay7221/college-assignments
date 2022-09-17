#include<iostream>
#include<string.h>
using namespace std;
class String{
    public:
    int n;
    char *s;
    public:
    String(){
        n = 0;
        s = new char[1];
        s[0] = '\0';
    }
    String(const string& str){
        n = str.size();
        cout << str << endl;
        s = new char[n + 1];
        for(int i = 0; i < n; ++i){
            s[i] = str[i];
        }
    }
    String(const String& str){
        n = str.n;
        s = new char[n];
        strcpy(s, str.s);
    }
    int size(){
        return n;
    }
    friend ostream &operator<<(ostream& os, const String& S){
        for(int i = 0; i < S.n; ++i){
            os << S.s[i];
        }
        return os;
    }
    String operator + (String const &obj){
        String ans;
        strcat(obj.s, ans.s);
        strcat(s, ans.s);
        return ans;
    }
};

int main(){
    String s("Hello");
    String s2("World");
    String sum = s + s2;
    cout <<sum ;
    return 0;
}