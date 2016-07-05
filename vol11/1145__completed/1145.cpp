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

const LL mod=100000007;

LL dp[1010][15010];
LL sum[1010][15010];

int k;

LL ff2(int n,int s);
LL ff1(int n,int s);

LL ff1(int n,int s){

    if ( n<0 || s<0 )return 0;
    if ( s==0 ){
        if ( n==0 )return 1;
        else return 0;
    }

    if ( dp[n][s] != -1 )return dp[n][s] ;

    else return dp[n][s]=ff2(n-1,s);
}


LL ff2(int n,int s){

    if (  s<0 )return 0;
    if ( n<0 )return 0;



    if ( sum[n][s] != -1 )return sum[n][s] ;

    return sum[n][s]=( ff2(n,s-1)+ff1(n,s-1)-ff1(n,s-k-1) )%mod;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,s;
        scanf("%d %d %d",&n,&k,&s);

        NEG(dp);
        NEG(sum);

        for (int i=0;i<=n;++i){
            for (int j=0;j<=s;++j){
                ff1(i,j);
            }
        }

        LL ans=ff1(n,s);
        if ( ans<0 )ans=mod+ans;

        printf("%lld\n",ans);
    }


    return 0;
}

