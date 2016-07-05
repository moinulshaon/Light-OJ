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

#define SIZE 1000100

LL mod = 1000000007;

LL fact[SIZE];

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

LL ncr(int n,int r){
    return ( fact[n] * BigMod( ( fact[r]*fact[n-r] )%mod,mod-2,mod ) )%mod;
}

LL dp[1010];

int main(){

    fact[0] = 1;
    for (int i=1;i<SIZE;++i){
        fact[i] = (fact[i-1]*i)%mod;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        vector<int> vec(n);
        for (int i=0;i<n;++i){
            scanf("%d",&vec[i]);
        }
        int sum = vec[0];
        dp[0] = 1;
        for (int i=1;i<n;++i){
            sum += vec[i];
            dp[i] = ( dp[i-1] * ncr(sum-1,vec[i]-1) )%mod;
        }
        printf("Case %d: %lld\n",kk,dp[n-1]);
    }


    return 0;
}
