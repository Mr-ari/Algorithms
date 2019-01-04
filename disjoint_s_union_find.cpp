#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind{
    private:
        vi p,rank;
    public:
        UnionFind(int N){
            rank.assign(N,1);
            p.assign(N,0);
            for(int i=0;i<N;i++) p[i] = i;
        }

        int find_root(int i){
            return (p[i] == i) ? i:p[i]=find_root(p[i]);
        }

        bool find(int a,int b) {return find_root(a) == find_root(b);}

        void union_set( int a, int b){
            if(find(a,b)) return;
            int root_a = find_root(a);
            int root_b = find_root(b);

            if (rank[root_a] > rank[root_b]) {p[root_b] = root_a;}
            else {
                p[root_a] = root_b;
                if (rank[root_a] == rank[root_b]) rank[root_b]++;
            }
        }
};


int main(){

    int n=5;
    UnionFind uf(n);
    uf.union_set(0,1);
    uf.union_set(2,3);
    uf.union_set(4,3);
    cout<<uf.find(0,4)<<" ";
    cout<<uf.find(0,1)<<endl;
    uf.union_set(0,3);
    cout<<uf.find(0,4)<<endl;
}