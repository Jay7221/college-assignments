#include<iostream>
using namespace std;
class Node{
	public:
		Node* link;
		int data;
		Node(){
			link = NULL;
		}
		Node(int data):data(data){
			link = NULL;
		}
};
void printLinkedList(Node *head){
	while(head != NULL){
		cout << (head -> data) << ' ' ;
		head = head -> link;
	}
	cout << endl;
}
Node* reverseLinkedList0(Node *head){
	// Returns the head of the reversed linked list
	if(head == NULL){
		return head;
	}
	Node *cur = NULL, *next = head, *prev = NULL;
	while(next  != NULL){
		prev = cur;
		cur = next;
		next = next -> link;
		cur -> link = prev;
	}
	return cur;
}

Node* reverseLinkedList(Node *head, Node* prev = NULL){
	cout << (head -> data) << endl;
	if(head -> link == NULL){
		head -> link = prev;
		return head;
	}
	Node *reverseHead = reverseLinkedList(head -> link, head);
	head -> link = prev;
	return reverseHead;
}

int main(){
	int m;
	cout << "Enter the number of elements of list : ";
	cin >> m;
	cout << endl;
	cout << "Enter the elements of the list" << endl;
	int n;
	cin >> n;
	--m;
	Node *head = new Node(n);
	Node *cur = head;
	while(m--){
		cin >> n;
		cur -> link = new Node(n);
		cur = cur -> link;
	}
	head = reverseLinkedList(head);
	cout << "The reversed linked list is : ";
	printLinkedList(head);
	return 0;
}
