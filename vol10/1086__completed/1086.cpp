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

#define SIZE 17

int d[SIZE][SIZE];
int dp[1<<SIZE];
int odd[SIZE];
int degree[SIZE];

int vertex,edge;
int cnt;

int func( int state ){
    if ( state == (1<<cnt)-1 )return 0;

    if ( dp[state]!=-1 )return dp[state];

    int sum=(1<<29);

    for (int i=0;i<cnt;++i){
        if ( check( state,i )==0 ){
            for (int j=0;j<cnt;++j){
                if ( i!=j &&  check(state,j)==0 ){
                    sum=min( sum , d[ odd[i] ][ odd[j] ]+func(  set( set(state,i),j ) ) );
                }
            }
        }
    }
    return dp[state]=sum;
}

int main(){

    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for(int kk=1;kase--;++kk){
        memset(dp,-1,sizeof(dp));
        memset(degree,0,sizeof(degree));

        scanf("%d %d",&vertex,&edge);

        for (int i=0;i<vertex;++i){
            for (int j=0;j<vertex;++j){
                d[i][j]=(1<<29);
            }
        }

        int a,b,w,ans=0;
        while( edge-- ){
            scanf("%d %d %d",&a,&b,&w);

            a--;
            b--;

            d[a][b]=min( d[a][b],w );
            d[b][a]=min( d[b][a],w );

            degree[a]++;
            degree[b]++;

            ans+=w;
        }
        for (int k=0;k<vertex;++k)
            for (int i=0;i<vertex;++i)
                for (int j=0;j<vertex;++j)
                    d[i][j]=min( d[i][k]+d[k][j],d[i][j] );

        cnt=0;
        for (int i=0;i<vertex;++i){
            if ( degree[i] & 1 ){
                odd[cnt++]=i;
            }
        }

        printf("Case %d: %d\n",kk,ans+func(0));
    }
    return 0;
}
