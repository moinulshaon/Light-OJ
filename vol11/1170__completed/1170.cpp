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


vector<LL> vec;
const LL lim = 1e10+1e7;

#define SIZE 2000100

LL fact[SIZE];
LL mod = 100000007;

LL calc(int n){
    if ( n==0 )return 0;
    else return ( fact[2*n]*BigMod( (fact[n]*fact[n+1])%mod,mod-2,mod ) )%mod;
}

int main(){

    for ( LL x=2;x*x<lim;++x  ){
        LL y = x*x;
        while ( y<lim ){
            vec.PB( y );
            y*= x;
        }
    }

    sort( vec.begin(),vec.end() );

    //cout<<vec.size()<<endl;

    vector<LL>::iterator it = unique( vec.begin(),vec.end() );
    vec.resize( it-vec.begin() );


    //cout<<vec.size()<<endl;


    fact[0]=1;
    for (int i=1;i<SIZE;++i){
        fact[i] = (fact[i-1]*LL(i) )%mod;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL a,b;
        scanf("%lld %lld",&a,&b);
        int n = upper_bound( vec.begin(),vec.end(),b )-
                   upper_bound( vec.begin(),vec.end(),a-1 );
        printf("Case %d: %lld\n",kk,calc(n));

    }

    return 0;
}
