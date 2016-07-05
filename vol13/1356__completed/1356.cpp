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

#define SIZE 40100

int arr[SIZE];
mint mp;
int n;

bool prime[501000];
vector<LL> pp;
bool vis[501000];
vector<int> fact[501000];

#define MAX 100101
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int m, match[MAX], dist[MAX];
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

void func( int x ){
    for (int i=0;i<fact[ arr[x] ].size();++i){
        if ( mp.find( arr[x]/fact[ arr[x] ][i] )!=mp.end() ){
            G[x+1].PB( n+mp[ arr[x]/fact[ arr[x] ][i] ]+1 );
            G[ mp[ arr[x]/fact[ arr[x] ][i] ]+1 ].PB( n+x+1 );
            //cout<<x<<' '<<mp[tmp]<<endl;
        }
    }
}

void div(int x){

    if ( vis[ arr[x] ] ){
        func( x );
        return ;
    }

    int tmp=arr[x];
    for (int i=0;pp[i]*pp[i]<=tmp;++i){

        if ( tmp%pp[i]==0 ){
            fact[ arr[x] ].PB( pp[i] );
            if ( mp.find( arr[x]/pp[i] )!=mp.end() ){
                G[x+1].PB( n+mp[ arr[x]/pp[i] ]+1 );
                G[ mp[ arr[x]/pp[i] ]+1 ].PB( n+x+1 );
                //cout<<x<<' '<<mp[tmp]<<endl;
            }
            while( tmp%pp[i]==0 ){
                tmp/=pp[i];
            }
        }

    }

    if ( tmp!=1 ){
        //cout<<x<<' '<<mp[tmp]<<endl;
        fact[ arr[x] ].PB( tmp );
        if ( mp.find( arr[x]/tmp )!=mp.end() ){
            G[x+1].PB( n+mp[ arr[x]/tmp ]+1 );
            G[ mp[ arr[x]/tmp ]+1 ].PB( n+x+1 );
        }
    }
    vis[ arr[x] ]=true;
}

int main(){


    prime[0]=prime[1]=true;
    for (int i=2;i<=710;++i){
        if ( !prime[i] ){
            for (int j=2*i;j<501000;j+=i){
                prime[j]=true;
            }
        }
    }
    for (int i=2;i<501000;++i){
        if ( !prime[i] ){
            pp.PB(i);
        }
    }

    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        mp.clear();
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            mp[ arr[i] ]=i;
        }

        for (int i=0;i<MAX;++i){
            G[i].clear();
        }

        for (int i=0;i<n;++i){
            div(i);
        }

        printf("Case %d: %d\n",kk, n-hopcroft_karp()/2 );
    }

    return 0;
}
