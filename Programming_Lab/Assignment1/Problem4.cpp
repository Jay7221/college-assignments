#include<iostream>
using namespace std;
bool is_prime(int n){
	bool ans = true;
	for(int i = 2; (i * i) <= n; ++i){
		if(n % i == 0)
			ans = false;
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	bool flag = true;
	if(!is_prime(n)){
		flag = false;
	}else{
		int tmp = n;
		while(tmp){
			int digit = tmp % 10;
			tmp /= 10;
			if(!is_prime(digit)){
				flag = false;
				break ;
			}
		}
	}
	if(flag){
		cout << "The number is a superprime" << endl;
	}else{
		cout << "The number is not a superprime" << endl;
	}
}