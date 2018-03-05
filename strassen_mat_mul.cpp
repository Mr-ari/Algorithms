#include<iostream>
using namespace std;

void printArray(int a[2][2]);
void solve(int a[2][2],int b[2][2]);

int main(){
	
	int a[2][2] = {1,5,4,2};
	int b[2][2] = {5,4,65,5};
	printArray(a);
	cout<<endl<<"X"<<endl<<endl;
	printArray(b);
	cout<<"------"<<endl;
	solve(a,b);
	return 0;
}

void printArray(int a[2][2]){

for (int i=0;i<2;i++){
	for(int j=0;j<2;j++)
		cout<<a[i][j]<<" ";
	cout<<endl;	
	}
}

void solve(int a[2][2],int b[2][2]){
	
	int P = (a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	int Q = (a[1][0]+a[1][1])*b[0][0];
	int R = (b[0][1]-a[1][1])*a[0][0];
	int S = (b[1][0]-b[0][0])*a[1][1];
	int T = (a[0][0]+a[0][1])*b[1][1];
	int U = (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
	int V = (a[0][1]-a[1][1])*(b[1][0]-b[1][1]);
	
	int f[2][2];
	f[0][0] = P+S-T+V;
	f[0][1] = R+T;
	f[1][0] = Q+S;
	f[1][1] = P+R-Q+V;
	
	printArray(f);
}
