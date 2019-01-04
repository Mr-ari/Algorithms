/*

Implementation of Heap Data Structure using priority queue STL in build DS 
Author : ari
Date   : 01-01-2019

*/

#include<bits/stdc++.h>
using namespace std;


template <typename T> void print_priority_queue(T &q){
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    // implementation of the max heap top() will return the max element
    priority_queue<int> pq ;
    for (int n : {1,8,6,7,2,4,3,5,0,9}) pq.push(n);
    print_priority_queue(pq);


    // implementation of min heap ... top() will return the min element 
    priority_queue <int , vector<int> , greater<int> > pq2 ;
    for(int n: {1,8,6,7,2,4,3,5,0,9}) pq2.push(n);
    print_priority_queue(pq2);
}