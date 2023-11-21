#include<bits/stdc++.h>
using namespace std;
struct Job{
    string id;
    int deadline;
    int profit;
};
int compare(const Job a, const Job b){
    return (b.profit < a.profit);
}
int main(){
    int n;
    cerr << "Enter the number of jobs : " << endl;
    cin >> n;
    vector<Job> jobs(n);
    cerr << "Enter job ids : " << endl;
    for(Job &j : jobs){
        cin >> j.id;
    }
    cerr << "Enter job deadlines: " << endl;
    for(Job &j : jobs){
        cin >> j.deadline;
    }
    cerr << "Enter job profits: " << endl;
    for(Job &j : jobs){
        cin >> j.profit;
    }
    sort(jobs.begin(), jobs.end(), compare);
    vector<string> result(n + 1);
    vector<bool> occupied(n + 1, false);
    for(Job &j : jobs){
        for(int slot = min(n, j.deadline); slot > 0; --slot){
            if(!occupied[slot]){
                result[slot] = j.id;
                occupied[slot] = true;
                break;
            }
        }
    }
    for(int slot = 1; slot <= n; ++slot){
        if(occupied[slot]){
            cout << result[slot] << ' ';
        }
    }
    cout << endl;
    return 0;
}
