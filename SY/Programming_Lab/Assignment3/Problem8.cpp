#include<iostream>
using namespace std;
class MAT{
	public:
		int n, m;
		int *arr;
		MAT(){
			n = 1, m = 1;
			arr = new int[1];
		}
		MAT(int nn, int mm){
			n = nn, m = mm;
			arr = new int[n * m];
		}
		MAT operator + (const MAT & obj){
			MAT res(n, m);
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j){
					res.arr[i * m + j] = arr[i * m + j] + obj.arr[i * m + j];
				}
			}
			return res;
		}
		MAT operator - (const MAT & obj){
			MAT res(n, m);
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j){
					res.arr[i * m + j] = arr[i * m + j] - obj.arr[i * m + j];
				}
			}
			return res;
		}
		MAT operator * (const MAT & obj){
			if(m != obj.n){
				cout << "Operation not possible" << endl;
				return obj;
			}
			MAT res(n, obj.m);
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < obj.m; ++j){
					res.arr[i * n + j] = 0;
					for(int k = 0; k < m; ++k){
						res.arr[i * n + k] += arr[i * n + k] + obj.arr[k * obj.n + j];
					}
				}
			}
			return res;
		}
		friend ostream &operator<<(ostream &out, const MAT &obj){
			int n = obj.n, m = obj.m;
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j){
					out << obj.arr[i * n + j] << ' ';
				}
				out << endl;
			}
			out << endl;
			return out;
		}
		friend istream &operator>>(istream &in, MAT &obj){
			int n = obj.n, m = obj.m;
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j){
					cin >> obj.arr[i * n + j];
				}
			}
			return in;
		}
};
int main(){
	int n, m;
	cout << "Enter value of n and m : " << endl;
	cin >> n >> m;
	cout << endl;
	MAT A(n, m), B(n, m);
	cin >> A >> B;
	cout << "A : " << endl << A << endl;
	cout << "B : " << endl << B << endl;
	cout << "A + B : " << endl << A + B << endl;
	cout << "A - B : " << endl << A - B << endl;
	cout << "A * B : " << endl << A * B << endl;
	return 0;
}
