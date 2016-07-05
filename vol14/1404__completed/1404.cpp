#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

// the maximum number of vertices + 1
#define NN 100

// adjacency matrix (fill this up)
int cap[NN][NN];

// cost per unit of flow matrix (fill this up)
int cost[NN][NN];

// flow network and adjacency list
int fnet[NN][NN], adj[NN][NN], deg[NN];

// Dijkstra's successor and depth
int par[NN], d[NN];        // par[source] = source;

// Labelling function
int pi[NN];

#define CLR(a, x) memset( a, x, sizeof( a ) )
#define Inf (INT_MAX/2)

// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( int n, int s, int t )
{
    for( int i = 0; i < n; i++ ) d[i] = Inf, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;

    while( 1 )
    {
        // find u with smallest d[u]
        int u = -1, bestD = Inf;
        for( int i = 0; i < n; i++ ) if( par[i] < 0 && d[i] < bestD )
            bestD = d[u = i];
        if( bestD == Inf ) break;

        // relax edge (u,i) or (i,u) for all i;
        par[u] = -par[u] - 1;
        for( int i = 0; i < deg[u]; i++ )
        {
            // try undoing edge v->u
            int v = adj[u][i];
            if( par[v] >= 0 ) continue;
            if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] )
                d[v] = Pot( u, v ) - cost[v][u], par[v] = -u-1;

            // try edge u->v
            if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v] )
                d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
        }
    }

    for( int i = 0; i < n; i++ ) if( pi[i] < Inf ) pi[i] += d[i];

    return par[t] >= 0;
}
#undef Pot

int mcmf3( int n, int s, int t, int &fcost ,int lim)
{
    // build the adjacency list
    CLR( deg, 0 );
    for( int i = 0; i < n; i++ )
    for( int j = 0; j < n; j++ )
        if( cap[i][j] || cap[j][i] ) adj[i][deg[i]++] = j;

    CLR( fnet, 0 );
    CLR( pi, 0 );
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

//----------------- EXAMPLE USAGE -----------------
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int vertex,kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk  ) {

        memset( cap, 0, sizeof( cap ) );

        int edge, a, b, c,cp,lim;
        int source,sink;

        scanf("%d %d %d",&vertex,&edge,&lim);

        // fill up cap with existing capacities.
        // if the edge u->v has capacity 6, set cap[u][v] = 6.
        // for each cap[u][v] > 0, set cost[u][v] to  the
        // cost per unit of flow along the edge i->v
        for (int i=0; i<edge; i++) {
            scanf("%d %d %d %d",&a,&b,&cp,&c);
            cost[a][b] = c;  cost[b][a] = c;
            cap[a][b] = cp;  cap[b][a] = cp;
        }

        int fcost;
        int flow = mcmf3( vertex+1, 1, vertex, fcost,lim  );
        printf("Case %d: ",kk);
        if ( flow>=lim ){
            printf("%d\n",fcost);
        }else{
            printf("impossible\n");
        }

    }
    return 0;
}
