#include<iostream>
using namespace std;
namespace Outer{
	int a = 10;
	void set(int k){
		a = k;
	}
	namespace Inner{
		int a;
		void set(int k){
			a = k;
		}
	};
};
int main(){
	int n;
	cin >> n;
	Outer::set(n);
	cout << Outer::a << endl;
	cin >> n;
	Outer::Inner::set(n);
	cout << Outer::Inner::a << endl;
	return 0;
}
