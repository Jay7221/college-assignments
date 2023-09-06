#include<iostream>
using namespace std;
void doSomething(int x){
	if(x < 0)
		throw x;
	if(x > 100)
		throw "Greater than 100";
	if(x % 2 == 0)
		throw 'e';
	cout << "x is non-negative, odd, less-than or equal to 100" << endl;
}
int main(){
	for(int i = 0; i < 3; ++i){
		int n;
		cin >> n;
		try{
			doSomething(n);
		}
		catch(...){
			cout << "An exception occured" << endl;
		}
	}
	return 0;
}
