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


#define SIZE 1005

vector<int> out[SIZE];
LL fact[SIZE];
LL inv[SIZE];
int in[SIZE];

LL mod=1000000007;

int subtree[SIZE];

LL func( int x ){

    LL ret = 1;
    subtree[x]++;
    for (int i=0;i<out[x].size();++i){
        int &y=out[x][i];
        ret = ( ret*func( y ) )%mod;
        subtree[x] += subtree[ y ];
    }

    ret = ( ret*fact[ subtree[x]-1 ] )%mod;
    for (int i=0;i<out[x].size();++i){
        int &y=out[x][i];
        ret = ( ret*inv[ subtree[y] ] )%mod;
    }
    return ret;
}

int main(){

    fact[0] = 1;
    for (int i=1;i<SIZE;++i){
        fact[i] = ( fact[i-1] *i )%mod;
    }

    for (int i=0;i<SIZE;++i){
        inv[i] = BigMod( fact[i],mod-2,mod );
    }


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            out[i].clear();
            in[i] = 0;
            subtree[i] = 0;
        }

        int u,v;
        for (int i=1;i<n;++i){
            scanf("%d %d",&u,&v);
            out[u].PB( v );
            in[v]++;
        }

        int start = 1;
        for (int i=1;i<=n;++i){
            if ( in[i] == 0 ){
                start = i;
                break;
            }
        }

        printf("Case %d: %lld\n",kk,func(start));


    }

    return 0;
}
