#include<iostream>
using namespace std;
class Vehicle{
	private:
		string type;
	public:
		Vehicle(){
			type = "";
		}
		void set_type(string s){
			type = s;
		}
		string get_type(){
			return type;
		}
		void display(){
			cout << "Type : " << type << endl;
		}
};
class Racing{
	private:
		int top_speed;
	public:
		Racing(){
			top_speed = 0;
		}
		void set_top_speed(int s){
			top_speed = s;
		}
		int get_top_speed(){
			return top_speed;
		}
		void display(){
			cout << "Top Speed : " << top_speed << endl;
		}
};
class Car : public Vehicle{
	private:
		string brand;
	public:
		Car(){
			Vehicle::set_type("Car");
			brand = "";
		}
		void set_brand(string s){
			brand = s;
		}
		void display(){
			cout << "Brand : " << brand << endl;
			Vehicle::display();
		}
};
class Audi : public Car, public Racing{
	private:
		string name;
	public:
		Audi(string s){
			name = s;
			Car::set_brand("Audi");
			Racing::set_top_speed(40);
		}
		void display(){
			cout << "The details are : " << endl;
			cout << "Name : " << name << endl;
			Car :: display();
			Racing :: display();
		}
};
int main(){
	string s;
	cout << "Enter the name of the car" << endl;
	cin >> s;
	Audi a(s);
	a.display();
	return 0;
}

