#include<iostream>
#include<string.h>
using namespace std;
class Employee{
public:
    int empID;
    string name;
    string address;
    string designation;
    int salary[5];
    double avg_salary;
public:
    void display(){
        cout << "Employee Id : " << empID << endl;
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Designation : " << designation << endl;
        cout << "Salary : " << salary << endl;
    }
    void get_id(){
        cout << "Enter EMP ID : ";
        cin >> empID;
        cout << endl;
    }
    void get_name(){
        cout << "Enter name of employee : " ;
        cin >> name ;
        cout << endl;
    }
    void get_add(){
        cout << "Enter address of employee : " ;
        cin >> address;
        cout << endl;
    }
    void get_desg(){
        cout << "Enter designation of employee : " ;
        cin >> designation;
        cout << endl;
    }
    void get_sal(){
        avg_salary = 0;
        cout << "Enter salary of employee for " << endl;
        for(int i = 0; i < 5; ++i){
            cout << "Year " << i + 1 << " : ";
            cin >> salary[i];
            avg_salary += salary[i];
            cout << endl;
        }
        avg_salary /= 5;
        cout << endl;
    }
    void input_data(){
        get_id();
        get_name();
        get_add();
        get_desg();
        get_sal();
    }
    void output_data(){
        cout << "Employee ID : " << empID << endl;
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Designation : " << designation << endl;
        cout << "Average Salary : " << avg_salary << endl;
    }
};
int main(){
    cout << "Welcome administrator !!!" << endl ;
    int NUMBER_EMPLOYEES;
    cout << "Enter the number of employees : " << endl;
    cin >> NUMBER_EMPLOYEES;
    Employee employee[NUMBER_EMPLOYEES];
    for(int i = 0; i < NUMBER_EMPLOYEES; ++i){
        cout << "Enter data for employee : " << i + 1 << endl;
        Employee tmp;
        employee[i] = tmp;
        employee[i].input_data();
    }
    cout << "--------------------------\n\n\n";
    cout << endl;
    cout << "The entered data is :" << endl << endl;
    for(int i = 0; i < NUMBER_EMPLOYEES; ++i){
        employee[i].output_data();
        cout << endl;
        cout << endl;
    }
}
    