#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int dp[110][110];

char line[110];

int func( int left ,int right){
    if ( left>right )return 0;

    if ( dp[left][right]!= -1 ) return dp[left][right];

    if ( line[left]==line[right] ){
        if ( left!=right )
            return dp[left][right]=1+func(left+1,right-1)+1;
        else
            return dp[left][right]=1;
    }else{
        int a=1+func(left,right-1)+1;
        int b=1+func(left+1,right)+1;
        if ( a<b ){
            return dp[left][right]=a;
        }else{
            return dp[left][right]=b;
        }
    }

}


int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        memset(dp,-1,sizeof(dp));
        scanf("%s",line);
        int len=strlen(line);
        printf("Case %d: %d\n",kk,func(0,len-1)-len );
    }
    return 0;

}
