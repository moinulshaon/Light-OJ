#include <cstdio>
#include <cstring>

using namespace std;

#define sz 32

long long dp[sz][sz];

long long ncr(int n,int r){

    if (r==0 || n==r)return 1;

    if (dp[n][r]!=-1)return dp[n][r];

    return dp[n][r]=ncr( n-1,r-1 )+ncr( n-1,r );

}


int main(){

    int kase,n,k;
    scanf("%d",&kase);

    memset(dp,-1,sizeof(dp));


    for (int kk=1;kase--;++kk){

        scanf("%d %d",&n,&k);

        if (k>n){
            printf("Case %d: 0\n",kk);
            continue;
        }

        long long sum=1;

        for (int i=0;i<k;++i){
            sum*= n-i;
        }

        printf("Case %d: %lld\n",kk,sum*ncr(n,k));

    }
    return 0;

}
