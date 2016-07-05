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

#define NIL 0
#define INF (1<<28)

struct HP {


    vector< vector <int> > G;
    int n,m;
    vector<int> match, dist;

    HP(int n,int m){
        G.resize(n+m+3);
        match.resize( n+m+3 );
        dist.resize( n+m+3 );
        this->n = n;
        this->m = m;

    }

    bool bfs() {
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++) {
            if(match[i]==NIL) {
                dist[i] = 0;
                Q.push(i);
            } else dist[i] = INF;
        }
        dist[NIL] = INF;
        while(!Q.empty()) {
            u = Q.front();
            Q.pop();
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
        for (int i=0;i<match.size();++i){
            match[i] = 0;
        }
        // match[] is assumed NIL for all vertex in G
        while(bfs())
            for(i=1; i<=n; i++)
                if(match[i]==NIL && dfs(i))
                    matching++;
        return matching;
    }
};

#define SIZE 105

vector<int> aout[SIZE],bout[SIZE];

char pos[SIZE][SIZE];

bool check(int u,int pa,int v,int pb){

    if ( pos[u][v] != -1 )return pos[u][v];

    int n= aout[u].size()-(u != 1);
    int m= bout[v].size()-(v != 1);
    HP now ( n,m );

    //cout<<u<<" "<<n<<" "<<v<<" "<<m<<endl;

    int cara=0,carb=0;
    for (int i=0;i<aout[u].size();++i){
        if ( aout[u][i]==pa ){
            cara=1;
            continue;
        }
        carb=0;
        for (int j=0;j<bout[v].size();++j){
            if ( bout[v][j]==pb ){
                carb=1;
                continue;
            }

            if ( check( aout[u][i],u,bout[v][j],v ) ){
                now.G[i+1-cara].PB( n+j+1-carb );
                //cout<<"in "<<i+1<<" "<<n+j+1<<endl;
            }
        }
    }
    if ( now.hopcroft_karp() == n ){
        //cout<<u<<" "<<v<<endl;
        return pos[u][v]=true;
    }else {
        return pos[u][v]=false;
    }
}



int main() {

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int a,b;
        scanf("%d",&b);

        for (int i=0;i<=b;++i){
            bout[i].clear();
        }

        int u,v;
        for (int i=1;i<b;++i) {
            scanf("%d %d",&u,&v);
            bout[u].PB( v );
            bout[v].PB( u );
        }

        scanf("%d",&a);

        for (int i=0;i<=a;++i){
            aout[i].clear();
        }

        for (int i=1;i<a;++i){
            scanf("%d %d",&u,&v);
            aout[u].PB( v );
            aout[v].PB( u );
        }

        NEG(pos);


        if ( b>a && check( 1,0,1,0 ) ){
            printf("Case %d: Yes\n",kk);
        }else{
            printf("Case %d: No\n",kk);
        }

    }


    return 0;
}
