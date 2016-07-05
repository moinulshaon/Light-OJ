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

#define SIZE 210

int node;
int parent[SIZE];
int size[SIZE];

int edge[SIZE][SIZE];
vector<int> out[SIZE];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}

void makeUnion(int p,int q){
    if (size[p]>size[q])swap(p,q);
    size[q]+=size[p];
    parent [p] = q;
}

void prep(){

    for (int i=0;i<=node;++i){
        parent[i]=i;
        size[i]=1;
    }
    for (int i=0;i<=node;++i)
        for (int j=0;j<=node;++j)
            edge[i][j] = 0;
    for (int i=0;i<=node;++i)
        out[i].clear();
}

bool isconnected(){
    int cnt=0;
    for (int i=1;i<=node;++i){
        if ( parentOf(i) == i){
            cnt++;
            if ( cnt>1 )return false;
        }
    }
    return true;
}

int start,end,weight;
bool vis[SIZE];

void dfs( int u,int v,int mxs,int mxe ,int mxw ){
    if ( vis[u] )return ;
    if ( u == v ){
        start=mxs;
        end=mxe;
        weight=mxw;
        return ;
    }
    vis[u]=true;
    for (int i=0;i<out[u].size() ;++i){
        if ( edge[u][ out[u][i] ] && !vis[ out[u][i] ] ){
            if( edge[u][ out[u][i] ]>mxw ){
                dfs( out[u][i],v,u,out[u][i],edge[u][ out[u][i] ] );
            }else{
                dfs( out[u][i],v,mxs,mxe,mxw );
            }
        }
    }

}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        printf("Case %d:\n",kk);
        int day;
        scanf("%d %d",&node,&day);

        prep();
        int u,v,w,p,q,ans=0;
        bool was=false;
        while( day-- ){
            scanf("%d %d %d",&u,&v,&w);
            p=parentOf(u) ;
            q=parentOf(v) ;
            if ( p !=q  ){
                makeUnion( p,q );
                edge[u][v] = edge[v][u] = w;
                out[u].PB(v);
                out[v].PB(u);
                ans+= w;
            }else{
                CLR(vis);
                dfs( u, v , u,v,w );
                if ( weight!=w ){
                    ans+= w;
                    ans-= weight;
                    //printf("adding %d %d %d deleting %d %d %d\n",u,v,w,start,end,weight);
                    edge[start][end] = edge[end][start] = 0 ;
                    edge[u][v] = edge[v][u] = w;

                    out[u].PB(v);
                    out[v].PB(u);
                }

            }
            if( was || isconnected() ){
                printf("%d\n",ans);
                was=true;
            }else{
                printf("-1\n");
            }
        }
    }


    return 0;
}
