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

LL mod = 100000007;

LL pos[1010][15010];
LL dp[1010][15010];
int k;

long long func(int has,int yet){
    if ( has==0 ){
        return yet==0;
    }else if ( yet<0 ){
        return 0;
    }

    LL &ret=pos[yet][has];

    if ( ret!= -1 )return ret;

    long long sum=0;
    for (int i=1;i<=k;++i){
        sum=sum+func(has-1,yet-i);
    }
    return ret=sum;
}


LL another( int left,int sum ){
    if ( left==0 ){
        return sum==0;
    }else if ( sum<0 ){
        return 0;
    }

    LL &ret= dp[left][sum];
    long long xxx=0;
    for (int i=1;i<=k;++i){
        xxx=xxx+i*another( left-1,sum-i );
    }
    return ret=xxx;
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n,s;
        scanf("%d %d %d",&n,&k,&s);

        NEG(dp);
        NEG(pos);

        printf("%lld\n",another(n,s));
    }


    return 0;
}
