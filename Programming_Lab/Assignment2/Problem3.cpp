#include<iostream>
using namespace std;
class Shape{
    public:
    int edge;
    Shape(int x){
        edge = x;
    }
    Shape(const Shape& old){
        edge = old.edge;
    }
    void area_of_circle(){
        double area = (3.14 * edge * edge);
        cout << "Area of circle is : " << area << endl;
    }
    void area_of_triangle(){
        double area = (.433 * edge * edge);
        cout << "Area of circle is : " << area << endl;
    }
    void area_of_square(){
        double area = (edge * edge);
        cout << "Area of circle is : " << area << endl;
    }
};
int main(){
    int n ;
    cout << "Enter edge length : " ;
    cin >> n;
    cout << endl;
    Shape circle(n);
    Shape triangle = circle, square = circle;
    circle.area_of_circle();
    triangle.area_of_triangle();
    square.area_of_square();
    return 0;
}