#include<iostream>
using namespace std;
void swap(int *a, int *b){
	int x = *a, y = *b;
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	*a = x, *b = y;
}
int main(){
	int *a, *b;
	int x, y;
	cin >> x >> y;
	a = &x, b = &y;
	swap(a, b);
	cout << *a << ' ' << *b << endl;
}