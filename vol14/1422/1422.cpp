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
#include <stack>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 105

int dp[SIZE][SIZE];
int arr[SIZE];

int func( int prv,int now ){

    if ( prv>now )return 0;
    else if ( prv==now )return 1 ;

    if ( dp[prv][now] != -1 )return dp[prv][now];

    int ans=now-prv+1;
    for (int i=prv ;i<=now;++i){
        if ( arr[prv] == arr[i] )
            ans=min( ans,
                    func( prv,i-1 ) + func( i+1 ,now ) /*- ( arr[i] == arr[i-1])*/ - ( ((i+1)<=now)?( ( arr[i] == arr[i+1]) ) :0 ) );
    }
    //printf("%d %d %d\n",prv,now,ans);
    return dp[prv][now]= ans;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    arr[0]= -1;

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
        }

        arr[n+1] = -2 ;

        NEG(dp);
        printf("Case %d: %d\n",kk,func( 1,n ));
    }


    return 0;
}
