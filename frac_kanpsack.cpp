//coded by Mr.ari



#include<bits/stdc++.h>
#define W 50
using namespace std;

double frac_knap(int *w,int *v,int n);
int findIndex(double *arr,int n);

int main(){

	int w[3]={10,20,30};
	int v[3]={60,100,120};

	cout<<"The maximum we can get is : "<<frac_knap(w,v,3);
}

int findIndex(double *arr,int n){
	int max=0;
	for (int i = 0;i<n;i++){
		if (arr[i]>arr[max]) max=i;
	}
	arr[max] = -1.0;
	return max;
}
double frac_knap(int *w,int *v,int n){
	double arr[n];static double count=0.0;static int tot=0;
	for (int i = 0;i<n;i++) arr[i]=v[i]/w[i];
	for (int i = 0;i<n;i++){
		int j=findIndex(arr,n);
		//cout<<j<<" ";
		tot+=w[j];
		if (tot<=W) count += v[j];
		else{
			int rem = tot - W;
			count += ((v[i]/w[i])*(w[j]-rem));
		}
	//	cout<<count<<endl;
	}
	return count;	
}