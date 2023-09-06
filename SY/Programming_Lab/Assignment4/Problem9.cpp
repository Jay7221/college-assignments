#include<iostream>
using namespace std;
template<class U, class V>
class Number{
	private:
		U x;
		V y;
	public:
		void set(U xx, V yy){
			x = xx;
			y = yy;
		}
		void print(){
			cout << "x : " << x << endl;
			cout << "y : " << y << endl;
		}
};
int main(){
	Number<int, float> n1;
	Number<double, float> n2;
	n1.set(10, 34.44);
	cout << "N1 : " << endl;
	n1.print();
	cout << "N2 : " << endl;
	n2.set(3.34, 34);
	n2.print();
	return 0;
}
