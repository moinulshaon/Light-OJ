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

vector<int> v;
int n,m;

int dp[12][12];

int func( int dig ,int prv){
    if ( dig==n )return 1;

    if ( dp[dig][prv] != -1 )return dp[dig][prv];

    int tmp=0;
    for (int i=0;i<m;++i){
        if ( abs( v[i]-prv )<=2 ){
            tmp+= func( dig+1,v[i] );
        }
    }
    return dp[dig][prv]=tmp;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&m,&n);

        int tmp;
        v.clear();
        for (int i=0;i<m;++i){
            scanf("%d",&tmp);
            v.PB(tmp);
        }
        memset( dp,-1,sizeof(dp) );
        int ans=0;
        for (int i=0;i<m;++i){
            ans+= func(1,v[i]);
        }

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
