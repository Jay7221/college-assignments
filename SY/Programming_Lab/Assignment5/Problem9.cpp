#include<iostream>
using namespace std;
class Shape{
	public:
		double x;
		double y;
		virtual void display_area(){
		}
		void get_data(double xx, double yy = 0){
			x = xx;
			y = yy;
			// initialze x and y
		}
		Shape(){
			x = 0;
			y = 0;
		}
};
class Triangle : public Shape{
	public:
		void display_area(){
			cout << "Area : " <<  (0.5 * x * y) << endl;
		}
};
class Rect : public Shape{
	public:
		void display_area(){
			cout << "Area : " << (x * y) << endl;
		}
};
class Circle : public Shape{
	public:
		void display_area(){
			cout << "Area : " << (3.14 * x * x) << endl;
		}
};
int main(){
	Circle c;
	double x;
	cout << "Circle : " << endl;
	cin >> x;
	c.get_data(x);
	c.display_area();
	return 0;
}
