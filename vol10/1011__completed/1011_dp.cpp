#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int d[20][20];
int n;

int dp[17][(1<<17)+20];

int func(int men,int state){

    if ( state== (1<<n)-1 )return 0;

    if ( dp[men][state]!=-1 )return dp[men][state];
    int sum=0;

    for (int i=0;i<n;++i){
        if ( check(state,i)==0 ){
            sum=max( sum, d[men][i]+func( men+1,set(state,i) ) );
        }
    }

    return dp[men][state]=sum;
}

int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                scanf("%d",&d[i][j]);
            }
        }

        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",kk,func(0,0));
    }
}
