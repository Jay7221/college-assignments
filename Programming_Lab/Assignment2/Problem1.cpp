#include<iostream>
using namespace std;
class Film{
	private:
		string name;
		string language;
		string type;
		float duration;
	public:
		Film(){
			language = "Hindi";
			duration = 3;
		}
		~Film(){
			cout << "Film " << name << " closing " << endl;
		}
		void get_name(){
			cout << "Enter the name of the film:" << endl;
			cin >> name;
		}
		void get_language(){
			cout << "Enter the language of the film:" << endl;
			cin >> language;
		}
		void get_type(){
			cout << "Enter the type of the film:" << endl;
			cin >> type;
		}
		void get_duration(){
			cout << "Enter the duration of film:" << endl;
			cin >> duration;
		}
		void display(){
			cout << "Name : " << name << endl;
			cout << "Language : " << language << endl;
			cout << "Type : " << type << endl;
			cout << "Duration : " << duration << endl;
		}
};
int main(){
	Film f;
	f.get_name();
	f.get_type();
	cout << "The entered information is : " << endl;
	f.display();
	return 0;
}
