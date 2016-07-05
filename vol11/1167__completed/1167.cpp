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

#define SIZE 250
#define IN(x) (2*(x))
#define OUT(x) (2*(x)+1)

vector<int> out[SIZE];
int cap[SIZE][SIZE];

int q[SIZE],prev[SIZE];


bool bfs( int s,int t  ){
    // find an augmenting path
    memset( prev, -1, sizeof( prev ) );
    int qf = 0, qb = 0;
    prev[q[qb++] = s] = -2;
    while( qb > qf && prev[t] == -1 )
        for( int u = q[qf++], i = 0, v; i < out[u].size(); i++ )
            if( prev[v = out[u][i]] == -1 && cap[u][v] )
                prev[q[qb++] = v] = u;

    // see if we're done
    return  prev[t] != -1;
}

int dinic( int n, int s, int t ){

    for (int i=0;i<n;++i){
        out[i].clear();
    }

    for (int i=0;i<n;++i){
        for (int j=i+1;j<=n;++j){
            if ( cap[i][j] || cap[j][i] ){
                out[i].PB( j );
                out[j].PB( i );
            }
        }
    }

    int flow = 0;
    while( bfs( s,t ) ){

        // try finding more paths
        for( int z = 0; z < n; z++ ) {
            if( cap[z][t] && prev[z] != -1 ){
                int bot = cap[z][t];
                for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] )
                    bot = (bot>cap[u][v])?cap[u][v]:bot;
                if( !bot ) continue;

                cap[z][t] -= bot;
                cap[t][z] += bot;


                for( int v = z, u = prev[v]; u >= 0; v = u, u = prev[v] ){
                    cap[u][v] -= bot;
                    cap[v][u] += bot;

                }
                flow += bot;
            }
        }
    }
    return flow;
}


struct ee{
    int u,v,w;
}edge[SIZE*SIZE];
int edgeCnt;

void build(int lim,int n){

    for (int i=0;i<OUT(n);++i){
        for (int j=0;j<OUT(n);++j){
            cap[i][j] = 0;
        }
    }

    for (int i=0;i<n;++i){
        cap[ IN(i) ][ OUT(i) ] = 1;
    }

    for (int i=0;i<edgeCnt;++i){
        if ( edge[i].w<= lim ){
            cap[ OUT( edge[i].u ) ][ IN( edge[i].v ) ] = 1;
        }
    }

}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d %d",&n,&edgeCnt);
        n+= 2;

        for (int i=0;i<edgeCnt;++i){
            scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
            if ( edge[i].v<edge[i].u ){
                swap( edge[i].u,edge[i].v );
            }
        }

        int per;
        scanf("%d",&per);


/*
        build( 100000,n );

        for (int i=0;i<2*n;++i){
            for (int j=0;j<2*n;++j){
                printf("%2d",cap[i][j]);
            }printf("\n");
        }
        cout<<dinic( OUT(n-1)+1,OUT(0),IN(n-1) )<<endl;
*/

        int low = 1,high= 100100;
        int ans = -1;
        while ( low<=high ){
            int mid = (low+high)/2;
            build( mid,n );

            if( dinic( OUT(n-1)+1,OUT(0),IN(n-1) )>=per ){
                ans = mid;
                high = mid-1;
            }else{
                low= mid+1;
            }
        }

        printf("Case %d: ",kk);
        if ( ans == -1 )printf("no solution\n");
        else printf("%d\n",ans);

    }


    return 0;
}
