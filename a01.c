#include <stdio.h>
#define MAX 20

int n;

void Insert(int arr[]){
	int i,p,c,key;

	printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at any position\n");
	printf("Enter ypur choice: ");
	scanf("%d",&c);
	printf("Enter the value to be inserted: ");
	scanf("%d",&key);


	switch(c){
		case 1:
			for(i=n-1;i>=0;i--)
				arr[i+1]=arr[i];
			arr[0]=key;
			n++;
			break;
		case 2:
			arr[n]=key;
			n++;
			break;
		case 3:
			printf("Enter the position to insert: ");
			scanf("%d",&p);
			if(p>0 && p<=n+1){
				for(i=n;i>=p;i--)
					arr[i]=arr[i-1];
				arr[p-1]=key;
				n++;
			}
			else printf("Invalid input.");
			break;

		default:
			printf("Invalid Input!");
			break;
	}
}

void Delete(int arr[]){
	int i,c,p;

	printf("\n1.Delete at beginning\n2.Delete at end\n3.Delete at any position\n");
	printf("Enter your choice: ");
	scanf("%d",&c);

	switch(c){
		case 1:
			for(i=0;i<n;i++)
				arr[i]=arr[i+1];
			n--;
			break;

		case 2:
			n--;
			break;

		case 3:
			printf("Enter the position to delete: ");
			scanf("%d",&p);
			if(p>0 && p<=n){
				for(i=p-1;i<n-1;i++)
					arr[i]=arr[i+1];
				n--;
			}
			else printf("Invalid input.");
			break;

		default:
			printf("Invalid Input!");
			break;
	}
}

void Replace(int arr[]){
	int p;
	printf("Enter the position to replace: ");
	scanf("%d",&p);

	if(p>0 && p<=n){
		printf("Enter the value to replace: ");
		scanf("%d",&arr[p-1]);
	}
	else printf("Invalid input.");
}


void Search(int arr[]){
	int i,p;

	printf("Enter the searching value: ");
	scanf("%d",&p);

	for(i=0;i<n;i++) if(arr[i]==p) break;

	if(i<n) printf("%d is found at position %d",p,i+1);
	else printf("%d is not found.",p);

}

void Display(int arr[]){
	int i;
	printf("The Array is:\n");
	for(i=0;i<n;i++) printf("%d ",arr[i]);
}

int main(){
	int i,c,flag=1;
	int arr[MAX];

	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of array:\n");
	for(i=0;i<n;i++) scanf("%d",&arr[i]);


	while(flag){
		printf("\n1. Insertion\n2. Deletion\n3. Replace\n4. Searching\n5. Display\n6. Exit\n");
		printf("Enter your choice = ");
		scanf("%d",&c);


		switch(c){

			case 1:	//Insertion
				if(n<MAX) Insert(arr);
				else printf("The Container Array is full.");
				break;

			case 2:	//Deletion
				if(n==0) printf("Array is empty.");
				else Delete(arr);
				break;

			case 3:	//Replace
				if(n==0) printf("Array is empty.");
				else Replace(arr);
				break;

			case 4:	//Searching
				if(n==0) printf("Array is empty.");
				else Search(arr);
				break;

			case 5:	//For display
				Display(arr);
				break;

			case 6:
				flag=0;
				break;

			default:
				printf("Invalid input!");
		}

	}


	return 0;
}

