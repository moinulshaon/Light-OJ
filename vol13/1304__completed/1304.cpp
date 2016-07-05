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

#define MAX 100000
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int n, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    memset(match,0,sizeof(match));
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

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

        int tmp = 1;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( str[i][j] == 'W' && ( j-1>=0 && str[i][j-1] != 'W' ) )tmp++;
                num[i][j].X = tmp;
            }
            tmp++;
        }
        n = tmp;
        tmp=1;
        for (int j=0;j<col;++j){
            for (int i=0;i<row;++i){
                if ( str[i][j] == 'W' && ( i-1>=0 && str[i-1][j] != 'W' ) )tmp++;
                num[i][j].Y = tmp;
            }
            tmp++;
        }



        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( str[i][j] == '.' ){
                    G[ num[i][j].X ].PB( n+ num[i][j].Y );
                }
            }
        }

        printf("Case %d: %d\n",kk,hopcroft_karp());
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( match[ num[i][j].X ] == n + num[i][j].Y ){
                    str[i][j] = 'T';
                }
            }
            printf("%s\n",str[i]);
        }

        for (int i=0;i<=n+tmp;++i){
            G[i].clear();
        }
    }


    return 0;
}
