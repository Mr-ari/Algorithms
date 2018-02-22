/* 
prgram name - "Counting Sort"
coded by - Mr.ari 
date - 17-02-2018
*/

#include<stdio.h>
#include<conio.h>

void counting_sort(int *arr,int n);
void printArray(int *arr,int size);

int main(){
	int n,i,*a;
	printf("Enter the number of items you want to enter:");
	scanf("%d",&n);
	int arr[n];a = &arr[0];
	printf("Enter the numbers now :\n");
	for (i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("Entered Array is :");
	printArray(&arr[0],n);
	printf("After sorting the array is :");
	counting_sort(a,n);
	getch();
	return 0;
}

void counting_sort(int *arr,int n){
	int hash[10]={0},final[n],i;;
	int *x=&final[0];
	for (i=0;i<n;i++){
		hash[*(arr+i)]++;
	}
	for (i=1;i<10;i++){
		hash[i] = hash[i]+hash[i-1];
	}
	for (i=0;i<n;i++){
			final[hash[*(arr+i)]-1] = *(arr+i);
			hash[*(arr+i)]--;
	}
	printArray(x,n);
}

void printArray(int *arr,int size){
	int i;
	for (i=0;i<size;i++) printf("%d  ",*(arr+i));
	printf("\n");
}
