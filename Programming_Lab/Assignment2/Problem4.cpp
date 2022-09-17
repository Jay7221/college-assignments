#include<iostream>
using namespace std;
class SportsTeam{
    private:
    string name;
    int no_players;
    int average_age;
    public:
    static int obj_count;
    SportsTeam(string NAME, int NO_OF_PLAYERS, int AVERAGE_AGE){
        obj_count++;
        name = NAME;
        no_players = NO_OF_PLAYERS;
        average_age = AVERAGE_AGE;
    }
    void display(){
        cout << "TEAM NAME : " << name << endl;
        cout << "Number of players : " << no_players << endl;
        cout << "Average Age : " << average_age << endl;
    }
    ~SportsTeam(){
        --obj_count;
    }

};
int SportsTeam::obj_count = 0;
int main(){
    SportsTeam* teams[3];
    for(int i = 0; i < 3; ++i){
        string name;
        int no_players, avg_age;
        cout << "Enter data for player " << i + 1 << endl;
        cout << "Enter team name : ";
        cin >> name;
        cout << endl;
        cout << "Enter number of players : " ;
        cin >> no_players;
        cout << endl;
        cout << "Enter Average age of players : ";
        cin >> avg_age;
        cout << endl;
        teams[i] = new SportsTeam(name, no_players, avg_age);
    }
    cout << "Number of teams : " << (SportsTeam :: obj_count) << endl;
    for(int i = 0; i < 3; ++i){
        teams[i] -> display();
    }
}