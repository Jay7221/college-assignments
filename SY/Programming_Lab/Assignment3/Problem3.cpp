#include<iostream>
using namespace std;
class Staff{
	private:
		string codename;
	public:
		Staff(){
			codename = "";
		}
		Staff(string name){
			codename = name;
		}
		void set_codename(string name){
			codename = name;
		}
		string get_codename(){
			return codename;
		}
};
class Teacher: public Staff {
	private:
		string subject_publication;
	public:
		Teacher(string sub_pub, string name){
			subject_publication = sub_pub;
			set_codename(name);
		}
		Teacher(){
			subject_publication = "";
		}
		string get_subject_publication(){
			return subject_publication;
		}
		void set_subject_publication(string sub_pub){
			subject_publication = sub_pub;
		}
};
class Officer : public Staff {
	private:
		string grade;
	public:
		Officer(string grd, string name){
			grade = grd;
			set_codename(name);
		}
		Officer(){
			grade = "";
		}
		string get_grade(){
			return grade;
		}
		void set_grade(string grd){
			grade = grd;
		}
};
class Typist : public Staff {
	private:
		int speed;
	public:
		Typist(int sp, string name){
			speed = sp;
			set_codename(name);
		}
		Typist(){
			speed = 0;
		}
		int get_speed(){
			return speed;
		}
		void set_speed(int sp){
			speed = sp;
		}
};
class Regular : public Typist {
	public : 
		Regular(int sp, string name){
			set_speed(sp);
			set_codename(name);
		}
};
class Casual : public Typist { 
	private:
		int daily_wages;
	public:
		Casual(int daily_w, int sp, string name){
			daily_wages = daily_w;
			set_speed(sp);
			set_codename(name);
		}
		void set_daily_wages(int dw){
			daily_wages = dw;
		}
		int get_daily_wages(){
			return daily_wages;
		}
};
int main(){
	Casual c(43, 34, "The Great");
	cout << c.get_codename() << endl;
	return 0;
}
