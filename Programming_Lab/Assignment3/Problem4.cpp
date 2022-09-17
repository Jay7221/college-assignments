#include<iostream>
using namespace std;
class Education{
	private:
		string educational_qualification;
		string professional_qualification;
	public:
		void set_educational_qualification(string qual){
			educational_qualification = qual;
		}
		void set_professional_qualification(string qual){
			professional_qualification = qual;
		}
		string get_education_qualification(){
			return educational_qualification;
		}
		string get_professional_qualification(){
			return professional_qualification;
		}
		void display(){
			cout << "Highest Educational Qualification : " << educational_qualification << endl;
			cout << "Highest Professional Qualification : " << professional_qualification << endl;
		}
};
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
		void display(){
			cout << "Codename : " << codename << endl;
		}
};
class Teacher: public Staff, public Education {
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
		void display(){
			Education::display();
			Staff::display();
			cout << "Subject Publication : " << subject_publication << endl;
		}
};
class Officer : public Staff, public Education {
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
		void display(){
			Education::display();
			Staff::display();
			cout << "Grade : " << grade << endl;
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
		void display(){
			Staff::display();
			cout << "Speed : " << speed << endl;
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
	Teacher t;
	Officer o;
	t.set_educational_qualification("PHD in M.Tech.");
	o.set_educational_qualification("Degree in Management");
	t.display();
	o.display();
	Typist tp(100, "TP");
	tp.display();
	return 0;
}
