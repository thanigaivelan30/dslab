#include<stdio.h>
void insertionSort(int arr[],int n){
	int i,key,j;
	for(i=1;i<n;i++){
	    key=arr[i];
	    j=i-1;
	    while(j>=0&&arr[j]>key){
	        arr[j+1]=arr[j];
	        j--;
	    }
	    arr[j+1]=key;
	}
}
void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
	    printf("%d",arr[i]);
	}
	printf("\n");
}
int main(){
	int choice,n,i;
	printf("\n-----INSERTION SORT------\n");
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
	   scanf("%d",&arr[i]);
	}
	do{
	   printf("\nMenu:\n");
	   printf("1.Sort using Insertion sort\n");
	   printf("2.Print the sorted array\n");
	   printf("3.Exit\n");
	   printf("Enter your choice:");
	   scanf("%d",&choice);
	   switch(choice){
	      case 1: 
	          insertionSort(arr,n);
	          printf("Array sorted using Insertion sort.\n");
	          break;
	      case 2:
	          printf("Sorted array:");
	          printArray(arr,n);
	          break;
	      case 3:
	          printf("Exiting the program.\n");
	          break;
	      default:
	          printf("Invalid choice!Please enter a valid menu option.\n");
	  }
       }while(choice !=3);
	return 0;
}
