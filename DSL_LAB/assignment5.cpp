#include<iostream>
using namespace std;
class Stack{
	private:
		int *arr;
		int n;
		int l, r;
	public:
		Stack(int n):n(n){
			l = -1, r = -1;
			arr = new int(n);
		}
		Stack(){
			l = -1, r = -1;
			n = 0;
		}
		void push(int data){
			if(r == n - 1){
				cout << "STACK OVERFLOW" << endl;
				return ;
			}
			if(r == -1){
				l = 0;
			}
			r = r + 1;
			arr[r] = data;
		}
		int pop(){
			if(l == -1){
				cout << "EMPTY STACK" << endl;
				return -1;
			}
			int res = arr[r];
			r = r - 1;
			if(l > r){
				l = r = -1;
			}
			return res;
		}

};
int main(){
	int n;
	cout << "Enter the number of elements in the stack : ";
	cin >> n;
	Stack s(n);
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		s.push(k);
	}
	cout << "The entered elements are : ";
	for(int i = 0; i < n; ++i){
		cout << s.pop() << ' ' ;
	}
	cout << endl;
	return 0;
}
