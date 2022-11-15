#include<iostream>
using namespace std;
FILE *fp = fopen("text.txt", "w");
void move(int tower1, int tower2){
	cout << "Move disk from tower " << tower1 << " to " << tower2 << endl;
	fprintf(fp, "Move disk from tower %d to tower %d \n", tower1, tower2);
}
void towerOfHanoi(int n, int tower1, int tower2, int tower3){
	// we wish to move all disks from tower1 to tower2 using tower3 as mediator
	if(n < 1)
		return ;
	towerOfHanoi(n - 1, tower1, tower3, tower2);
	move(tower1, tower2);
	towerOfHanoi(n - 1, tower3, tower2, tower1);
}
int main(int argv, char* argc[]){
	int n;
	if(argv > 1){
		n = argc[1][0] - '0';
	}else{
		cout << "Enter the number of disks on tower 1 : ";
		cin >> n;
		cout << endl;
	}
	towerOfHanoi(n, 1, 2, 3);
	fclose(fp);
	return 0;
}
