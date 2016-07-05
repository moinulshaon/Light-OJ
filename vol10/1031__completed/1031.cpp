#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

#define SIZE 105

int dp[SIZE][SIZE];
bool vis[SIZE][SIZE];
int arr[SIZE];
int sum[SIZE];

int func(int left,int right){
    if ( vis[left][right] )return dp[left][right];
    if ( left==right ){

        vis[left][right]=true;
        return dp[left][right]=arr[left];
    }

    //printf("%d %d\n",left,right);
    //getchar();

    int rr= INT_MIN;
    for (int i=left+1;i<=right;++i){
        rr=max(  rr,sum[right]-sum[left-1]-func(i,right) );
    }

    for (int i=right-1;i>=left;--i){
        rr=max(  rr,sum[right]-sum[left-1]-func(left,i) );
    }
    rr=max(rr,sum[right]-sum[left-1]);
    vis[left][right]=true;
    return dp[left][right]=rr;
}


int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        scanf("%d",&n);
        sum[0]=0;
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            sum[i]=sum[i-1]+arr[i];
        }
        memset(vis,false,sizeof(vis));
        printf("Case %d: %d\n",kk, func(1,n)-sum[n]+func(1,n) );
        /*
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                printf("%d %d %d\n",i,j,dp[i][j]);
            }
        }
        */
    }
    return 0;
}
