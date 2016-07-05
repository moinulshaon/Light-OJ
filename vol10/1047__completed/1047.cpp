#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int cost[25][4];
int dp[25][4];
int n;

int func( int now,int prv ){

    if ( now==n+1 )return 0;
    if ( dp[now][prv]!= -1 )return dp[now][prv];
    int rr=INT_MAX;
    for (int i=1;i<=3;++i){
        if ( i!=prv )
            rr=min( rr, cost[now][i]+func( now+1,i ) );
    }
    return dp[now][prv]=rr;
}

int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);

        for (int i=1;i<=n;++i){
            scanf("%d %d %d",&cost[i][1],&cost[i][2],&cost[i][3]);
        }

        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",kk,func(1,0));
    }
    return 0;
}
