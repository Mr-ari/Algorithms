/*

Author : Arijit Ghosh

*/

#include <bits/stdc++.h>
using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp                std::map<int,int>
#define      st                std::set<int>
#define      sz(v)             (int)(v.size())
#define      m_p(a,b)          make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      fo(i,a,n)        for(int i = (a); i < (n); ++i)
#define      all(v)            v.begin(), v.end()
#define      X                 first
#define      Y                 second
#define      FastRead          ios_base::sync_with_stdio(0);cin.tie(0)

typedef double db;
typedef long long ll;
typedef long double lf;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll mo = 1000000007;

const int inf=~0u>>1;
template<typename T>inline void admo(int&a,const T&b){a=(a+b>=mo?a+b-mo:a+b);}
template<typename T>inline void sumo(int&a,const T&b){a=(a-b<0?a-b+mo:a-b);}
template<typename T,typename S>inline bool upmx(T&a,const S&b){return a<b?a=b,1:0;}
template<typename T,typename S>inline bool upmn(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T>inline T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}

const int N = 100000;
vi g[N];
int arr[N];
int dp[N];
int max(int a,int b) {return (a>b)?a:b;}
void dfs(int child,int parent){
    dp[child] = arr[child];
    int mx = 0;
    for(int ch : g[child]){
        if(ch == parent) continue;
        dfs(ch,child);
        mx = max(mx,dp[ch]); 
    }
    dp[child] += mx;
} 

int main(){
	FastRead;
	int u,v,n;
    cin>>n; //no of nodes
    fo(i,0,n-1) {cin>>u>>v; g[u].pb(v);g[v].pb(u);}// input for edges
    fo(i,1,n+1) cin>>arr[i];

    dfs(1,0);
    cout<<dp[1]<<endl; 
	return 0; 
}