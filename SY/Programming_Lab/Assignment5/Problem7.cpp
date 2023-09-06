#include<iostream>
using namespace std;
class E{
	public:
		string message;
		E(string m) : message(m){}
};
void checkTemp(double t){
	if(t > 50)
		throw E("Temperature Threshold Exceded");
}
void validateAge(int a){
	if(a > 20)
		throw E("Not a teenager");
	cout << "Valid" << endl;
}
int main(){
	int age, temp;
	cout << "Enter temperature : " ;
	cin >> temp;
	try{
		checkTemp(temp);
	}
	catch(E e){
		cout << "Exception : " << e.message << endl;
	}
	cout << "Enter age : ";
	cin >> age;
	try{
		validateAge(age);
	}
	catch(E e){
		cout << "Exception : " << e.message << endl;
	}
	return 0;
}
