#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int get_winner(vector<int> &v){
    sort(v.begin(), v.end());
    int winner = -1, winner_vote = 0, cur_cand = -1, vote = 0;
    for(int id : v){
        if(id != cur_cand){
            vote = 0;
            cur_cand = id;
        }
        ++vote;
        if(vote >= winner_vote){
            winner_vote = vote;
            winner = cur_cand;
        }
    }
    return winner;
}
int main(){
    int n;
    cout << "Enter the size of array : " ;
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << "The winner is : " << get_winner(a) << endl;
    return 0;
}
