#include<iostream>
using namespace std;
namespace Organization{
	class Employee{
		public:
			string name;
			int id;
			int salary;
			void setDetails(int empId, string empName, int empSalary){
				id = empId;
				name = empName;
				salary = empSalary;
				return ;
			}
			void getDetails(){
				cout << "Name : " << name << endl;
				cout << "Id : " << id << endl;
				cout << "Salary : " << salary << endl;
			}
	};
};
int main(){
	Organization::Employee e;
	e.setDetails(10, "Jay Shirgupe", 1000);
	e.getDetails();
	return 0;
}
