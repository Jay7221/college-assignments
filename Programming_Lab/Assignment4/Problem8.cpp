#include<iostream>
using namespace std;
template<typename T>
class Calc{
	public:
		T add(T x, T y){
			return (x + y);
		}
		T sub(T x, T y){
			return (x - y);
		}
		T mult(T x, T y){
			return (x * y);
		}
		T div(T x, T y){
			return (x / y);
		}
};
int main(){
	Calc<int> c;
	int x, y;
	cin >> x >> y;
	cout << "x + y = " << c.add(x, y) << endl;
	cout << "x - y = " << c.sub(x, y) << endl;
	cout << "x * y = " << c.mult(x, y) << endl;
	cout << "x / y = " << c.div(x, y) << endl;
	return 0;
}



