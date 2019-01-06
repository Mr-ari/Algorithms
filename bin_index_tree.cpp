#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class BinaryIndexTree{
    private:
    vi ft;
    int LSOne(int s){return s&(-s);}
    public:
    BinaryIndexTree(int size){ft.assign(size+1,0);}
    void update(int k,int v){
        for(;k<ft.size();k+=k&-k){ft[k]+=v;}
    }
    int query(int b){
        int sum = 0;
        for(;b>0;b-= b&-b){sum+=ft[b];}
        return sum;
    }

    int query(int a,int b){
        return query(b) - (a==1 ? 0:query(a-1));
    }
};

int main(){
    int f[] = {2,4,5,5,6,6,6,7,7,8,9};
    BinaryIndexTree bt(10);
    for(int i=0;i<11;i++) bt.update(f[i],1);
    printf("RSQ(1,10) = %d",bt.query(1,10));
}