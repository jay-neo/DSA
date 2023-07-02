//Circular queue with using modulo
#include<stdio.h>
#define MAX 3


int queue[MAX];
int front=-1;
int rear=-1;


void enque(int data){
	if(front==(rear+1)%MAX){
		printf("Circular Queue is full!\n");
		return;
	}
	if(front==-1)	
		front++;
	rear=(rear+1)%MAX;
	queue[rear]=data;
}


void delque(){
	if(front==-1 && rear==-1){
		printf("Circular Queue is empty!\n");
		return;
	}

	printf("Deleted element is %d\n",queue[front]);
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else
		front=(front+1)%MAX;
}


void display(){
	int i;
	if(front==-1 && rear==-1){
		printf("Circular Queue is empty!\n");
		return;
	}
	
	printf("Circular Queue is:\n");
	for(i=front;i!=rear;i=(i+1)%MAX)
		printf("%d ",queue[i]);
	printf("%d ",queue[i]);
	printf("\n");
}



int main(){
	int c,n,flag=1;
	while(flag){
		printf("For Circular Queue Maniulation\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice = ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter the value to be inserted = ");
				scanf("%d",&n);
				enque(n);
				break;
			case 2:
				delque();
				break;
			case 3:
				display();
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Invalid Input!\n");
		}
	}
}



/*
//Circular queue without using modulo
#include<stdio.h>
#define MAX 5


int queue[MAX];
int front=-1;
int rear=-1;


void enque(int d){
	if((front==-1 && rear==MAX-1) || (front==rear+1)){
		printf("Cirluar Queue is full.\n");
		return;
	}

	if(front==-1){
		front=0;
		rear=0;
	}
	else if(rear==MAX-1)
		rear=0;
	else
		rear++;
	queue[rear]=d;
}


void delque(){
	if(front==-1){
		printf("Circular Queue is empty!\n");
		return;
	}

	printf("Deleted element is %d\n",queue[front]);
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
		front=0;
	else
		front++;
}


void display(){
	int i;
	if(front==-1)
		printf("Circular Queue is empty!");
	else if(front<=rear){
		printf("Circular Queue is:\n");
		for(i=front;i<=rear;i++)
			printf("%d ",queue[i]);
	}
	else{
		printf("Circular Queue is:\n");
		for(i=front;i<=MAX-1;i++)
			printf("%d ",queue[i]);
		for(i=0;i<=rear;i++)
			printf("%d ",queue[i]);
	}
	printf("\n");
}



int main(){
	int c,n,flag=1;
	while(flag){
		printf("For Circular Queue Maniulation\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice = ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter the value to be inserted = ");
				scanf("%d",&n);
				enque(n);
				break;
			case 2:
				delque();
				break;
			case 3:
				display();
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Invalid Input!\n");
		}
	}
}
*/


// code by jay-neo
