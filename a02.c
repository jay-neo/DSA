#include<stdio.h>
#define MAX 10

int stack[MAX];
int t=-1;

void push(int data){
	if(t==MAX-1)
		printf("Stack is overflow condition!\n");
	else{
		t++;
		stack[t]=data;
	}
}

int pop(){
	int data;
	data=stack[t];
	t--;
	return data;
}


void display(){
	int i;
	if(t==-1)
		printf("Stack id underflow cindition!\n");
	else{
		printf("Stack is:\n");
		for(i=0;i<=t;i++)
			printf("%d ",stack[i]);
		printf("\n");
	}
}


int main(){
	int n,c,flag=1;


	while(flag){
		printf("For Stack Maniulation\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice = ");
		scanf("%d",&c);

		switch(c){
			case 1:
				printf("Enter the value to be inserted = ");
				scanf("%d",&n);
				push(n);
				break;

			case 2:
				if(t==-1)
					printf("Stack is underflow condition!\n");
				else
					printf("Poped element is %d\n",pop());
				break;

			case 3:
				display();
				break;

			case 4:
				flag=0;
				break;

			default:
				printf("Invalid Input");
		}
	}


}