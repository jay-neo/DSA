#include<stdio.h>
#include<stdlib.h>


typedef struct Stack{
	int data;
	struct Stack *link;
}node;


node *push(node *head,int d){

	node *neo=(node*)malloc(sizeof(node));
	neo->data=d;
	neo->link=NULL;


	if(head==NULL)
		head=neo;
	else{
		neo->link=head;
		head=neo;
	}

	return head;
}


node *pop(node *head){
	if(head==NULL){
		printf("\n\t\t\t\tStack is empty!!\n");
		return head;
	}

	node *temp=head;
	head=head->link;

	free(temp);

	return head;
}


void top(node *head){
	if(head==NULL) printf("Stack is empty!!\n");
	else printf("Top element is %d\n",head->data);
}


void display(node *head){
	if(head==NULL){
		printf("\n\t\t\t\tStack is empty!!");
		return;
	}

	printf("\n\t\t\t\tThe Stack is: ");

	node *curr=head;
	while(curr!=NULL){
		printf("%d ",curr->data);
		curr=curr->link;
	}

	printf("\n");
}


int main(){
	node *head=NULL;
	int d,c,flag=1;


	while(flag){
		printf("For Stack Maniulation\n1. Push\n2. Pop\n3. Top\n4. Print\n5. Exit\nEnter your choice = ");
		scanf("%d",&c);


		switch(c){
			case 1:
				printf("Enter the value to be inserted = ");
				scanf("%d",&d);
				head=push(head,d);
				break;

			case 2:
				head=pop(head);
				break;

			case 3:
				top(head);
				break;

			case 4:
				display(head);
				break;

			case 5:
				flag=0;
				break;

			default:
				printf("Invalid Input Found!\n");
				break;
		}
	}

}

