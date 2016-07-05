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




int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int sack;
        scanf("%d %d",&n,&sack);

        for (int i=1;i<=n;++i){
            scanf("%d %d %d",&p[i],&req[i],&w[i]);
        }

        for (int i=0;i<=n;++i){
            dp[i][0]=0;
        }
        for (int i=0;i<=sack;++i){
            dp[0][i]=0;
        }

        int tmp;
        for (int i=1;i<=n;++i){
            for (int j=0;j<=sack;++j){
                dp[i][j]= -INF;
                for (int k=req[i],mm=0;j-k*w[i]>=0 && dp[i-1][ j-k*w[i] ] >=0 ;++k,++mm){
                    dp[i][j]=max( dp[i][j],p[i]*mm+dp[i-1][ j-k*w[i] ] );
                    //printf("shaon\n");
                }
            }
        }

        if (dp[n][sack]<0){
            printf("Impossible\n");
        }else{
            printf("%d\n",dp[n][sack]);
        }

    }

    return 0;
}
