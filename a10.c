#include<stdio.h>
#define MAX 20


void bsort(int arr[],int n){
	int i,j,temp;

	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1])
				arr[j]=arr[j+1]+arr[j]-(arr[j+1]=arr[j]);
	}

}


void binary_search(int arr[],int n,int key){
	int left=0;
	int right=n-1;
	int mid,i,ct=0;

	while(left<=right){
		ct++;
		mid=(left+right)/2;

		if(arr[mid]==key){
			printf("\nSorted array:\n");
			for(i=0;i<n;i++) printf("%d ",arr[i]);
			printf("\nThe searching value found in %d position of sorted array.",mid+1);
			printf("\nNumber of iterations for binary search = %d",ct);
			return;
		}

		else if(key<arr[mid]) right=mid-1;

		else left=mid+1;
	}

	printf("\nThe searching value not found!\n");

}



void interpolation_search(int arr[],int n,int key){
	int left=0;
	int right=n-1;
	int mid,i,ct=0;

	while(left<=right){
		ct++;
		mid=left+(((double)(right-left)/(arr[right]-arr[left]))*(key-arr[left]));

		if(arr[mid]==key){
			printf("\nSorted array:\n");
			for(i=0;i<n;i++) printf("%d ",arr[i]);
			printf("\nThe searching value found in %d position of sorted array.\n",mid+1);
			printf("\nNumber of iterations for interpolation search = %d",ct);
			return;
		}

		else if(key<arr[mid]) right=mid-1;

		else left=mid+1;
	}

	printf("\nThe searching value not found!");

}



int main(){
	int i,n,key;
	int arr[MAX];


	printf("Enter the nummber of elements = ");
	scanf("%d",&n);

	printf("Enter the elements of array:\n");
	for(i=0;i<n;i++) scanf("%d",&arr[i]);


	printf("Enter the searching value = ");
	scanf("%d",&key);

	printf("Given array:\n");
	for(i=0;i<n;i++) printf("%d ",arr[i]);

	bsort(arr,n);


	binary_search(arr,n,key);
	interpolation_search(arr,n,key);
}

// code by jay-neo

