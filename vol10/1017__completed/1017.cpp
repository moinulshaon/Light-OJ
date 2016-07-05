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
int n,w,k;
int item[110];
int dp[110][110];

int func( int totake ,int left){
    if ( totake==n ){
        return 0;
    }

    if ( dp[totake][left]!= -1 )return dp[totake][left];

    int x=func( totake+1,left );
    int y=0;
    if ( left ){
        int cnt=0;
        for (int i=totake;i<n && item[i]-item[totake]<=w;++i){
            ++cnt;
        }
        y=cnt+func( totake+cnt,left-1 );
    }
    return dp[totake][left]=max(x,y);
}

int main(){
    FRO
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d %d",&n,&w,&k);

        int tmp;
        for (int i=0;i<n;++i){
            scanf("%d %d",&tmp,&item[i]);
        }
        sort(item,item+n);

        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",kk,func(0,k));
    }


    return 0;
}
