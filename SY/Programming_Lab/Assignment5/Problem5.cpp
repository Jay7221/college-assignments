#include<iostream>
using namespace std;
class E{
	public:
		string message;
		E(string m) : message(m){}
};
double divide(double a, double b){
	if(b == 0)
		throw E("Divide by Zero");
	return (a / b);
}
void input(double &x, double &y){
	cin >> x;
	if(!cin.good())
		throw E("Input not a number");
	cin >> y;
	if(!cin.good()){
		throw E("Input not a number");
	}
}
int main(){
	double a, b;
	cout << "Enter two numbers : ";
	try{
		input(a, b);
		cout << divide(a, b) << endl;
	}
	catch(E e){
		cout << "Exception : " << e.message << endl;
	}
	return 0;
}
