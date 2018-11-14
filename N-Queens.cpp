#include<bits/stdc++.h>
using namespace std;


void print(int *arr,int N){
    cout<<"Printing Result...\n\n";
    cout<<"Row | Col\n";
    for(int i = 0;i<N;i++) cout<<arr[i]<<"   |   "<<i<<"\n";
}

bool is_safe(int *queen,int N,int row,int col){
    for(int i=0;i<N;i++){
        if(queen[i] == -1) break;
        else{
            int coll = i;
            int roww = queen[i];
            if(row == roww ) return false;
            else if (abs(col - coll) == abs(row-roww)) return false; 
        }
    }
    return true;
}
bool placeQueen(int *queen,int N,int col){
    if (col >= N) return true;
    for(int row=0;row<N;row++){
        if (is_safe(queen,N,row,col)) {
            queen[col]=row;
            if(placeQueen(queen,N,col+1)) return true;
            queen[col] = -1; 
        }
    }
    return false;

}
int* N_Queen(int N){
    int *queens = new int[N];
    for (int i=0;i<N;i++) queens[i]=-1;
    if (placeQueen(queens,N,0)) return queens;
    queens[0] = -1;
    return queens;
}

int main(){
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;

    int *result = N_Queen(n);
    if(result[0] == -1) cout<<"Cannot find a solution\n";
    else print(result,n);
}