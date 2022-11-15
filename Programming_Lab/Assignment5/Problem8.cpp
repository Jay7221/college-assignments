#include<iostream>
using namespace std;
class Shape{
	public:
		double x;
		double y;
		virtual void display_area(){
		}
		void get_data(double xx, double yy){
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
int main(){
	Rect r;
	Triangle t;
	double x, y;
	cout << "Rectangle : " << endl;
	cin >> x >> y;
	r.get_data(x, y);
	r.display_area();
	cout << "Triangle : " << endl;
	cin >> x >> y;
	t.get_data(x, y);
	t.display_area();
	return 0;
}
