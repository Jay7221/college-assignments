#include<iostream>
using namespace std;
class Apples{
	private:
		int apples;
	public:
		void input_apples(){
			cout << "Enter the nubmer of apples : ";
			cin >> apples;
			cout << endl;
		}
		int get_apples(){
			return apples;
		}
};
class Mangoes{
	private:
		int mangoes;
	public:
		void input_mangoes(){
			cout << "Enter the number of mangoes : ";
			cin >> mangoes;
			cout << endl;
		}
		int get_mangoes(){
			return mangoes;
		}
};
class Fruits : public Apples, public Mangoes{
	public:
		void get_data(){
			input_apples();
			input_mangoes();
		}
		void display(){
			int total = 0;
			cout << "Number of apples : " << get_apples() << endl;
			total += get_apples();
			cout << "Number of mangoes : " << get_mangoes() << endl;
			total += get_mangoes();
			cout << "Total number of fruits : " << total << endl;
		}
};

int main(){
	Fruits f;
	f.get_data();
	f.display();
	return 0;
}
