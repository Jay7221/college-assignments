#include<iostream>
using namespace std;
class E{
	public:
		string message;
		E(string m) : message(m){}
};
int discount(int cid, int age, int cash){
	if(cid < 100){
		if(age > 20){
			if(age > 40)
				return 3;
			else
				return 7;
		}else{
			return 4;
		}
	}else{
		if(age > 20){
			if(cash > 0)
				return 4;
			else 
				throw E("No cash customer");
		}else{
			if(cash > 400)
				return 4;
			else
				throw E("Too big puchase for Discount");
		}
	}
}
int main(){
	int age, cash, cid;
	cout << "C ID : " ;
	cin >> cid;
	cout << "Age : ";
	cin >> age;
	cout << "Cash : ";
	cin >> cash;
	try{
		int d = discount(cid, age, cash);
		cout << "Discount : " << d << endl;
	}
	catch(E e){
		cout << "Exception Occured : " << e.message << endl;
	}
	return 0;
}
