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

#define SIZE 5010

vector<int> out[SIZE];
vector<int> rev[SIZE];

int parent[SIZE];
bool active[SIZE];
bool vis[SIZE];

set<pint> rem;

void refresh(int x){
    for (int i=0;i<rev[x].size();++i){
        int &y = rev[x][i];
        if ( y != parent[x] && active[y] ){
            rem.insert( MP( y , x ) );
        }
    }
}

void dfs(int x,int p){

    cout<<x<<" "<<p<<endl;

    parent[x] = p;
    active[x] = true;
    vis[x] = true;

    refresh(x);

    for (int i=0;i<out[x].size();++i){
        int &y = out[x][i];
        if ( !vis[y] ){
            dfs( y,x );
        }else{
            if ( parent[y] != -1 && active[ parent[y] ] ){
                rem.insert( MP( parent[y],y ) );
                parent[y] = x;
                refresh(y);
            }
        }
    }

    active[x] = false;
}

vector<int> stk;
void topo(int x){
    vis[x] = true;
    for (int i=0;i<out[x].size();++i){
        int &y = out[x][i];
        if ( !vis[y] ){
            topo(y);
        }
    }
    stk.PB( x );
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int u,v,n,m;
        scanf("%d %d",&n,&m);
        for (int i=0;i<=n;++i){
            out[i].clear();
            rev[i].clear();
            parent[i] = -1;
            vis[i] = false;
            active[i] = false;
        }
        rem.clear();
        for (int i=0;i<m;++i){
            scanf("%d %d",&u,&v);
            out[u].PB( v );
            rev[v].PB( u );
        }

        stk.clear();
        for (int i=1;i<=n;++i){
            if ( !vis[i] ){
                topo(i);
            }
        }
        for (int i=1;i<=n;++i)vis[i] = false;

        for (int i=stk.size()-1;i>=0;--i){
            int x = stk[i];
            //cout<<x<<endl;
            if ( !vis[x] ){
                dfs(x,-1);
            }
        }


        printf("Case %d: %d\n",kk,m-rem.size());
        for (int i=1;i<=n;++i){
            sort( ALL(out[i]) );
            for (int j=0;j<out[i].size();++j){
                if ( rem.find( MP(i,out[i][j]) ) == rem.end() ){
                    printf("%d %d\n",i,out[i][j]);
                }
            }
        }

    }

    return 0;
}
