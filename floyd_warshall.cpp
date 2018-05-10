#include<iostream>
using namespace std;

void print(int arr[][7],int n){
    for(int i=0;i<n;i++){for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";cout<<endl;}
}

void floyd_warshall(int arr[][7],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
            }
        }
    }
}

int main(){

    int n=5;
    int arr[n][n]={}; //Adjacency matrix for a graph
    floyd_warshall(arr,n);
}