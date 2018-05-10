#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> a,int n,int x){
    int mid,low=0,high=n-1;
    while(low<= high){
        mid = low+((high-low)/2);
        if(a[mid] == x) return mid+1;
        else if(a[mid]>x) high=mid-1;
        else low = mid+1; 
    }
    return -1;
}
int main(){
    vector<int> a;
    for(int i=1;i<=500000;i++) a.push_back(i);
    cout<<"The element present in the index "<<binary_search(a,a.size(),500)<<endl;
    return 0;
}