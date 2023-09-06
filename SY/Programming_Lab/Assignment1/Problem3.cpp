#include<iostream>
using namespace std;
int main(){
	double a, b, c, d;
	cin >> a >> b >> c;
	d = a + b;
	double x = a * b - (c / d);
	if(d == 0){
		cout << "Value of d is zero" << endl;
	}
	else{
		cout << x << endl;
	}
}