/*finding the maximum path posible in the tree*/


#include <bits/stdc++.h>
using namespace std;
typedef    vector<int> vi;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
const int N=100000;
vi g[N];
int in[N];
int out[N];
int dp[N];
int max(int a,int b) {return (a>b)?a:b;}
void dfs1(int u,int p){
    in[u] = 0;
    for(int v:g[u]){
        if(v == u) continue;
        dfs1(v,u);
        in[u] = max(in[v]+1,in[u]);
    }
}

void dfs2(int u,int p){
    int mx1 = -1,mx2=-1;
    for(int v:g[u]){
        if(v == u) continue;
        if(in[v] >= mx1){mx2=mx1;mx1=in[v];}
        else if(in[v]>mx2) mx2 = in[v];
    }
    for(int v:g[u]){
        if(v == u) continue;
        int use = mx1;
        if(in[v] == use) use = mx2;

        out[v] = max(out[u]+1,2+use);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,u,v;
    
	cin >> n;
	fo(i, n-1){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	
	Fo(i, 1, n+1){
		dp[i] = max(in[i], out[i]);
		cout << dp[i] << " " ;
	}

}

/*
10
1 2
1 3
1 4
2 5
2 6
3 7
4 8
7 9
7 10
*/
//3 4 3 4 5 5 4 5 5 5 