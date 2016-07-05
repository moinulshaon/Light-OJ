#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

const int MAX=30100;

using namespace std;

int dist[MAX];
bool vis[MAX];
vector<int> outarrow[MAX],cost[MAX];

void dfs1(int x,int d){
    if ( vis[x] )return ;

    vis[x]=true;
    dist[x]=d;
    for (int i=0;i<outarrow[x].size();++i){
        dfs1(outarrow[x][i],d+cost[x][i]);
    }
}

void dfs2(int x,int d){
    if ( vis[x] )return ;

    vis[x]=true;
    dist[x]=d;
    for (int i=0;i<outarrow[x].size();++i){
        dfs1(outarrow[x][i],d+cost[x][i]);
    }
}

int main(){
    int kase,node,a,b,w;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&node);

        for (int i=0;i<node;++i){
            outarrow[i].clear();
            cost[i].clear();
        }

        for (int i=1;i<node;++i){
            scanf("%d %d %d",&a,&b,&w);
            outarrow[a].push_back(b);
            cost[a].push_back(w);

            outarrow[b].push_back(a);
            cost[b].push_back(w);
        }
        memset(vis,false,sizeof(vis));
        dfs1(0,0);
        int d= -1,leaf;
        for (int i=0;i<node;++i){
            if ( dist[i]>d ){
                d=dist[i];
                leaf=i;
            }
        }

        memset(vis,false,sizeof(vis));
        dfs2(leaf,0);

        for (int i=0;i<node;++i){
            if ( dist[i]>d ){
                d=dist[i];
            }
        }
        printf("Case %d: %d\n",kk,d);
    }
    return 0;
}
