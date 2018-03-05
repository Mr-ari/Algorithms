#include<iostream>
using namespace std;


void swap(int *x,int *y){
	int temp = *y;
	*y = *x;
	*x = temp;
}

class maxHeap{
	int *heap;
	int heapsize;
	int capacity;
	
public:
	void initialMaxHeap(int val);
	void maxHeapify(int i);
	int extractHeap(void);
	int deleteKey(int i);
	void insertKey(int value);
	int parent(int i){return (i-1)/2;}
	int left(int i){return (2*i)+1;}
	int right(int i){return (2*i)+2;}
};

void maxHeap :: initialMaxHeap(int val){
	capacity = val;
	heapsize = 0;
	heap = new int[capacity];

	if (!heap){
		cout<<"Overflow"<<endl;
		exit(0);
	}
}

void maxHeap :: maxHeapify(int i){
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

//function returns the largest value from the heap;
int maxHeap :: extractHeap(void){
	if(heapsize <= 0) return INT_MAX;
	if (heapsize == 1){
		heapsize --;
		return heap[0];
	}

	int largest = heap[0];
	heap[0] = heap[heapsize - 1];
	heapsize--;
	maxHeapify(0);
	return largest;
}

void maxHeap :: insertKey(int val){
	if (heapsize == capacity){
		cout<<"Overflow"<<endl;
		return;
	}
	heap[heapsize] = val;
	int i=heapsize;
	heapsize++;
	if (i != 0 && heap[parent(i)]<heap[i]){
		swap(&heap[parent(i)],&heap[i]);
		i = parent(i);
	}
}


int main(){

	maxHeap h;
	h.initialMaxHeap(10);
	h.insertKey(5);
	h.insertKey(8);
	h.insertKey(1);
	h.insertKey(6);
	h.insertKey(4);
	h.insertKey(10);
	
	h.maxHeapify(0);
	cout<<h.extractHeap()<<" ";
	cout<<h.extractHeap()<<" ";
	cout<<h.extractHeap()<<" ";
	cout<<h.extractHeap()<<" ";
	cout<<h.extractHeap()<<" ";
	cout<<h.extractHeap()<<" ";
	return 0;
}
