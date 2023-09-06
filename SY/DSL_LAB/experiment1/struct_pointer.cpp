#include<iostream>
using namespace std;
struct Node{
	Node* next;
	int data;
	Node(int n){
		data = n;
	}
};
int main(){
	Node* n = new Node(0);
	Node* head;
	head = n;
	int num_elem;
	cin >> num_elem;
	while(num_elem--){
		int tmp;
		cin >> tmp;
		n -> next = new Node(tmp);
		n = n -> next;
	}
	while(head != NULL){
		cout << head -> data << ' ' ;
		head = head -> next;
	}
	cout << endl;
}
