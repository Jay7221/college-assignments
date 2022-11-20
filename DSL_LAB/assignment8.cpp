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
TreeNode insertTreeNode(TreeNode *root, int data){
	if(root == NULL)
		return new TreeNode(data);
	if(root -> left == NULL)
		root -> left = insertTreeNode(root -> left, data);
	else
		root -> right = insertTreeNode(root -> right, data);
	return root;
}
class BinaryTree{
	public:
		TreeNode *root;
		TreeNode insert(int data){
			root = insertTreeNode(root, data);
		}
};
