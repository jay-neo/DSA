//						AVL Seach Tree
//AVL tree is a self-balancing Binary Search Tree (BST) 
//where the difference between heights of left and right subtrees 
//cannot be more than one for all nodes. 
#include<stdio.h>
#include<stdlib.h>

typedef struct avl_tree{
	int data;
	int height;
	struct avl_tree *left;
	struct avl_tree *right;
}node;
int max_height(node *n1,node *n2){
	if(n1==NULL && n2==NULL) return 0;
	if(n1==NULL)	return n2->height;
	if(n2==NULL)	return n1->height;
	return (n1->height>n2->height)?n1->height:n2->height;
}
int max(int a, int b){
	return(a>b)?a:b;
}
int height(node *N){
	if(N==NULL)
		return 0;
	return N->height;
}
node *left_rotate(node *prev){
	node *curr=prev->right;
	node *temp=curr->left;

	curr->left=prev;
	prev->right=temp;

	// prev->height=max_height(prev->left,prev->right)+1;
	// curr->height=max_height(curr->left,curr->right)+1;

	prev->height=max(height(prev->left),height(prev->right))+1;
	curr->height=max(height(curr->left),height(curr->right))+1;
	return curr;
}
node *right_rotate(node *prev){
	node *curr=prev->left;
	node *temp=curr->right;

	curr->right=prev;
	prev->left=temp;

	// prev->height=max_height(prev->left,prev->right)+1;
	// curr->height=max_height(curr->left,curr->right)+1;

	prev->height=max(height(prev->left),height(prev->right))+1;
	curr->height=max(height(curr->left),height(curr->right))+1;

	return curr;
}
int balance_factor(node *root){
	if(root==NULL)
		return 0;
	return (root->left->height-root->right->height);
}
node *insert(node *root, int d){
	int factor;
	node *neo=(node*)malloc(sizeof(node));
	neo->data=d;
	neo->left=NULL;
	neo->right=NULL;
	neo->height=1;
	if(root==NULL)
		root=neo;
	else if(d<root->data)
		root->left=insert(root->left,d);
	else if(d>root->data)
		root->right=insert(root->right,d);

	root->height=max(height(root->left),height(root->right))+1;
	factor=balance_factor(root);
	// Left Left Case
	if(factor>1 && d<root->left->data)
		return right_rotate(root);
    // Right Right Case
    if(factor<-1 && d>root->right->data)
    	return left_rotate(root);
    // Left Right Case
    if(factor>1 && d>root->left->data){
    	root->left=left_rotate(root->left);
    	return right_rotate(root);
    }
    // Right Left Case
    if(factor<-1 && d<root->right->data){
    	root->right=right_rotate(root->right);
    	return left_rotate(root);
    }
	return root;
}
node *binary_search(node *root, int key){
	if(root==NULL)
		return NULL;
	else if(key<root->data)
		return binary_search(root->left,key);
	else if(key>root->data)
		return binary_search(root->right,key);
	else
		return root;
}
void inorder_print(node *root){
	if(root==NULL)
		return;
	inorder_print(root->left);
	printf("%d ",root->data);
	inorder_print(root->right);
}
void preorder_print(node *root){
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder_print(root->left);
	preorder_print(root->right);
}
/*
node *inorder_successor(node *root){
	node *curr=root;
	while(curr && curr->left!=NULL)
		curr=curr->left;
	return curr;
}
*/
node *delete_node(node *root, int key){
	node *temp;
	if(root==NULL)
		return NULL;
	if(key<root->data)
		root->left=delete_node(root->left,key);
	else if(key>root->data)
		root->right=delete_node(root->right,key);
	else{
		if(root->left==NULL)				//For no child
			root=root->right;
		else if(root->right==NULL)			//For one child
			root=root->left;
		else{								//For two child
			temp=root->right;				//Using Inorder Successor
			while(temp && temp->left!=NULL)
				temp=temp->left;
			root->data=temp->data;
			root->right=delete_node(root->right,root->data);
		}
	}
	return root;
}
int main(){
	node *root=NULL;
	int t,d;
	printf("Enter how much value to insert in binary seach tree = ");
	scanf("%d",&t);
	while(t--){
		scanf("%d",&d);
		root=insert(root,d);
	}
	//inorder_print(root);
	printf("ok");
	preorder_print(root);
	// printf("Enter the key value to search = ");
	// scanf("%d",&d);
	// ((binary_search(root,d)->data)==d)?printf("True\n"):printf("False\n");
	// root=delete_node(root,d);
	// inorder_print(root);
}