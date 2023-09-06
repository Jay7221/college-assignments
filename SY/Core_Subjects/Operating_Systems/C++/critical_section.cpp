#include<iostream>
#include<thread>
using namespace std;
int count;
void inr(){
	for(int i = 0; i < 100000; ++i){
		++count;
	}
}
int main(){
	thread t1(inr);
	thread t2(inr);

	cout << "Before : " << count << "\n";

	t1.join();
	t2.join();
	cout << "After : " << count << '\n';
	return 0;
}
