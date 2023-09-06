#include<iostream>
#include<string.h>
using namespace std;
struct Student{
	string name;
	string prn;
	string address;
	int year;
	string branch;
};
void inputData(Student *s){
	cout << "Enter the name of the student : ";
	cin >> ws;
	getline(cin, s -> name);
	cout << endl;
	cout << "Enter the PRN of the student : ";
	cin >>(s -> prn);
	cout << endl;
	cout << "Enter the address of the student : ";
	cin >> ws;
	getline(cin, s -> address);
	cout << endl;
	cout << "Enter the year of the student : ";
	cin >> (s -> year);
	cout << endl;
	cout << "Enter the branch of the student : ";
	cin >> ws;
	getline(cin, s -> branch);
	cout << endl;
}
void outputData(Student *s){
	cout << "Name : " << (s -> name) << endl;
	cout << "PRN : " << (s -> prn) << endl;
	cout << "Address : " << (s -> address) << endl;
	cout << "Year : " << (s -> year) << endl;
	cout << "Branch : " << (s -> branch) << endl;
}
int main(){
	int numberStudents;
	cout << "Enter the number of students : ";
	cin >> numberStudents;
	cout << endl;
	Student students[numberStudents];
	for(int i = 0; i < numberStudents; ++i){
		cout << "Enter data for student " << i + 1 << endl;
		inputData(students + i);
	}
	cout << "The entered data is : " << endl;
	for(int i = 0; i < numberStudents; ++i){
		outputData(students + i);
	}
	return 0;
}
