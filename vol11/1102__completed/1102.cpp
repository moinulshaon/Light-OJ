#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 2000010

long long BigMod ( long long a, long long p, long long m ){
    long long res = 1;
    long long x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res % m;
}

LL fact[SIZE];
LL mod = 1000000007;

LL func( int n,int r ){
    return ( fact[n]* BigMod( (fact[r]*fact[n-r])%mod,mod-2,mod )  )%mod;
}

int main(){

    fact[0]=1;
    for (int i=1;i<SIZE;++i){
        fact[i] = ( fact[i-1] * i )%mod;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){


        int n,k;
        scanf("%d %d",&n,&k);

        printf("Case %d: %lld\n",kk,func( n+k-1,n ));

    }

    return 0;
}
