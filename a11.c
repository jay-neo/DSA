#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree{
	int data;
	struct binary_tree *left;
	struct binary_tree *right;
}node;


node *insert(node *root, int d){
	node *neo=(node*)malloc(sizeof(node));
	neo->data=d;
	neo->left=NULL;
	neo->right=NULL;

	if(root==NULL) root=neo;
	else if(d<root->data) root->left=insert(root->left,d);
	else root->right=insert(root->right,d);

	return root;
}


void preorder_print(node *root){
	if(root==NULL) return;
	printf("%d ",root->data);
	preorder_print(root->left);
	preorder_print(root->right);
}

void inorder_print(node *root){
	if(root==NULL) return;
	inorder_print(root->left);
	printf("%d ",root->data);
	inorder_print(root->right);
}

void postorder_print(node *root){
	if(root==NULL) return;
	postorder_print(root->left);
	postorder_print(root->right);
	printf("%d ",root->data);
}

int main(){
	node *root=NULL;
	int t,d;

	printf("Enter how much value to insert in binary seach tree = ");
	scanf("%d",&t);

	printf("Enter the %d elements:\n",t);
	while(t--){
		scanf("%d",&d);
		root=insert(root,d);
	}


	printf("<---Preorder Traverse--->\n");
	preorder_print(root);
	printf("\n<---Inorder Traverse--->\n");
	inorder_print(root);
	printf("\n<---Prstorder Traverse--->\n");
	postorder_print(root);
	printf("\n");
}


// code by jay-neo