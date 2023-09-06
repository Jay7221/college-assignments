#include<iostream>
using namespace std;
class CircularQueue{
	private:
		int *arr;
		int front, rear;
		int size;
	public:
		CircularQueue(int s){
			size = s;
			front = rear = -1;
			arr = new int[s];
		}
		void enqueue(int data){
			if(front == -1){
				front = rear = 0;
				arr[front] = data;
			}else{
				if((front + 1) % size == rear){
					cout << "QUEUE FULL" << endl;
					return ;
				}else{
					front = (front + 1) % size;
					arr[front] = data;
				}
			}
		}
		int dequeue(){
			if(rear == -1){
				cout << "EMPTY QUEUE" << endl;
				return -1;
			}else{
				int ans = arr[rear];
				if(front == rear)
					front = rear = -1;
				else
					rear = (rear + 1) % size;
				return ans;
			}
		}
};
int main(){
	CircularQueue q(10);
	for(int i = 0; i < 10; ++i)
		q.enqueue(i);
	for(int i = 0; i < 12; ++i)
		cout << q.dequeue() << ' ' ;
	cout << endl;
	return 0;
}
