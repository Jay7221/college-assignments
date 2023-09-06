#include<iostream>
using namespace std;
template<class T>
void swap_val(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}
int main(){
	int a, b;
	cin >> a >> b;
	swap_val(a, b);
	cout << a << ' ' << b << endl;
	return 0;
}
