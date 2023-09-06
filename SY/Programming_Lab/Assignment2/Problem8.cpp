#include<iostream>
using namespace std;
void result(int ise_marks){
	cout << "Insem Marks : " << ise_marks << endl;
	cout << "Result : ";
	if(ise_marks >= 15)
		cout << "PASS" << endl;
	else
		cout << "FAIL" << endl;
	cout << endl;
}
void result(int ise_marks, int mse_marks){
	cout << "Insem Marks : " << ise_marks << endl;
	cout << "MidSem Marks : " << mse_marks << endl;
	int marks = ise_marks + mse_marks;
	bool flag = true;
	if(ise_marks < 15)
		flag = false;
	if(mse_marks < 20)
		flag = false;
	if(marks < 30)
		flag = false;
	if(flag)
		cout << "Result : PASS" << endl;
	else
		cout << "Result : FAIL" << endl;
	cout << endl;
}
void result(int ise_marks, int mse_marks, int ese_marks){
	int marks = ise_marks + mse_marks + ese_marks;
	cout << "InSem Marks : " << ise_marks << endl;
	cout << "MidSem Marks : " << mse_marks << endl;
	cout << "EndSem Marks : " << ese_marks << endl;
	cout << "Total Marks : " << marks << endl;
	bool flag = true;
	if(ise_marks < 15)
		flag = false;
	if(mse_marks < 20)
		flag = false;
	if(ese_marks < 40)
		flag = false;
	if(marks < 40)
		flag = false;
	if(flag)
		cout << "Result : PASS" << endl;
	else
		cout << "Result : FAIL" << endl;
	cout << endl;
}
int main(){
	result(23);
	result(10);
	result(10, 34);
	result(34, 14);
	result(10, 23, 45);
	result(34, 22, 42);
	return 0;
}
