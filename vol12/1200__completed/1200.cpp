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

const int INF=(1<<29);

#define SIZE 105

int w[SIZE],p[SIZE],req[SIZE];
int n;
int dp[SIZE][10005];

int func( int totake,int remain ){

    if ( remain<0 )return -INF;
    if ( totake<0 )return 0;

    if ( dp[totake][remain]!= -1 )return dp[totake][remain];

    return dp[totake][remain]=max( func(totake-1,remain ) ,p[totake]+func(totake,remain-w[totake]) );
}


int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int sack;
        scanf("%d %d",&n,&sack);

        for (int i=0;i<n;++i){
            scanf("%d %d %d",&p[i],&req[i],&w[i]);
            sack-=req[i]*w[i];
        }

        for (int i=0;i<=n;++i){
            for (int j=0;j<=sack;++j){
                dp[i][j]= -1;
            }
        }

        int ans=func(n-1,sack);
        printf("Case %d: ",kk);
        if (ans<0){
            printf("Impossible\n");
        }else{
            printf("%d\n",ans);
        }

    }

    return 0;
}
