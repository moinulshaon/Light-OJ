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

typedef pair<int,int> pint;
typedef map<int,int> mint;

LL mod = 1000000007;

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


int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        LL c;
        scanf("%d %lld",&n,&c);

        LL sum = 0;
        for (int i=0;i<n;++i){
            sum=( sum + BigMod( c,__gcd(i,n),mod ) )%mod;
        }

        printf("Case %d: %lld\n",kk,( sum * BigMod( n,mod-2,mod ) )%mod );
    }


    return 0;
}
