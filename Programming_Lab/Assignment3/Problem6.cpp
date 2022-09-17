#include<iostream>
#include<math.h>
using namespace std;
class Polar{
	public:
		double radius;
		double angle;
		void set_angle(double a){
			angle = a;
		}
		void set_radius(double r){
			radius = r;
		}
		void set_coords(double r, double a){
			radius = r;
			angle = a;
		}
		double get_x(){
			return radius * cos(angle);
		}
		double get_y(){
			return radius * sin(angle);
		}
		Polar(){
			radius = 0;
			angle = 0;
		}
		Polar(double x, double y){
			radius = sqrt(x * x + y * y);;
			angle = atan(y / x);
		}
		Polar operator + (Polar const &obj){
			double x = radius * sin(angle) + obj.radius * sin(obj.angle);
			double y = radius * cos(angle) + obj.radius * cos(obj.angle);
			Polar res(x, y);
			return res;
		}
		Polar operator * (Polar const &obj){
			double r = radius * obj.radius;
			double a = angle + obj.angle;
			Polar res;
			res.set_coords(r, a);
			return res;
		}
		friend ostream &operator<<(ostream &out, const Polar &obj){
			out << "Radius : " << obj.radius << endl;
			out << "Angle : " << obj.angle << endl;
			return out;
		}
		friend istream &operator>>(istream &in, Polar &obj){
			in >> obj.radius;
			in >> obj.angle;
			return in;
		}
};
int main(){
	double x1, x2, y1, y2;
	cout << "Enter coordinates of point p1 and p2 : " << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	Polar p1(x1, y1), p2(x2, y2);
	cout << "The points are : " << p1 << p2 << endl;
	cout << "p1 + p2 = " << endl;
	cout << p1 + p2 << endl;
	cout << "p1 * p2 = " << endl;
	cout << p1 * p2 << endl;
	return 0;
}
