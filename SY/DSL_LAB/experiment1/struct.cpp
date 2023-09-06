#include<iostream>
#include<string.h>
using namespace std;
string SUBJECTS[] = {"Data Communication", "Discrete Mathematics", "Probability And Statics", "Computer Organization And Archtecture", "Software Engineering", "Data Structures"};
struct Student{
	string name;
	string PRN;
	string department;
	int marks[6];
	void get_name(){
		cout << "Enter name of the student : ";
		cin >> name;
		cout << endl;
	}
	void get_PRN(){
		cout << "Enter the PRN of the student : ";
		cin >> PRN;
		cout << endl ;
	}
	void get_department(){
		cout << "Enter the department of the Student : ";
		cin >> department;
		cout << endl;
	}
	void get_marks(){
		for(int i = 0; i < 6; ++i){
			cout << "Enter the marks of Student in " << SUBJECTS[i] << " : " ;
			cin >> marks[i];
			cout << endl;
		}
		cout << endl;
	}
	void put_name(){
		cout << "Name : " << name << endl;
	}
	void put_PRN(){
		cout << "PRN : " << PRN << endl;
	}
	void put_department(){
		cout << "Department : " << department << endl;
	}
	void put_marks(){
		for(int i = 0; i < 6; ++i){
			cout << SUBJECTS[i] << " : " << marks[i] << endl;
		}
	}
};
struct Student input_data(int ind){
	struct Student s;
	cout << "Enter data for student " << ind + 1 << endl;
	s.get_name();
	s.get_PRN();
	s.get_department();
	s.get_marks();
	return s;
}
void output_data(struct Student s){
	s.put_name();
	s.put_PRN();
	s.put_department();
	s.put_marks();
}
int main(){
	cout << "Welcome to administrator!!!!" << endl;
	cout << "Enter the number of students : " ;
	int NUMBER_STUDENTS;
	cin >> NUMBER_STUDENTS;
	struct Student STUDENTS[NUMBER_STUDENTS];
	for(int i = 0; i < NUMBER_STUDENTS; ++i){
		STUDENTS[i] = input_data(i);
	}
	for(int i = 0; i < NUMBER_STUDENTS; ++i){
		output_data(STUDENTS[i]);
	}
	return 0;
}