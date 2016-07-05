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

#define MAX 1011
#define NIL 0
#define INF (1<<28)

vector <int> G[MAX];
int n,m, match[MAX], dist[MAX];
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
int le,ri,v;


int func( const string &x ){

    int cnt;

    string tmp =x.substr( 1,x.length()-1 );
    sscanf(tmp.c_str(),"%d",&cnt);

    //cout<<tmp<<endl;
    if ( x[0] == 'M' ){
        return cnt;
    }else{
        return cnt+le;
    }
}

vector<pint> male,female;

int main(){

    FRO

    ios_base::sync_with_stdio(false);

    int kase;
    cin>>kase;

    for (int kk=1;kase--;++kk){

        cin>>le>>ri>>v;

        for (int i=0;i<=v;++i){
            G[i].clear();
        }

        string x,y;

        male.clear();female.clear();

        for (int i=0 ; i<v ; ++i ){
            cin>>x>>y;
            if ( x[0]=='M' ){
                male.PB( make_pair( func(x),func(y) ) );
            }else{
                female.PB( make_pair( func(x),func(y) ) );
            }
        }

        n = male.size();
        m = female.size();

        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if ( male[i].first == female[j].second || male[i].second == female[j].first ){
                    G[ i+1 ].PB( n+j+1 );

                    //cout<<i<<' '<<j<<endl;
                }
            }
        }

        cout<<"Case "<<kk<<": "<<v-hopcroft_karp()<<'\n';
    }



    return 0;
}
