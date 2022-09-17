#include<iostream>
using namespace std;
class Box{
    private:
    static int height;
    int breadth;
    int length;
    public:
    Box(int h, int b, int l){
        height = h;
        breadth = b;
        length = l;
    }
    int getHeight(){
        return height;
    }
    int area(){
        return height * breadth * length;
    }
};
int Box::height = 100;
int main(){
    Box* boxex[2];
    for(int i = 0; i < 2; ++i){
        int h, b, l;
        cout << "Enter height : ";
        cin >> h;
        cout << endl;
        cout << "Enter breadth : ";
        cin >> b;
        cout << endl;
        cout << "Enter length : ";
        cin >> l;
        cout << endl;
        boxex[i] = new Box(h, b, l);
    }
    for(int i = 0; i < 2; ++i){
        cout << "Height of box " << i + 1 << " : " << boxex[i] -> getHeight();
        cout << endl;
        cout << "Area for box " << i + 1 << " : " << boxex[i] -> area();
        cout << endl;
    }
    return 0;
}