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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


#define SIZE 20100

vector<int> out[SIZE];
mint cap[SIZE];

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

char board[105][105];
int row,col;

int shaon( int r,int c ){
    return r*col+c+1;
}

#define IN(x) ( 2*(x) )
#define OUT(x) ( 2*(x)+1 )

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&row,&col);
        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }


        int source=0,sink=OUT( shaon(row-1,col-1) ) + 1,x,y;

        for (int i=0;i<=sink;++i){
            cap[i].clear();
            out[i].clear();
        }

        int cnt=0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == '*' ){
                    cap[ source ][ IN( shaon( i,j ) ) ] =1;
                    out[ source ].PB( IN( shaon( i,j ) ) );
                    out[ IN( shaon( i,j ) ) ].PB( source );
                    cnt++;
                }

                cap[ IN( shaon( i,j ) ) ][ OUT( shaon( i,j ) ) ] =1;
                out[ IN( shaon( i,j ) )  ].PB( OUT( shaon( i,j ) ) );
                out[  OUT( shaon( i,j ) ) ].PB( IN( shaon( i,j ) ));

                for (int k=0;k<4;++k){
                    x=i+dr[k];
                    y=j+dc[k];
                    if ( x>=0 && x<row && y>=0 && y<col ){
                        cap[ OUT( shaon( i,j ) ) ][ IN( shaon( x,y ) ) ] =100;
                        out[ OUT( shaon( i,j ) ) ].PB( IN( shaon( x,y ) ) );
                        out[ IN( shaon( x,y ) )  ].PB( OUT( shaon( i,j ) ) );
                    }
                }
            }
        }

        for (int i=0;i<row;++i){
            cap[ OUT(shaon( i,0 )) ][ sink ]= 1;
            out[ OUT(shaon( i,0 )) ].PB( sink );

            cap[ OUT(shaon( i,col-1 )) ][ sink ]= 1;
            out[ OUT(shaon( i,col-1 )) ].PB( sink );
        }

        for (int i=0;i<col;++i){
            cap[ OUT(shaon( 0,i )) ][ sink ]= 1;
            out[ OUT(shaon( 0,i )) ].PB( sink );

            cap[ OUT(shaon( row-1,i )) ][ sink ]= 1;
            out[ OUT(shaon( row-1,i )) ].PB( sink );
        }


        printf("Case %d: ",kk);

        //cout<<source<<' '<<sink<<endl;

        //cout<<dinic( sink+1,source,sink )<<' '<<cnt<<endl;
        if ( dinic( sink+1,source,sink )>=cnt ){
            printf("yes\n");
        }else{
            printf("no\n");
        }

    }


    return 0;
}
