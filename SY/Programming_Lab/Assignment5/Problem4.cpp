#include<iostream>
using namespace std;
class E{
	public:
	string message;
	E(string s) : message(s){}
};
int divide(int a, int b){
	int d;
	if(b == 0)
		throw E("Divison by zero");
	d = a / b;
	return d;
}
void calc(int x, int k){
	try{
		int d = divide(x, k);
		cout << "The division of x and k is : " << d << endl;
	}
	catch(E e){
		throw e;
	}
}
int main(){
	int x, y;
	cin >> x >> y;
	try{
		calc(x, y);
	}
	catch(E e){
		cout << "Exception : " << e.message << endl;
	}
	return 0;
}
