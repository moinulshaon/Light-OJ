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


#define SIZE 100007

struct hopcroft_karp {

    int n1, n2;
    int matching[SIZE], dist[SIZE], Q[SIZE];
    bool used[SIZE], vis[SIZE];

    vector<int> out[SIZE];

    void ini(int _n1, int _n2) {
        n1 = _n1;
        n2 = _n2;
    }

    void addEdge(int u, int v) {
        out[u].PB( v );
    }

    void bfs() {
        fill(dist, dist + n1, -1);
        int sizeQ = 0;
        for (int u = 0; u < n1; ++u) {
            if (!used[u]) {
                Q[sizeQ++] = u;
                dist[u] = 0;
            }
        }
        for (int i = 0; i < sizeQ; i++) {
            int u1 = Q[i];
            for (int j=0;j<out[u1].size();++j){
                int u2 = matching[ out[u1][j] ];
                if (u2 >= 0 && dist[u2] < 0) {
                    dist[u2] = dist[u1] + 1;
                    Q[sizeQ++] = u2;
                }
            }
        }
    }

    bool dfs(int u1) {
        vis[u1] = true;
        for (int i=0;i<out[u1].size();++i) {
            int v = out[u1][i];
            int u2 = matching[v];
            if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
                matching[v] = u1;
                used[u1] = true;
                return true;
            }
        }
        return false;
    }

    int maxMatching() {
        fill(used, used + n1, false);
        fill(matching, matching + n2, -1);
        for (int res = 0;;) {
            bfs();
            fill(vis, vis + n1, false);
            int f = 0;
            for (int u = 0; u < n1; ++u)
                if (!used[u] && dfs(u))
                    ++f;
            if (!f)
                return res;
            res += f;
        }
    }
    void clear(){
        for (int i=0;i<n1+n2;++i){
            out[i].clear();
        }
    }

}hk;


char str[200][200];
pint num[200][200];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int row,col;
        scanf("%d %d",&row,&col);
        for (int i=0;i<row;++i){
            scanf("%s",str[i]);
        }

        int tmp = 0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( str[i][j] == 'W' && ( j-1>=0 && str[i][j-1] != 'W' ) )tmp++;
                num[i][j].X = tmp;
            }
            tmp++;
        }
        int n = tmp;
        tmp=0;
        for (int j=0;j<col;++j){
            for (int i=0;i<row;++i){
                if ( str[i][j] == 'W' && ( i-1>=0 && str[i-1][j] != 'W' ) )tmp++;
                num[i][j].Y = tmp;
            }
            tmp++;
        }
        int m = tmp;
        hk.ini( n,m );

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( str[i][j] == '.' ){
                    hk.addEdge( num[i][j].X , num[i][j].Y );
                }
            }
        }

        printf("Case %d: %d\n",kk,hk.maxMatching() );
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( hk.matching[ num[i][j].Y ] == num[i][j].X ){
                    str[i][j] = 'T';
                }
            }
            printf("%s\n",str[i]);
        }

        hk.clear();

    }


    return 0;
}
