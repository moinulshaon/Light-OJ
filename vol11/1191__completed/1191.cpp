#include <cstdio>
#include <cstring>

using namespace std;

int n,k,s;
long long dp[51][51][51];

long long func(int has,int yet){
    if ( has==0 ){
        return yet==0;
    }else if ( yet<0 ){
        return 0;
    }

    if ( dp[yet][has][k]!= -1 )return dp[yet][has][k];

    long long sum=0;
    for (int i=1;i<=k;++i){
        sum=sum+func(has-1,yet-i);
    }
    return dp[yet][has][k]=sum;
}

int main(){

    int kase;
    scanf("%d",&kase);
    memset(dp,-1,sizeof(dp));
    for (int kk=1;kase--;++kk){
        scanf("%d %d %d",&s,&n,&k);
        printf("Case %d: %lld\n",kk,func(n,s));
    }
    return 0;
}
