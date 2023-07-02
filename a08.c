#include<stdio.h>
#include<stdlib.h>


typedef struct polynomial{
	int coeff,exp;
	struct polynomial *link;
}node;


void display(node *head){
	node *ptr=NULL;

	if(head==NULL)
		printf("Linked List is empty!");
	else{
		ptr=head;

		while(ptr!=NULL){
			if(ptr->link==NULL && ptr->exp==0)
				printf("%d",ptr->coeff);

			else if(ptr->link==NULL)
				printf("%dx^%d",ptr->coeff,ptr->exp);

			else if(ptr->link->coeff>0)
				printf("%dx^%d + ",ptr->coeff,ptr->exp);

			else
				printf("%dx^%d ",ptr->coeff,ptr->exp);

			ptr=ptr->link;
		}

		printf("\n");
	}

}


node *insert(node *head,int c,int e){
	node *ptr=NULL;

	node *neo=(node*)malloc(sizeof(node));
	neo->coeff=c;
	neo->exp=e;
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



node *add_poly(node *head1,node *head2,node *neon){
	node *h1=head1;
	node *h2=head2;


	while(h1!=NULL && h2!=NULL){
		if((h1->exp>h2->exp)){
			neon=insert(neon,h1->coeff,h1->exp);
			h1=h1->link;
		}
		else if((h1->exp<h2->exp)){
			neon=insert(neon,h2->coeff,h2->exp);
			h2=h2->link;
		}
		else{
			neon=insert(neon,(h1->coeff+h2->coeff),h1->exp);
			h1=h1->link;
			h2=h2->link;
		}
	}


	if(h1==NULL){
		while(h2!=NULL){
			neon=insert(neon,h2->coeff,h2->exp);
			h2=h2->link;
		}
	}

	else if(h2==NULL){
		while(h1!=NULL){
			neon=insert(neon,h1->coeff,h1->exp);
			h1=h1->link;
		}
	}

	return neon;
}


node *input_poly(node *head,int p){
	int c,e,t,k=1;

	printf("Enter the number of terms in %d-th polynomial = ",p);
	scanf("%d",&t);

	while(t--){
		printf("Enter the %d term's coefficient = ",k);
		scanf("%d",&c);
		printf("Enter the %d term's exponential = ",k);
		scanf("%d",&e);

		head=insert(head,c,e);
		k++;
	}

	return head;
}


int main(){
	node *head1=NULL;
	node *head2=NULL;
	node *neon=NULL;

	
	head1=input_poly(head1,1);
	head2=input_poly(head2,2);

	display(head1);
	display(head2);


	neon=add_poly(head1,head2,neon);

	display(neon);


}

// code by jay-neo
