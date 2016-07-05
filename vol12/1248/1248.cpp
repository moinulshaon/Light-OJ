#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define SIZE 100010

double dp[SIZE];

int main(){

    dp[1]=1;
    for (int i=2;i<SIZE;++i ){
        dp[i]= dp[i-1]+ 1.0/ i ;
    }

    int kase;
    scanf("%d",&kase);
    int n;
    for (int kk=1;kase--;++kk){

        scanf("%d",&n);
        printf("Case %d: %lf\n",kk,dp[n]*n);
    }
    return 0;
}
