#include<iostream>
#include<vector>
using namespace std;

long long int fibo(int n){
	if (n==1 || n==2) return 1;
	return fibo(n-1)+fibo(n-2); 
}

long long int fibo_memo(int n){
	static vector<long long int> memo;
	if (n == 1 || n == 2) return 1;
	
	if(n>=memo.size()) memo.resize(n+1);
	
	if (memo[n] == 0) memo[n] = fibo_memo(n-1)+fibo_memo(n-2);
	return memo[n];
}

long long int fibo_bottom_up(int n){
	
	vector <long long int> v(n+1);
	v[2]=v[1]=1;
	for (int i=3;i<=n;i++){
		v[i] = v[i-1]+v[i-2];
	}
	
 return v.back(); 
}
int main(void){
	cout <<fibo(40)<<endl;
	int n;
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	cout<<"Fibonacci by the memozier method: "<<fibo_memo(n)<<endl;
	cout<<"Fibonacci bottom up approach - "<<endl<<fibo_bottom_up(n);
	return 0;
}
