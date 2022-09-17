#include<iostream>
using namespace std;
class Customer{
    private:
    int id;
    string name;
    int age;
    string city;
    public:
    Customer(int ID, string NAME, int AGE, string CITY){
        id = ID;
        name = NAME;
        age = AGE;
        city = CITY;
    }
    void display(){
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "City : " << city << endl;
    }
};
int main(){
    Customer* c[5];
    for(int i = 0; i < 5; ++i){
        int id, age;
        string name, city;
        cout << "Enter id : ";
        cin >> id;
        cout << endl;
        cout << "Enter name : " ;
        cin >> name;
        cout << endl;
        cout << "Enter age : " ;
        cin >> age;
        cout << endl;
        cout << "Enter city : " ;
        cin >> city;
        cout << endl;
        c[i] = new Customer(id, name, age, city);
    }
    for(int i = 0; i < 5; ++i){
        c[i] -> display();
        cout << endl;
    }
}