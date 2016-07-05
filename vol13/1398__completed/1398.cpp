#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }

#define SIZE 250

vector<int> out[SIZE];
int cap[SIZE][SIZE];

int q[SIZE],prv[SIZE];


bool bfs( int s,int t  ){
    // find an augmenting path
    memset( prv, -1, sizeof( prv ) );
    int qf = 0, qb = 0;
    prv[q[qb++] = s] = -2;
    while( qb > qf && prv[t] == -1 )
        for( int u = q[qf++], i = 0, v; i < out[u].size(); i++ )
            if( prv[v = out[u][i]] == -1 && cap[u][v] )
                prv[q[qb++] = v] = u;

    // see if we're done
    return  prv[t] != -1;
}

int dinic( int n, int s, int t ){

    for (int i=0;i<n;++i){
        out[i].clear();
    }
    FO( i,0,n ){
        FO(j,0,n){
            if ( cap[i][j] || cap[j][i] ){
                out[i].PB( j );
            }
        }
    }

    int flow = 0;
    while( bfs( s,t ) ){

        // try finding more paths
        for( int z = 0; z < n; z++ ) {
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

void add_edge(int x,int y){
    cap[x][y]++;
}

pint arr[SIZE];

LL sq(LL x){ return x*x; }

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int L,w,n,d;
        scanf("%d %d %d %d",&L,&w,&n,&d);
        if ( L+w+n+d == 0 )break;
        for (int i=1;i<=n;++i){
            scanf("%d %d",&arr[i].X,&arr[i].Y);
        }

        CLR(cap);

        int source = 0,sink = n+n+1;

        for (int i=1;i<=n;++i){
            if ( arr[i].Y <= d ){
                add_edge( source,i );
            }
            if ( arr[i].Y >= w-d ){
                add_edge( n+i,sink );
            }

            add_edge( i,n+i );

            for (int j=1;j<=n;++j){
                if ( i == j )continue;
                if ( sq( abs( arr[i].X-arr[j].X ) ) + sq( abs( arr[i].Y-arr[j].Y ) ) <= 4LL* d*d ){
                    add_edge( n+i,j );
                }
            }

        }

        printf("Case %d: %d\n",kk,dinic( sink+1,source,sink ));
    }


    return 0;
}
