#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

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


int dp[(1<<15)+3];
char cost[20][20];
int n;
int health[20];

int func( int state ){

    if ( state == (1<<n)-1 )return 0;

    if ( dp[state]!= -1 )return dp[state];

    int ss=(1<<29);

    for (int i=0;i<n;++i){
        if ( check( state,i ) == 0 ){
            for (int j=0;j<n;++j){
                if ( check( state,j ) == 1 && cost[j][i]!='0'){
                    ss=min( ss, int( ceil( double(health[i])/( cost[j][i]-'0' )- 1e-5 ) ) +func( set( state,i ) )    );
                    //printf("%d\n",( cost[j][i]-'0' ));
                }
            }
            ss=min( ss, health[i] + func( set( state,i ) )    );
        }
    }
    //printf("%d\n",ss);
    return dp[state]=ss;
}


int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&health[i]);
        }
        for (int i=0;i<n;++i){
            scanf("%s",cost[i]);
        }

        memset(dp,-1,sizeof(dp));
        int ans=(1<<29);

        for (int i=0;i<n;++i){
            //printf("%d\n",health[i] + func( set(0,i) ));
            ans=min( ans,health[i] + func( set(0,i) ) );
        }
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}
