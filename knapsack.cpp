#include<iostream>
using namespace std;

inline int max(int a,int b){
	if (a>b) return a;
	return b;
}
int knapsack(int w[],int v[],int n,int W){
	int mem[n+1][W+1];
	for (int i=0;i<=n;i++){
		for (int j=0;j<=W;j++){
			if(i==0 || j == 0) mem[i][j] = 0;
			else if (w[i-1] <= j) mem[i][j] = max(v[i-1]+mem[i-1][W-w[i-1]],mem[i-1][j]);
			else mem[i][j]=mem[i-1][j];
		}
	}
	return mem[n][W];
}
int main(){
	int n=3;
	int w[n]={10,20,30};
	int v[n]={60,100,120};
	int W=50;
	cout<<"The maximum value is = "<<knapsack(w,v,n,W)<<endl;
}