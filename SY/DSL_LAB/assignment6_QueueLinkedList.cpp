#include<iostream>
using namespace std;
class QNode{
	public:
		int data;
		QNode *next;
		QNode(int d){
			next = NULL;
			data = d;
		}
		QNode(){
			next = NULL;
			data = 0;
		}
};
class Queue{
	public:
		QNode *front, *rear;
		Queue(){
			front = NULL;
			rear = NULL;
		}
		void enqueue(int data){
			if(front != NULL){
				front -> next = new QNode(data);
				front = front -> next;
			}else{
				front = rear = new QNode(data);
			}
		}
		int dequeue(){
			if(rear == NULL){
				cout << "Queue is EMPTY" << endl;
				return -1;
			}else{
				int ans = rear -> data;
				rear = rear -> next;
				if(rear == NULL)
					front = NULL;
				return ans;
			}
		}
};
int main(){
	Queue q;
	for(int i = 0; i < 30; ++i)
		q.enqueue(i);
	for(int i = 0; i < 33; ++i)
		cout << q.dequeue() << ' ' ;
	cout << endl;
	return 0;
}
