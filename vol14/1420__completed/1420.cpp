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

#define MAX 2100
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


vector<int> out[MAX];

bool vis[MAX];

void pre(){
    for (int i=1;i<=n;++i){
        vis[i] = false;
    }
}

void shaon( int x ){
    vis[x]=true;
    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( !vis[y] ){
            shaon(y);
        }
    }
}

vector <int> outarrow [MAX];
vector <int> inarrow [MAX];
vector <int> stk;
int component [MAX];


void dfs1 (int x){
	vis [x] = true;
	for ( int u = 0; u < outarrow [x].size (); u++ )
		if ( !vis [ outarrow [x] [u]] )
            dfs1 (outarrow [x] [u]);
	stk.push_back (x);
}

void dfs2 (int x, int c){
	vis [x] = false;
	component [x] = c;
	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}


void ini(){
    for ( int i = 1; i <= n ; i++ ){
        outarrow [i].clear ();
        inarrow [i].clear ();
        vis[i]=false;
    }
    stk.clear ();
}

void addedge(int a,int b){
    outarrow [a].push_back (b);
    inarrow [b].push_back (a);
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int ee;
        scanf("%d %d",&n,&ee);

        for (int i=1;i<=n;++i){
            out[i].clear();
        }


        ini();
        int u,v;
        while ( ee-- ){
            scanf("%d %d",&u,&v);
            addedge(u,v);
        }

        for ( int i = 1; i <= n; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], ++c);

        for (int i=0;i<MAX;++i){
            G[i].clear();
        }

        for ( int i = 1; i <= n; i++ )
			for ( int j = 0; j < outarrow [i].size (); j++ )
				if ( component [i] != component [outarrow [i] [j]] )
					out[ component[i] ].PB( component[ outarrow [i] [j] ] );

        for (int i=1;i<=c;++i){
            pre();
            shaon(i);
            for (int j=1;j<=c;++j){
                if ( i!= j && vis[j] ){
                    G[i].PB( c+j );
                    //cout<<"shaon "<<i<<" "<<j<<endl;
                }
            }
        }
        printf("Case %d: %d\n",kk,c-hopcroft_karp());
    }


    return 0;
}
