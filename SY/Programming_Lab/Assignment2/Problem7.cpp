#include<iostream>
using namespace std;
double pow(double m, int n = 2){
	double ans = 1;
	for(int i = 0; i < n; ++i){
		ans *= m;
	}
	return ans;
}
int pow(int m, int n = 2){
	int ans = 1;
	for(int i = 0; i < n; ++i){
		ans *= m;
	}
	return ans;
}
int main(){
	cout << pow(4.4, 3) << endl;
	cout << pow(4.4) << endl;
	cout << pow(34, 4) << endl;
	cout << pow(34) << endl;
	return 0;
}
