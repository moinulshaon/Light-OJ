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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

int coin[110],n;
int target;

int dp[101][10010];
int mod=100000007;

int func( int totake,int sum ){
    //printf("%d %d\n",totake,sum);
    if ( sum==target )return 1;
    else if ( sum>target )return 0;
    else if ( totake==n )return 0;

    if ( dp[totake][sum] != -1 )return dp[totake][sum];

    return dp[totake][sum] = ( func(totake,sum+coin[totake])+func( totake+1,sum ) )%mod;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&target);
        for (int i=0;i<n;++i){
            scanf("%d",&coin[i]);
        }

        NEG(dp);

        printf("Case %d: %d\n",kk,func(0,0));
    }

    return 0;
}
