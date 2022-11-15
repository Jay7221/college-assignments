#include<iostream>
using namespace std;
void drive(int age){
	if(age < 18)
		throw 404;
	if(age > 50)
		throw "Too old to drive";
	else
		cout << "Driving";
}
int main(){
	int age;
	for(int i = 0; i < 2; ++i){
		cout << "Enter age : ";
		cin >> age;
		try{
			drive(age);
		}
		catch(int x){
			cout << "Exception number : " << x << endl;
		}
		catch(...){
			cout << "Default Exception" << endl;
		}
	}
	return 0;
}
