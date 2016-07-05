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

// the maximum number of vertices + 1
#define SIZE 100

// adjacency matrix (fill this up)
int cap[SIZE][SIZE];

// cost per unit of flow matrix (fill this up)
int cost[SIZE][SIZE];

// flow network and adjacency list
int fnet[SIZE][SIZE];
vector<int> out[SIZE];

// Dijkstra's successor and depth
int par[SIZE], d[SIZE];        // par[source] = source;

// Labelling function
int pi[SIZE];


const int INF= (INT_MAX/2);

// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( int n, int s, int t ){
    for( int i = 0; i < n; i++ ){
        d[i] = INF, par[i] = -1;
    }
    d[s] = 0;
    par[s] = -n - 1;

    while( 1 )
    {
        // find u with smallest d[u]
        int u = -1, bestD = INF;
        for( int i = 0; i < n; i++ ) if( par[i] < 0 && d[i] < bestD )
            bestD = d[u = i];
        if( bestD == INF ) break;

        // relax edge (u,i) or (i,u) for all i;
        par[u] = -par[u] - 1;
        for( int i = 0; i < out[u].size(); i++ )
        {
            // try undoing edge v->u
            int v = out[u][i];
            if( par[v] >= 0 ) continue;
            if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] )
                d[v] = Pot( u, v ) - cost[v][u], par[v] = -u-1;

            // try edge u->v
            if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v] )
                d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
        }
    }

    for( int i = 0; i < n; i++ ) if( pi[i] < INF ) pi[i] += d[i];

    return par[t] >= 0;
}
#undef Pot

int mincost( int n, int s, int t, int &fcost ,int lim)
{
    //clear the vector
    for (int i=0;i<n;++i){
        out[i].clear();
    }

    // build the adjacency list
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            if( cap[i][j] || cap[j][i] ) out[i].PB(j);


    memset(fnet,0,sizeof(fnet));
    memset(pi,0,sizeof(pi));
    int flow = fcost = 0;

    // repeatedly, find a cheapest path from s to t
    while( dijkstra( n, s, t ) && lim>0  )
    {
        // get the bottleneck capacity
        int bot = INT_MAX;
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            bot =min(bot, fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ) );

        // update the flow network
        for( int v = t, u = par[v]; v != s ; u = par[v = u] )
            if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= min(lim,bot) * cost[v][u]; }
            else { fnet[u][v] += bot; fcost += min(lim,bot) * cost[u][v]; }

        lim-=bot;
        flow += bot;
    }
    return flow;
}

const int maxBufSize = (2000000);

struct Input
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	void grabBuffer() {
		bufSize = (maxBufSize); bufPos = 0;
		bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
		buffer[bufEnd] = '\0';
	}
	bool bufEof() {return bufPos == bufEnd;}
	int getChar() {return buffer[bufPos++];}
	void skipWS() {
		while ((buffer[bufPos] == '\n' ||
			buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
			bufPos++;
	}
	int rInt() {
		int n = 0, x; skipWS();
		bool neg=false;
		if (  ( x = getChar() )=='-'  ){
            neg=true;
            x=getChar();
		}

		for (; x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
        if ( neg )return -n;
        else return n;
	}
	inline bool isWhiteSpace(char x) {
		return x == ' ' || x == '\n' || x == '\t';
	}
	char rChar() {skipWS(); return getChar();}
}input;

int main(){

    freopen("in.txt","r",stdin);
    input.grabBuffer();
    int vertex,kase;
    kase=input.rInt();
    for (int kk=1;kase--;++kk  ) {

        memset( cap, 0, sizeof( cap ) );

        int edge, a, b, c,cp,lim;
        int source,sink;

        vertex=input.rInt();
        edge=input.rInt();
        lim=input.rInt();

        // fill up cap with existing capacities.
        // if the edge u->v has capacity 6, set cap[u][v] = 6.
        // for each cap[u][v] > 0, set cost[u][v] to  the
        // cost per unit of flow along the edge i->v
        for (int i=0; i<edge; i++) {
            a=input.rInt();
            b=input.rInt();
            cp=input.rInt();
            c=input.rInt();
            cost[a][b] = c;  cost[b][a] = c;
            cap[a][b] = cp;  cap[b][a] = cp;
        }

        int fcost;
        int flow = mincost( vertex+1, 1, vertex, fcost,lim  );
        printf("Case %d: ",kk);
        if ( flow>=lim ){
            printf("%d\n",fcost);
        }else{
            printf("impossible\n");
        }

    }


    return 0;
}
