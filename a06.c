#include<stdio.h>
#include<stdlib.h>
									// coding is an art for anxiety

typedef struct ListNode{
	int data;
	struct ListNode *link;
}node;



node *insert(node *head){
	int ch,d,p;
	node *neo=(node*)malloc(sizeof(node));
	node *ptr=NULL;

	printf("1. At Beginning\n2. At End\n3. At any position\nEnter your choice = ");
	scanf("%d",&ch);
	printf("Enter the value to be inserted = ");
	scanf("%d",&d);

	neo->data=d;
	neo->link=NULL;

	if(head==NULL){
		head=neo;
		return head;
	}

	switch(ch){
		case 1:
			neo->link=head;
			head=neo;
			break;

		case 2:
			ptr=head;
			while(ptr->link!=NULL){
				ptr=ptr->link;
			}
			ptr->link=neo;
			break;

		case 3:
			printf("Enter the position = ");
			scanf("%d",&p);
			ptr=head;
			if(p<1){
				printf("\n\t\t\t\tInvalid Position Input!!!\n");
			}
			else if(p==1){
				neo->link=head;
				head=neo;
			}
			else{
				for(;p>2;p--){
					if(ptr->link==NULL){
						printf("\n\t\t\t\tInvalid Position Input!!!\n");
						return head;
					}
					ptr=ptr->link;
				}
				neo->link=ptr->link;
				ptr->link=neo;
			}
			break;

		default:
			printf("\n\t\t\t\tInvalid Choice Input!\n");
			break;
	}

	return head;
}


node *del_list(node *head){
	int ch,p;
	node *prev=NULL;
	node *curr=NULL;

	printf("1. At Beginning\n2. At End\n3. At any position\nEnter your choice = ");
	scanf("%d",&ch);

	if(head==NULL){
		printf("\n\t\t\t\tLinked list is empty!!\n");
		return head;
	}

	switch(ch){
		case 1:
			curr=head;
			head=head->link;
			break;

		case 2:
			curr=head;
			if(head->link==NULL){
				head=NULL;
			}
			else{
				while(curr->link!=NULL){
					prev=curr;
					curr=curr->link;
				}
				prev->link=NULL;
			}
			break;

		case 3:
			printf("Enter the position = ");
			scanf("%d",&p);
			curr=head;
			if(p<1){
				printf("\n\t\t\t\tInvalid Position Input!!!\n");
			}
			else if(p==1){
				head=head->link;
			}
			else{
				for(;p>1;p--){
					if(curr->link==NULL){
						printf("\n\t\t\t\tInvalid Position Input!!!\n");
						return head;
					}
					prev=curr;
					curr=curr->link;
				}
				prev->link=curr->link;
			}
			break;

		default:
			printf("\n\t\t\t\tInvalid Choice Input!\n");
			break;
	}

	free(curr);
	curr=NULL;

	return head;
}

void print_ll(node *head){
	node *ptr=head;

	if(head==NULL){
		printf("\n\t\t\t\tLinked List is empty!!");
		return;
	}
	
	printf("\n\t\t\t\tThe Linked List is: ");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}


int main(){
	int c,flag=1;
	node *head=NULL;


	while(flag){
		printf("For Linked List Manipulation\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice = ");
		scanf("%d",&c);

		switch(c){
			case 1:
				head=insert(head);
				break;

			case 2:
				head=del_list(head);
				break;

			case 3:
				print_ll(head);
				break;

			case 4:
				flag=0;
				break;

			default:
				printf("\n\t\t\t\tInvalid Choice Input!\n");
				break;
		}
		printf("\n\n");
	}
}

// code by jay-neo