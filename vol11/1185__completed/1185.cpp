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

#define SIZE 102

vector<int> out[SIZE];
int n,m;

bool vis[SIZE][2];

void bfs(){

    for (int i=1;i<=n;++i){
        vis[i][0] = vis[i][1] = 0;
    }

    queue<pint> q;
    q.push( MP(1,0) );

    while ( !q.empty() ){
        pint f = q.front();q.pop();
        for (int i=0;i<out[f.X].size();++i){
            int &y = out[f.X][i];
            if ( !vis[y][(f.Y+1)%2] ){
                vis[y][(f.Y+1)%2] = true;
                q.push( MP(y,(f.Y+1)%2) );
            }
        }
    }


}


int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);

        for (int i=1;i<=n;++i){
            out[i].clear();
        }

        int u,v;
        while ( m-- ){
            scanf("%d %d",&u,&v);
            out[u].PB( v );
            out[v].PB( u );
        }


        bfs();
        int ans = 0;
        for (int i=1;i<=n;++i){
            if ( vis[i][0] ){
                ans++;
            }
        }

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
