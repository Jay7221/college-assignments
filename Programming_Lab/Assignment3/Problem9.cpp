#include<iostream>
using namespace std;
class String{
	public:
		int n;
		char *s;
		String(){
			n = 0;
			s = new char[1];
			s[0] = '\0';
		}
		String(const string &obj){
			n = obj.size();
			s = new char[n + 1];
			for(int i = 0; i < n; ++i){
				s[i] = obj[i];
			}
			s[n] = '\0';
		}
		bool operator == (const String &obj){
			int nn = obj.n;
			if(n != nn)
				return false;
			for(int i = 0; i < n; ++i){
				if(s[i] != obj.s[i])
					return false;
			}
			return true;
		}
		friend ostream &operator<<(ostream &out, const String &obj){
			for(int i = 0; i < obj.n; ++i){
				out << obj.s[i];
			}
			return out;
		}
};
int main(){
	String s("Hello"), s1("Hello WOrld"), s2("Hello");
	if(s == s2){
		cout << s << " = " << s2 << endl;
	}
	if(s == s1){
		cout << s << " = " << s1 << endl;
	}
	else{
		cout << s << " != " << s1;
	}
	cout << endl;
	return 0;
}
