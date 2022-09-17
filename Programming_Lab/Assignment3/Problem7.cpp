#include<iostream>
using namespace std;
class INTEGER{
	public:
		float n;
		INTEGER(){
			n = 0;
		}
		INTEGER(float num){
			n = num;
		}
		INTEGER operator + (INTEGER const &obj){
			INTEGER res(n + obj.n);
			return res;
		}
		INTEGER operator * (INTEGER const &obj){
			INTEGER res(n * obj.n);
			return res;
		}
		INTEGER operator / (INTEGER const &obj){
			INTEGER res(n / obj.n);
			return res;
		}
		INTEGER operator - (INTEGER const &obj){
			INTEGER res(n - obj.n);
			return res;
		}
		friend ostream &operator<<(ostream &out, const INTEGER &obj){
			out << obj.n ;
			return out;
		}
		friend istream &operator>>(istream &in, INTEGER &obj){
			in >> obj.n;
			return in;
		}
};
int main(){
	INTEGER n, m;
	cout << "Enter values of n and m : " << endl;
	cin >> n >> m;
	cout << endl;
	cout << "n + m = " << n + m << endl;
	cout << "n - m = " << n - m << endl;
	cout << "n * m = " << n * m << endl;
	cout << "n / m = " << n / m << endl;
	return 0;
}
