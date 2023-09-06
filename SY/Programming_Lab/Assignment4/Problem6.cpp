#include<iostream>
using namespace std;
template<class T>
T sum(T a, T b){
	return (a + b);
}
template<class T>
T sum(T a, T b, T c){
	return (a + b + c);
}
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << sum(a, b) << endl;
	cout << sum(a, b, c) << endl;
	return 0;
}
