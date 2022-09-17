#include<iostream>
using namespace std;
class Shape{
	public:
		void display(){
			cout << "This is a shape" << endl;
		}
};
class Polygon: public Shape{
	public:
		void display(){
			cout << "This is a polygon" << endl;
		}
};
class Rectangle: public Polygon{
	public:
		void display(){
			cout << "Rectangle is a polygon" << endl;
		}
};
class Triangle: public Polygon{
	public:
		void display(){
			cout << "Triangle is a polygon" << endl;
		}
};
class Square: public Rectangle{
	public:
		void display(){
			cout << "Square is a Rectangle" << endl;
		}
};
int main(){
	Shape s;
	Polygon p;
	Rectangle r;
	Triangle t;
	Square sq;


	s.display();
	p.display();
	r.display();
	t.display();
	sq.display();
	return 0;
}
