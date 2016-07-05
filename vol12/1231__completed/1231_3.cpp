#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}
int n;
int coin[55],cnt[55];
int dp[1002][52];

const int mod=100000007;



int func( int sum,int now ){

    if ( sum==0 )return 1;
    else if ( sum<0 || now==n  )return 0;

    if ( dp[sum][now] != -1 )return dp[sum][now];
    int ss=0;

    for (int i=0;i<=cnt[now];++i){
        ss= ( ss+ func( sum-i*coin[now] , now+1 ) )%mod;
    }
    return dp[sum][now]=ss;
}

int main(){
    freopen("in.txt","r",stdin);
    int kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        n=fastIn<int>();
        int target=fastIn<int>();

        for (int i=0;i<n;++i){
            coin[i]=fastIn<int>();
        }
        for (int i=0;i<n;++i){
            cnt[i]=fastIn<int>();
        }

        memset(dp,-1,sizeof(dp));

        printf("Case %d: %d\n",kk,func(target,0));
    }
    return 0;
}
