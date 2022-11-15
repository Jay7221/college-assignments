#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *prev;
		Node *next;
		Node(){
			prev = NULL;
			next = NULL;
			data = 0;
		}
		Node(int d){
			data = d;
			prev = NULL;
			next = NULL;
		}
};
Node *Add(Node *head, int data){
	Node *newHead = new Node(data);
	newHead -> next = head;
	if(head != NULL)
		head -> prev = newHead;
	return newHead;
}
void transverse(Node *head){
	while(head != NULL){
		cout << (head -> data) << ' ' ;
		head = head -> next;
	}
	cout << endl;
}
void reverseTransverse(Node *tail){
	while(tail != NULL){
		cout << (tail -> data) << ' ' ;
		tail = tail -> prev;
	}
	cout << endl;
}
Node *find(Node *head, int d){
	while(head != NULL && (head -> data != d)){
		head = head -> next;
	}
	return head;
}
int main(){
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	Node *head = NULL;
	for(int i = 0; i < n; ++i){
		int d;
		cin >> d;
		head = Add(head, d);
	}
	Node *tail = head;
	while(tail -> next != NULL)
		tail = tail -> next;
	cout << "Transversal of list is : ";
	transverse(head);
	cout << "Revese transversal of the list is : ";
	reverseTransverse(tail);
	cout << "Enter the value of node : ";
	int k;
	cin >> k;
	Node *cur = find(head, k);
	cout << (cur -> prev -> data) << ' ' << (cur -> data) << ' '  << (cur -> next -> data) << endl;
	cout << (cur -> prev) << " " << (cur) << " " << (cur -> next) << endl;
	return 0;
}
