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


#define SIZE 18

int n;
int d[SIZE][SIZE];
int cost[1<<SIZE];

bool vis[1<<SIZE];
int dp[1<<SIZE];

int func( int state ){

    if ( state == 0 )return 0;

    int &ret = dp[state];
    if ( vis[state] )return ret;
    vis[state] = true;

    ret = cost[state];
    for (int nxt = state&(state-1);nxt>0;nxt=state&(nxt-1) ){
        ret = min( ret , cost[nxt] + func( state & (~nxt) ) );
    }
    return ret;
}



int main(){


    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                scanf("%d",&d[i][j]);
            }
        }

        for (int state=0;state<(1<<n);++state ){
            cost[state]=0;
            vector<int> h;
            for (int i=0;i<n;++i){
                if ( state & (1<<i) ){
                    h.PB( i );
                }
            }
            for (int i=0;i<h.size();++i){
                for (int j=0;j<h.size();++j){
                    cost[state] += d[ h[i] ][ h[j] ];
                }
            }
            vis[state] = false;
        }

        printf("Case %d: %d\n",kk,func( (1<<n)-1 ));


    }


    return 0;
}
