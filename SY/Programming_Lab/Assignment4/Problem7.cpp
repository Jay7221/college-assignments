#include<iostream>
using namespace std;
template<class T>
int search(T arr[], T tar, int n){
	int ans = -1;
	for(int i = 0; i < n; ++i){
		if(arr[i] == tar)
			ans = i;
	}
	return ans;
}
int main(){
	int n;
	cout << "Enter size of array : ";
	cin >> n;
	char arr[n];
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	char tar;
	cout << "Enter target : ";
	cin >> tar;
	cout << "Index of target : " << search(arr, tar, n) << endl;
	return 0;
}
