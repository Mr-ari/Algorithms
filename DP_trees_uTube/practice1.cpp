/*
PROBLEM-
One day Polycarp published a funny picture in a social network making a poll about the color of his handle. Many of his friends started reposting Polycarp's joke to their news feed. Some of them reposted the reposts and so on.

These events are given as a sequence of strings "name1 reposted name2", where name1 is the name of the person who reposted the joke, and name2 is the name of the person from whose news feed the joke was reposted. It is guaranteed that for each string "name1 reposted name2" user "name1" didn't have the joke in his feed yet, and "name2" already had it in his feed by the moment of repost. Polycarp was registered as "Polycarp" and initially the joke was only in his feed.

Polycarp measures the popularity of the joke as the length of the largest repost chain. Print the popularity of Polycarp's joke.
Input

The first line of the input contains integer n (1 ≤ n ≤ 200) — the number of reposts. Next follow the reposts in the order they were made. Each of them is written on a single line and looks as "name1 reposted name2". All the names in the input consist of lowercase or uppercase English letters and/or digits and have lengths from 2 to 24 characters, inclusive.

We know that the user names are case-insensitive, that is, two names that only differ in the letter case correspond to the same social network user.
Output

Print a single integer — the maximum length of a repost chain.
*/

/*

Author : Arijit Ghosh

*/

#include <bits/stdc++.h>
using namespace std;


#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp                std::map<string,int>
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
mp mp_;

string StringToUpper(string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}
int max(int a,int b) {return (a>b)?a:b;}

int dfs(int node){
    int mx = 0;
    for(int ch : g[node]){
        mx = max(mx,1+dfs(ch)); 
    }
    return mx;
} 


int main(){
	FastRead;
	int edges;
    cin>>edges;
    string a,b,c;
    fo(i,0,edges) {
        cin>>a>>b>>c;
        a = StringToUpper(a);
        c = StringToUpper(c);
        if(mp_.find(a) == mp_.end()) mp_[a] = mp_.size()+1;
        if(mp_.find(c) == mp_.end()) mp_[c] = mp_.size()+1;
        g[mp_[c]].pb(mp_[a]);
    }
    cout<<1+dfs(mp_["POLYCARP"]); 
	return 0; 
}


/*INPUTS--

6
Mike reposted Polycarp
Max reposted Polycarp
EveryOne reposted Polycarp
111 reposted Polycarp
VkCup reposted Polycarp
Codeforces reposted Polycarp


*/

/*
OUTPUT--
2
*/