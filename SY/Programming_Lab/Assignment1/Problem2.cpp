#include<iostream>
using namespace std;
class Prob2{
	int arr[5];
public:
	void input(){
		for(int i = 0; i < 5; ++i){
			cin >> arr[i];
		} 
	}
	void sort(){
		for(int i = 0; i < 5; ++i){
			for(int j = i + 1; j < 5; ++j){
				if(arr[i] < arr[j]){
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
	void output(){
		for(int i = 0; i < 5; ++i)
			cout << arr[i] << ' ' ;
		cout << endl;
	}
};
int main(){
	Prob2 p;
	p.input();
	p.sort();
	p.output();
}