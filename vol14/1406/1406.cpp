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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 16

vector<int> out[SIZE];
int n;

int dp[ 1<<SIZE ];

bool pos[ 1<<SIZE ];

bool vis[SIZE][1<<SIZE];

void dfs(int x,int state){
    if ( vis[x][state] )return ;
    vis[x][state] = true;
    pos[ state ] = true;

    for (int i=0;i<out[x].size();++i){
        dfs( out[x][i] , state | ( 1<<out[x][i] ) );
    }
}

int func( int state ){

    if ( state == (1<<n)-1 )return 0;

    int &ret = dp[state];
    if ( ret != -1 )return ret;

    ret = 100;
    int tmp = (~state) & ( (1<<n)-1 );
    for (int nxt= tmp ;nxt>0;nxt = tmp&(nxt-1) ){
        if ( pos[nxt] ){
            ret = min( ret , 1 + func( state | nxt ) );
        }
    }
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int m;
        scanf("%d %d",&n,&m);

        for (int i=0;i<n;++i){
            out[i].clear();
        }

        int u,v;
        while ( m-- ){
            scanf("%d %d",&u,&v);
            u--,v--;
            out[u].PB( v );
        }




        NEG(dp);
        CLR(vis);
        CLR(pos);
        for (int i=0;i<n;++i){
            dfs( i,(1<<i) );
        }

        printf("Case %d: %d\n",kk,func( 0 ) );

    }


    return 0;
}
