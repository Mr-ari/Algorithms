#include<stdio.h>
#include<conio.h>

int *counting_sort(int *arr,int n);
void printArray(int *arr,int size);

int main(){
	int n,i;
	printf("Enter the number of items you want to enter:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the numbers now :\n");
	for (i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("Entered Array is :");
	printArray(&arr[0],n);
	int *final = counting_sort(&arr[0],n);
	printf("After sorting the array is :");
	printArray(counting_sort(&arr[0],n),n);
	getch();
	return 0;
}

int *counting_sort(int *arr,int n){
	int hash[10]={0},final[n];int i=0;
	for (;i<n;i++){
		hash[*(arr+i)]++;
	}
	for (i=1;i<10;i++){
		hash[i] = hash[i]+hash[i-1];
	}
	for (i=0;i<n;i++){
			final[hash[*(arr+i)]-1] = *(arr+i);
			hash[*(arr+i)]--;
	}
	return &final[0];
}

void printArray(int *arr,int size){
	int i;
	for (i=0;i<size;i++) printf("%d  ",*(arr+i));
	printf("\n");
}
