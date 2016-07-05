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

#define SIZE 105

vector<int> out[SIZE];
int cap[SIZE][SIZE];

int q[SIZE],prv[SIZE];

bool bfs( int n, int s,int t  ){
    // find an augmenting path
    for (int i=0;i<n;++i){
        prv[i] = -1;
    }
    int qf = 0, qb = 0;
    prv[q[qb++] = s] = -2;
    while( qb > qf && prv[t] == -1 )
        for( int u = q[qf++], i = 0, v; i < out[u].size(); i++ )
            if( prv[v = out[u][i]] == -1 && cap[u][v] )
                prv[q[qb++] = v] = u;

    // see if we're done
    return  prv[t] != -1;
}

int dinic( int n, int s, int t,bool single=false ){

    for (int i=0;i<n;++i){
        out[i].clear();
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if ( cap[i][j] || cap[j][i] ){
                out[i].PB( j );
            }
        }
    }

    int flow = 0;
    while( bfs( n,s,t ) ){

        if ( single ){
            int v=t;
            int mnflow=(1<<29);
            while (prv[v]>=0){
                int u=prv[v];
                mnflow=min( mnflow,cap[u][v] );
                v=u;
            }
            mnflow = min( 1,mnflow );
            v=t;
            while (prv[v]>=0){
                int u=prv[v];
                cap[u][v] -= mnflow;
                cap[v][u] += mnflow;
                v=u;
            }
            return mnflow >0;
        }

        // try finding more paths
        for( int z = 0; z < n ; z++ ) {

            if( cap[z][t] && prv[z] != -1 ){
                int bot = cap[z][t];
                for( int v = z, u = prv[v]; u >= 0; v = u, u = prv[v] )
                    bot = (bot>cap[u][v])?cap[u][v]:bot;
                if( !bot ) continue;

                cap[z][t] -= bot;
                cap[t][z] += bot;

                for( int v = z, u = prv[v]; u >= 0; v = u, u = prv[v] ){
                    cap[u][v] -= bot;
                    cap[v][u] += bot;
                }
                flow += bot;
            }
        }
    }
    return flow;
}

int n,m;
int row[SIZE];
int col[SIZE];

int ans[SIZE][SIZE];

void build(){
    int source = 0;
    int sink = n+m+1;

    for (int i=0;i<=sink;++i){
        for (int j=0;j<=sink;++j){
            cap[i][j] = 0;
        }
    }

    for (int i=1;i<=n;++i){
        cap[source][ i ] = row[i];
        for (int j=1;j<=m;++j){
            if ( ans[i][j] == -1 ){
                cap[ i ][ n+j ] = 1;
            }
        }
    }

    for (int j=1;j<=m;++j){
        cap[ n+j ][ sink ] = col[j];
    }
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);
        int rowsum = 0;
        for (int i=1;i<=n;++i){
            scanf("%d",&row[i]);
            rowsum += row[i];
        }
        int colsum = 0;
        for (int i=1;i<=m;++i){
            scanf("%d",&col[i]);
            colsum += col[i];
        }

        printf("Case %d:",kk);

        if ( rowsum != colsum ){
            printf(" impossible\n");
            continue;
        }

        int source = 0;
        int sink = n+m+1;

        for (int i=0;i<=n;++i){
            for (int j=0;j<=m;++j){
                ans[i][j] = -1;
            }
        }

        build();

        if ( dinic( sink+1,source,sink ) != rowsum ){
            printf(" impossible\n");
            continue;
        }
        printf("\n");
/*
        for (int i=0;i<=sink;++i){
            for (int j=0;j<=sink;++j){
                printf("%3d",cap[i][j]);
            }printf("\n");
        }
*/
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if ( cap[i][n+j] ){

                    ans[i][j] = 0;
                    cap[source][i] = 0;
                    cap[i][source] = 0;
                    cap[n+j][i] = 0;
                    cap[i][n+j] = 0;
                    cap[n+j][sink]=0;
                    cap[sink][n+j]=0;

                }else{
                    ans[i][j] = 1;

                    cap[n+j][i]--;

                    cap[source][i]++;
                    cap[i][source]--;
                    cap[n+j][sink]++;
                    cap[sink][n+j]--;

                    if ( dinic( sink+1,source,sink,true ) >0 ){
                        ans[i][j] = 0;
                    }else{
                        cap[source][i]--;
                        cap[i][source]++;
                        cap[n+j][sink]--;
                        cap[sink][n+j]++;
                    }
                }
            }
        }

        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                printf("%d",ans[i][j]);
            }printf("\n");
        }

    }


    return 0;
}
