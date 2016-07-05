#include <cstdio>
#include <cstring>
#include <algorithm>

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}

using namespace std;

int n;
int dp[1<<15+5];
int cost[15][15];


int func( int state ){

    if ( state==((1<<n)-1) )return 0;

    if ( dp[state]!= -1 )return dp[state];

    int sum=(1<<29);
    for (int i=0;i<n;++i){
        if ( check(state,i)==0 ){
            int j=i;
            int cc=0;
            for (int k=0;k<n;++k){
                if ( check(state,k)==1 ){
                    cc+=cost[j][k];
                }
            }
            sum=min( sum,cc+cost[j][i]+func(set(state,i)) );

        }
    }
    return dp[state]=sum;
}
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


int main(){
    freopen("in.txt","r",stdin);
    int kase;
    kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        n=fastIn<int>();

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                cost[i][j]=fastIn<int>();
            }
        }
        memset(dp,-1,sizeof(dp));

        printf("Case %d: %d\n",kk,func(0));
    }
}
