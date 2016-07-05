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


set<LL> have;


void calc(int x){

    char str[15];
    for (int state=0;state<(1<<x);++state){
        for (int i=0;i<x;++i){
            if ( state & (1<<i) ){
                str[i] = '4';
            }else{
                str[i] = '7';
            }
        }
        str[x+1] = '\0';
        LL tmp ;
        sscanf(str,"%lld",&tmp);
        have.insert( tmp );
    }

}

int n;
vector<LL> lucky;

void dfs( LL x,int lim ){
    if ( x != 1 )lucky.PB( x );

    for (int i=lim;i<n;++i){
        LL tmp = x * lucky[i];
        if ( tmp <0 || tmp >1e12 )break;
        dfs( tmp,i );
    }

}

int main(){


    for (int i=1;i<13;++i){
        calc(i);
    }

    snuke( have,itr ){
        lucky.PB( *itr );
    }

    n= lucky.size();

    dfs( 1 , 0 );
    sort( lucky.begin(),lucky.end() );
    lucky.resize( unique( lucky.begin(),lucky.end() )-lucky.begin() );

    int kase;
    scanf("%d",&kase);
    LL a,b;
    for (int kk=1;kase--;++kk){
        scanf("%lld %lld",&a,&b);

        int ans = upper_bound( lucky.begin(),lucky.end(),b )-lower_bound( lucky.begin(),lucky.end(),a );
        printf("Case %d: %d\n",kk,ans);
    }

    return 0;
}
