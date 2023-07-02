#include<stdio.h>
#define MAX 10

char lqueue[MAX];
int f=-1,r=-1;

void enque(char data){
	if(r==MAX-1)
		printf("Queue is overflow condition!\n");
	else{
		r++;
		lqueue[r]=data;
	}
	if(f==-1)
		f++;
}


char delque(){
	char data;
	if(f==-1 && r==-1)
		printf("Queue is underflow condition!\n");
	else if(f==r){
		data=lqueue[f];
		f=r=-1;
		return data;
	}
	else{
		data=lqueue[f];
		f++;
		return data;
	}
}


void display(){
	int i;
	
	if(f==-1 && r==-1)
		printf("Queue is underflow cindition!\n");
	else{
		printf("Queue is:\n");
		for(i=f;i<=r;i++)
			printf("%c ",lqueue[i]);
		printf("\n");
	}
}


int main(){
	char n;
	int c,flag=1;


	while(flag){
		printf("For Linear Queue Maniulation\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice = ");
		scanf("%d",&c);

		switch(c){
			case 1:
				printf("Enter the value to be inserted = ");
				scanf(" %c",&n);
				enque(n);
				break;

			case 2:
				if(f==-1 && r==-1)
					printf("Queue is underflow condition!\n");
				else
					printf("Deleted element is %c\n",delque());
				break;

			case 3:
				display();
				break;

			case 4:
				flag=0;
				break;

			default:
				printf("Invalid Input\n");
		}
	}
}