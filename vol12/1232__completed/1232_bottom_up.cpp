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



int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&target);
        for (int i=1;i<=n;++i){
            scanf("%d",&coin[i]);
        }

        for (int j=0;j<=target;++j){
            dp[0][j]=0;
        }

        for (int i=0;i<=n;++i){
            dp[i][0]=1;
        }


        for (int i=1;i<=n;++i){
            for (int j=1;j<=target;++j){
                dp[i][j] = dp[i-1][j];
                if ( j- coin[i]>=0 )
                    dp[i][j] =  (dp[i][j]+ dp[i][ j- coin[i] ] )%mod;
            }
        }

        printf("Case %d: %d\n",kk,dp[n][target]);
    }

    return 0;
}
