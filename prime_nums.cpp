#include<bits/stdc++.h>
#include<bitset>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000000> bs;
vi primes;

//generates list of prime upto upperbound
void sieve(ll upper_bound){
    _sieve_size = upper_bound + 1;
    bs.set();
    bs[0]=0;bs[1]=0;
    for(ll i=2;i<=_sieve_size;i++) if(bs[i]){
        for(ll j=i*i;j<=_sieve_size;j+=i) bs[j]=0;
    primes.push_back((int)i);
    }
}

//check if the number is prime or not
bool isPrime(ll n){
    if(n<=_sieve_size) return bs[n];
    for(int i=0;i<(int)primes.size();i++) if(n % primes[i] == 0) return false;
    return true;
}

int main(){
    sieve(10000000);
    printf("%d\n",isPrime(2147483647));
    printf("%d\n",isPrime(136117223861LL));
}