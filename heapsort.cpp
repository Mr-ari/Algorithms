#include<iostream>
#define CAPACITY 10
using namespace std;

class Maxheap{
	int *heap;
	int heapsize;
	public:
		//constractor
	Maxheap(int *arr,int val){
		heapsize = val;
		heap = arr;
	}	
	int parent(int i){
	 	return (i-1)/2;
	}
	int left(int i){
		return (2*i)+1;
	}
	int right(int i){
		return (2*i)+2;
	}
	void buildMaxHeap(void);
    void maxHeapify(int i);
    int getMaxOut(void);
    void heapsort(int *arr);
};
void swap(int *x,int *y){
	int temp = *y;
	*y = *x;
	*x = temp;
}

void Maxheap :: buildMaxHeap(){
	for (int i=(heapsize/2)-1;i>=0;i--){
		maxHeapify(i);
	}
}

void Maxheap :: maxHeapify(int i){
	int largest = i;
	int l = left(i);
	int r = right(i);

	if (l < heapsize && heap[l]>heap[i]) largest = l;
	if (r < heapsize && heap[r]>heap[largest]) largest = r;
	if (largest != i){
		swap(&heap[largest],&heap[i]);
		maxHeapify(largest);
	}
}

int Maxheap :: getMaxOut(){
	if (heapsize <= 0) return INT_MAX;
	if (heapsize == 1) {
		heapsize --;
		return heap[0];
	}
	int root = heap[0];
	heap[0] = heap[heapsize-1];
	heapsize--;
	maxHeapify(0);
	return root;
}

void Maxheap :: heapsort(int *arr){
	buildMaxHeap();
	int x = heapsize;
	for (int i=0;i<x;i++){
		arr[i] = getMaxOut();
	}
}

int main(void){
	int size;
	cout<<"ENTER THE NUMBER OF VALUE YOU WANT TO ENTER : ";
	cin>>size;
	int *arr = new int[size];
	int *final = new int[size];
	cout<<"enter your values now"<<endl;
	for (int i=0;i<size;i++) cin >> arr[i];
    Maxheap maxh(arr,size);
	maxh.heapsort(final);
	cout<<endl<<"In desending order - ";
	for (int i=0;i<size;i++) cout<<final[i]<<" ";
	return 0;
}


