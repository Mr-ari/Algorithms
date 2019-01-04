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
        if (start == end) st[node] = start;
        else{
            build(left(node),start,mid(start,end));
            build(right(node),mid(start,end)+1,end);
            int p1 = st[left(node)],p2 = st[right(node)];
            st[node] = (A[p1] <= A[p2]) ? p1:p2;
        }
    }
    //Time complexity for build is O(n)
    void update (int node , int start,int end,int idx,int val){
        if (start == end){
            A[start] = val;
        }
        else {
            if (idx >= start && idx <= mid(start,end)) update(left(node),start,mid(start,end),idx,val);
            else update(right(node),mid(start,end)+1,end,idx,val);
            int p1 = st[left(node)],p2 = st[right(node)];
            st[node] = (A[p1] <= A[p2]) ? p1:p2;
        }
    }
    int rmq(int node,int start,int end,int i,int j){
        if (i>end || j <start ) return -1;
        else if (i<=start && j>= end) return st[node];
        else {
            int p1 = rmq(left(node),start,mid(start,end),i,j);
            int p2 = rmq(right(node),mid(start,end)+1,end,i,j);

            if (p1 == -1) return p2;
            if(p2 == -1) return p1;
            return (A[p1]<=A[p2]) ? p1:p2;
        } 
    }
public:
    SegmentTree(const vi &_A){
        A = _A;
        n = int(A.size());
        st.assign(n<<1,0);
        build(1,0,n-1);
    }
    int rmq(int i,int j){return rmq(1,0,n-1,i,j);} //overloading 
    void update(int idx,int val) {return update(1,0,n-1,idx,val);}       
};

int main(){
    int arr[]={18,17,13,19,15,11,20};
    vi A(arr,arr+7);
    SegmentTree st(A);
    //st.print();
    printf("RMQ(1,3) = %d\n",st.rmq(1,3));
    st.update(1,10);
    printf("after update \nRMQ(1,3) = %d\n",st.rmq(1,3));
    printf("RMQ(4,6) = %d\n",st.rmq(4,6));

}