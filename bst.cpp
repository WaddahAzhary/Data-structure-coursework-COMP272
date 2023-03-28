/* 
Wadah Elsiddig
3385818
COMP272
*/
#include<iostream>
using namespace std;
 
struct Node {
	int value;
	struct Node *left;
	struct Node *right;
};

//Function to visit nodes in preOrderTraversal
void preOrderTraversal(struct Node *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	printf("%d ",root->value); // Print value
	preOrderTraversal(root->left);     // Visit left subtree
	preOrderTraversal(root->right);    // Visit right subtree
}

//Function to visit nodes in inOrderTraversal
void inOrderTraversal(Node *root) {
	if(root == NULL) return;

	inOrderTraversal(root->left);       //Visit left subtree
	printf("%d ",root->value);  //Print value
	inOrderTraversal(root->right);      // Visit right subtree
}

//Function to visit nodes in postOrderTraversal
void postOrderTraversal(Node *root) {
	if(root == NULL) return;

	postOrderTraversal(root->left);    // Visit left subtree
	postOrderTraversal(root->right);   // Visit right subtree
	printf("%d ",root->value); // Print value
}

// Function to insertNode Node in a Binary Search Tree
Node* insertNode(Node *root,int value) {
	if(root == NULL) {
		root = new Node();
		root->value = value;
		root->left = NULL;
		root->right = NULL;
	}
	else if(value <= root->value)
		root->left = insertNode(root->left,value);
	else 
		root->right = insertNode(root->right,value);
	return root;
}
 
int main() {
	/*Code To Test the logic
	  Creating an example tree
	             10
			   /   \
			  5     15
			 / \    / \
			1   7  12   20
    */
	Node* root = NULL;
	root = insertNode(root,10); 
	root = insertNode(root,5);
	root = insertNode(root,1); 
	root = insertNode(root,7); 
	root = insertNode(root,15); 
	root = insertNode(root,12);
	root = insertNode(root,20);

	//Print Nodes in preOrderTraversal. 
	cout<<"The order of the elements for preOrderTraversal is: ";
	preOrderTraversal(root);
	cout<<"\n";

	//Print Nodes in postOrderTraversal
	cout<<"The order of the elements for postOrderTraversal is: ";
	postOrderTraversal(root);
	cout<<"\n";

	//Print Nodes in inOrderTraversal
	cout<<"The order of the elements for inOrderTraversal is: ";
	inOrderTraversal(root);
	cout<<"\n";
	
}