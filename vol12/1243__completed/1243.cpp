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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define MP make_pair
#define X first
#define Y second

char board[35][35];
int hum[35][35];
int ghost[35][35];
int row,col;

int dis[110][110];

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int cntleft,cntright;

void bfs(int r,int c,int node){

    pint start=MP(r,c),tmp;
    queue<pint> q;
    queue<int> move;

    bool vis[35][35]={false};

    q.push(start);
    vis[start.X][start.Y]=true;
    move.push(0);

    while( !q.empty() ){
        tmp=q.front();q.pop();
        int xx=move.front();move.pop();

        for (int i=0;i<4;++i){
            int rr=tmp.X+dr[i];
            int cc=tmp.Y+dc[i];

            if ( rr>=0 && rr<row && cc>=0 && cc<col && board[rr][cc] != '#' && !vis[rr][cc] ){
                if ( board[rr][cc]=='m' ){
                    dis[node][ hum[rr][cc] ]=(xx+1);
                    //printf("%d %d\n",rr,cc);
                }
                vis[rr][cc]=true;
                q.push( MP(rr,cc) );
                move.push(xx+1);
            }
        }
    }
}


// the maximum number of vertices + 1
#define SIZE 150

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

int mincost( int n, int s, int t, int &fcost )
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
    while( dijkstra( n, s, t )   )
    {
        // get the bottleneck capacity
        int bot = INT_MAX;
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            bot =min(bot, fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ) );

        // update the flow network
        for( int v = t, u = par[v]; v != s ; u = par[v = u] )
            if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
            else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }

        flow += bot;
    }
    return flow;
}



int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d %d",&row,&cntleft,&cntright);
        col=row;

        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }
        int tmp=1;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == 'm' ){
                    hum[i][j]=tmp++;
                }
            }
        }

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] >='A' && board[i][j]<='Z' ){
                    ghost[i][j]= board[i][j]-'A'+1;
                }
            }
        }

        memset(dis,63,sizeof(dis));

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] >='A' && board[i][j]<='Z' ){
                    bfs(i,j,ghost[i][j]);
                }
            }
        }
        /*
        for (int i=0;i<cntleft;++i){
            for (int j=0;j<cntright;++j){
                printf("%d\n",dis[i][j]);
            }
        }
        */

        int source=0,sink=cntleft+cntright+1;

        CLR(cap);
        CLR(cost);

        for (int i=1;i<=cntleft;++i){
            scanf("%d",&tmp);
            cap[source][i]= tmp;
            cost[source][i]= 0;
        }

        for (int i=1;i<=cntright;++i){
            cap[cntleft+i][sink]= 1;
            cost[cntleft+i][sink]= 0;
        }

        for (int i=1;i<=cntleft;++i){
            for (int j=1;j<=cntright;++j){
                cap[i][cntleft+j]= 1;
                cost[i][cntleft+j]= dis[i][j];
                //printf("%3d",dis[i][j]);
            }
            //printf("\n");
        }

        int cc;
        mincost(sink+1,source,sink,cc);
        printf("Case %d: %d\n",kk,cc);

    }


    return 0;
}
