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

#define SIZE 1100

int dp[SIZE][SIZE];
int mod= 1000000007;

int func( int n,int k ){
    if ( k==1 )return 1;

    if (  dp[n][k] != -1 )return dp[n][k];

    int sum=0;
    for (int i=0;i<=n;++i){
        sum= ( sum+ func( n-i ,k-1) )%mod ;
    }
    return dp[n][k]=sum%mod;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    NEG(dp);

    for (int kk=1;kase--;++kk){
        int n,k;
        scanf("%d %d",&n,&k);

        printf("%d\n",func(n,k));
    }



    return 0;
}
