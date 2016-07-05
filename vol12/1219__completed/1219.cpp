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

#define SIZE 10100

vector<int> out[SIZE];
vector<int> stk;
bool vis[SIZE];

int n;
int have[SIZE];
int parent[SIZE];

void dfs( int x ){

    vis[x]=true;
    int y;
    for (int i=0;i<out[x].size();++i){
        y= out[x][i];
        if ( !vis[y] ){
            dfs( y );
        }
    }
    stk.PB( x );

}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);
        int v,x,tmp;

        for (int i=1;i<=n;++i){
            out[i].clear();
        }

        for (int i=1;i<=n;++i){
            scanf("%d %d %d",&v,&x,&tmp);
            have[v]= x;
            while ( tmp-- ){
                scanf("%d",&x);
                out[v].PB( x );
                parent[x]= v;
            }
            vis[i]=false;
        }

        stk.clear();
        for (int i=1;i<=n;++i){
            if ( !vis[i] ){
                dfs(i);
            }
        }

        int ans = 0;
        for (int i=0;i<stk.size();++i){
            if ( have[ stk[i] ] < 1 ){
                ans += -( have[ stk[i] ]-1 );
                have[ parent[ stk[i] ] ] -= -( have[ stk[i] ]-1 );
            }else if ( have[ stk[i] ] > 1 ){
                ans += ( have[ stk[i] ]-1 );
                have[ parent[ stk[i] ] ] += ( have[ stk[i] ]-1 );
            }
        }
        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
