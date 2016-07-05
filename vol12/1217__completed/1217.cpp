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

#define SIZE 1005

int n;
int luv[SIZE];

int dp[SIZE][2][2];

int func( int totake,int prv ,int zerotaken){

    if ( totake==n ){
        if ( prv==zerotaken && prv==1 ){
            return -(1<<29);
        }else{
            return 0;
        }
    }
    if ( dp[totake][prv][zerotaken]!= -1 )return dp[totake][prv][zerotaken];

    if ( prv ){
        return dp[totake][prv][zerotaken]=func( totake+1,0,zerotaken );
    }else{
        return dp[totake][prv][zerotaken]=max( func( totake+1,0,zerotaken ),
                                   luv[totake]+func( totake+1,1,zerotaken ) );
    }
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d",&luv[i]);
        }

        memset(dp,-1,sizeof(dp));

        printf("Case %d: %d\n",kk,max(luv[0]+func(1,1,1),func(1,0,0) ) );
    }


    return 0;
}
