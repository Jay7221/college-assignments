#include<iostream>
using namespace std;
class Node{
	public:
		Node *next;
		Node *prev;
		int data;
		Node(){
			next = NULL;
			prev = NULL;
			data = 0;
		}
		Node(int d){
			data = d;
			next = NULL;
			prev = NULL;
		}
};
void print(Node *head){
	while(head != NULL){
		cout << head -> data << ' ';
		head = head -> next;
	}
	cout << endl;
}
Node *reverseDoublyLinkedList(Node *head){
	while(head != NULL){
		Node *front = head -> next, *back = head -> prev;
		head -> next = back;
		head -> prev = front;
		if(front == NULL)
			return head;
		head = front;
	}
	return head;
}
Node* insertAtTail(Node *head, int data){
	if(head == NULL){
		head = new Node(data);
		return head;
	}
	Node *cur = head;
	while(cur -> next != NULL)
		cur = cur -> next;
	cur -> next = new Node(data);
	cur -> next -> prev = cur;
	return head;
}
void insertAtElem(Node *elem, int data){
	elem -> next = new Node(data);
	elem -> next -> prev = elem;
}
Node* insertAtHead(Node *head, int data){
	Node* cur = new Node(data);
	if(head != NULL)
		head -> prev = cur;
	cur -> next = head;
	return cur;
}
Node* search(Node* head, int data){
	while(head != NULL){
		if(head -> data == data)
			return head;
		head = head -> next;
	}
	return head;
}
Node* deleteHead(Node* head){
	if(head == NULL)
		return head;
	Node* newHead = head -> next;
	if(newHead != NULL)
		newHead -> prev = NULL;
	delete head;
	return newHead;
}
void deleteElem(Node *elem){
	if(elem == NULL)
		return ;
	Node *back = elem -> prev, *front = elem -> next;
	if(back != NULL)
		back -> next = front;
	if(front != NULL)
		front -> prev = back;
	delete elem;
}
int main(){
	Node *head = NULL;
	int n;
	cout << "Enter the number of elements in the list : ";
	cin >> n;
	while(n--){
		int k;
		cin >> k;
		head = insertAtTail(head, k);
	}
	head = reverseDoublyLinkedList(head);
	cout << "The reversed Doubly Linked List is : ";
	print(head);
	cout << "Enter the element to delete : ";
	int k;
	cin >> k;
	Node *tmp = search(head, k);
	deleteElem(tmp);
	cout << "The list is : ";
	print(head);
	return 0;
}
