#include<iostream>
using namespace std;
namespace NMS1{
	int a;
	void seta(int data){
		a = data;
	}
	int geta(){
		return a;
	}
};
namespace NMS2{
	int b;
	void setb(int data){
		b = data;
	}
	int getb(){
		return b;
	}
};
int main(){
	int k;
	cin >> k;
	NMS1::seta(k);
	cout << NMS1::geta() << endl;
	return 0;
}
