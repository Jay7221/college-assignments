#include<iostream>
using namespace std;
class TreeNode{
	public:
		TreeNode *left, *right;
		int data;
		TreeNode(){
			left = NULL;
			right = NULL;
			data = 0;
		}
		TreeNode(int d){
			left = NULL;
			right = NULL;
			data = d;
		}
};
TreeNode* insertTreeNode(TreeNode *root, int data){
	if(root == NULL)
		return new TreeNode(data);
	if(root -> data > data)
	{
		root -> left = insertTreeNode(root -> left, data);
	}
	if(root -> data < data)
	{
		root -> right = insertTreeNode(root -> right, data);
	}
	return root;
}
void preOrder(TreeNode *root)
{
	if(root == NULL)
	{
		return ;
	}
	cout << (root -> data) << ' ';
	preOrder(root -> left);
	preOrder(root -> right);
}
void postOrder(TreeNode *root)
{
	if(root == NULL)
	{
		return;
	}
	postOrder(root -> left);
	postOrder(root -> right);
	cout << (root -> data) << ' ';
}
void inOrder(TreeNode *root)
{
	if(root == NULL)
	{
		return;
	}
	inOrder(root -> left);
	cout << (root -> data) << ' ';
	inOrder(root -> right);
}
int main()
{
	cout << "Enter number Nodes : ";
	int n;
	cin >> n;
	TreeNode *root;
	for(int i = 0; i < n; ++i)
	{
		cout << "Enter value to insert : ";
		int val;
		cin >> val;
		root = insertTreeNode(root, val);
	}
	cout << "PreOrder : " ;
	preOrder(root);
	cout << endl;


	cout << "InOrder : " ;
	inOrder(root);
	cout << endl;


	cout << "PostOrder : " ;
	postOrder(root);
	cout << endl;
}