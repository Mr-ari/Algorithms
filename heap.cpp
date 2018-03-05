/*
-------------------------------------------------------------------------------------------------

PROGRAM NAME - Heap Algorithms
DATE - 23-02-2018
CODED BY - Mr-ari

-------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;


void swap(int *x,int *y);

class minHeap{
	int capacity;
	int heapSize;
	int *heap;

public:
	void initialMinHeap(int val);
	int parent(int i);
	int right(int i);
	int left(int i);
	void minHeapify(int root);
	void insertKey(int value);
	void decreaseKey(int i,int newVal);
	int extractHeap(void);
	void deleteKey(int i);
	int getMin(void);
};

void minHeap :: initialMinHeap(int val){
	capacity = val;
	heapSize = 0;
	heap = new int [capacity];
	if (!heap) {
		cout<<"Overflow....Exiting"<<endl;
		exit(0);
	}
} 

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int minHeap :: parent(int i){
	return (i-1)/2;
}

int minHeap :: right(int i){
	return (2*i)+2;
}

int minHeap :: left (int i){
	return (2*i)+1;
}

int minHeap :: getMin(void){
	return heap[0];
}
//Inserts a new key into the heap
//this function returns 0 if array is overloaded else returns 1

void minHeap :: insertKey(int value){
 if (heapSize == capacity){
 	cout<<"Overflow"<<endl;
 	return;
 }
 //first inserting the value to the heap then incease the heapsize by 1
 heap[heapSize] = value;
 int i = heapSize;
 heapSize++;

 while (i != 0 && heap[parent(i)] > heap[i]){
 	swap(&heap[parent(i)] , &heap[i]);
 	i = parent (i);
 }
}

void minHeap :: minHeapify (int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heapSize && heap[l] < heap[i]) smallest = l;
	if (r < heapSize && heap[r] < heap[smallest]) smallest = r;
	if (smallest != i){
		swap(&heap[smallest],&heap[i]);
		minHeapify(smallest);
	}
}

//this function enter a value of the key at the position i ... we assume that the key is smaller than the previous key

void minHeap :: decreaseKey(int i,int newVal){
	heap [i] = newVal;
	while (i != 0 && heap[parent(i)] > heap[i]){
		swap (&heap[parent(i)] , &heap[i]);
		i=parent(i);
	}
}

//this function returns the smallest number from the min heap (or root)
int minHeap :: extractHeap(){
	if (heapSize <= 0) return INT_MIN;
	if (heapSize == 1){
		heapSize--;
		return heap[0];
	}
	int root = heap[0];
	heap[0] = heap [heapSize-1];
	heapSize--;
	minHeapify(0);
	return root;
}

void minHeap :: deleteKey(int i){
	decreaseKey(i,INT_MIN);
	extractHeap();
}

int main(void){

	minHeap h;
	h.initialMinHeap(10);
	h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(8);
    h.insertKey(10);

	cout << h.extractHeap() << " ";
    cout << h.extractHeap() << " ";
    cout << h.extractHeap() << " ";
    cout << h.extractHeap() << " ";
    cout << h.extractHeap() << " ";
    cout << h.extractHeap() << " ";
	return 0;
}
