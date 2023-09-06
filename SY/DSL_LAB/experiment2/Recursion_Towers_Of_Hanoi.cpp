#include<iostream>
using namespace std;
int cnt = 0;
void move(int n, int source, int destination, int middle){
    if(n == 1){
        ++cnt;
        cout << "Move Disk from " << source << " to " << destination << endl;
        return ;
    }
    move(n - 1, source, middle, destination);
    move(1, source, destination, middle);
    move(n - 1, middle, destination, source);
}
int main(){
    int n;
    cout << "Enter the number of disks to move from tower 1 to 3 : ";
    cin >> n;
    cout << endl ;
    int source = 1, middle = 2, destination = 3;
    move(n, source, destination, middle);
    cout << cnt << endl;
}