#include<iostream>
using namespace std;
template<class T>
T max_of(T a, T b){
	if(a > b)
		return a;
	return b;
}
int main(){
	int a, b;
	cin >> a >> b;
	cout << max_of(a, b) << endl;
	return 0;
}
