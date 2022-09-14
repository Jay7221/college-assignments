#include<iostream>
#include<fstream>
using namespace std;
void move(FILE *fp, int n, int source, int destination, int middle){
    if(n == 1){
        fprintf(fp, "Move disk %d to %d\n", source, destination);
    }else{
        move(fp, n - 1, source, middle, destination);
        move(fp, 1, source, destination, middle);
        move(fp, n - 1, middle, destination, source);
    }
}
int main(){
    ofstream out;
    FILE *fp = fopen("text.txt", "w");
    int n;
    cin >> n;
    move(fp, n, 1, 3, 2);
}