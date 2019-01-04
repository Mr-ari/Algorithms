#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define deb printf("Debug\n")

class SegmentTree{

private:
    vi st,A;
    int n;
    int left(int i){return i<<1;}
    int right(int i){return (i<<1)+1;}
    int mid(int p,int q){return (p+q)>>1;}


    //build() will make the segment tree from the inputed array
    void build(int node,int start,int end){
        if (start == end) st[node] = A[start];
        else{
            build(left(node),start,mid(start,end));
            build(right(node),mid(start,end)+1,end);
            st[node] = st[left(node)]+st[right(node)];
        }
    }
    //Time complexity for build is O(n)

    void update (int node , int start,int end,int idx,int val){
        if (start == end){
            A[start] += val;
            st[node] += val;
        }
        else {
            if (idx >= start && idx <= mid(start,end)) update(left(node),start,mid(start,end),idx,val);
            else update(right(node),mid(start,end)+1,end,idx,val);
            st[node] = st[left(node)]+st[(right(node))];
        }
    }
    int rsq(int node,int start,int end,int i,int j){
        if (i>end || j <start ) return 0;
        else if (i<=start && j>= end) return st[node];
        else {
            int p1 = rsq(left(node),start,mid(start,end),i,j);
            int p2 = rsq(right(node),mid(start,end)+1,end,i,j);
            return p1+p2;
        } 
    }
    //Time Complexity for rsq() is O(logn)
public:
    SegmentTree(const vi &_A){
        A = _A;
        n = int(A.size());
        st.assign(n<<1,0);
        build(1,0,n-1);
    }
    int rsq(int i,int j){return rsq(1,0,n-1,i,j);} //overloading
    void update(int idx,int val) {return update(1,0,n-1,idx,val);}     
};



int main(){
    int arr[]={1,3,5,7,9,11};
    vi A(arr,arr+6);
    SegmentTree st(A);
    //st.print();
    printf("RSQ(0,5) = %d\n",st.rsq(0,5));
    printf("RMQ(1,4) = %d\n",st.rsq(1,4));

}