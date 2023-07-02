#include<stdio.h>
#include<stdlib.h>


typedef struct stack{
	int data;
	struct stack *link;
}node;



node *enque(node *head,int d){
	node *ptr=NULL;
	node *neo=(node*)malloc(sizeof(node));
	neo->data=d;
	neo->link=NULL;
	if(head==NULL)
		head=neo;
	else{
		ptr=head;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=neo;
	}
	return head;
}

int delque(node **head){
	int d;
	if((*head)->link==NULL){
		d=(*head)->data;
		(*head)=NULL;
	}
	else{
		d=(*head)->data;
		*head=(*head)->link;
	}
	return d;
}


void print(node *head){
	node *ptr=NULL;
	if(head==NULL)
		printf("\n\t\t\t\tQueue is empty!!");
	else{
		printf("\n\t\t\t\tThe Queue is: ");

		ptr=head;
		while(ptr!=NULL){
		 	printf("%d ",ptr->data);
			ptr=ptr->link;
		}
	}
	printf("\n");
}



int main(){
	int c,d,flag=1;
	node *head=NULL;
	while(flag){
		printf("For Queue Manipulation\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice = ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter the value to be inserted = ");
				scanf("%d",&d);
				head=enque(head,d);
				break;
			case 2:
				if(head!=NULL) printf("Deleted element is %d\n",delque(&head));
				else printf("\n\t\t\t\tQueue is empty!!\n");
				break;
			case 3:
				print(head);
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("\n\t\t\t\tInvalid Choice Input!\n");
				break;

		}
	}
}

// code by jay-neo