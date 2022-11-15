#include<iostream>
using namespace std;
int main(){
	int a = 10, b = 0;
	string zero_error = "Zero Error";
	try{
		if(b != 0){
			cout << "a / b = " << (a / b) << endl;
		}else{
			throw zero_error;
		}
	}
	catch(string s){
		cout << "Error : " << s << endl;
	}
	return 0;
}
