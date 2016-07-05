#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define SIZE 100010

vector<int> outarrow[SIZE];
bool isArtic[SIZE];
int level[SIZE];
int low[SIZE];
int childrenCnt[SIZE];

set<int> sset;

void dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];

    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;
            childrenCnt[ x ]++;

            dfs( y );


            low[x]=min( low[x],low[y] );

            if ( level[x]!=0 && low[y]>=level[x] ){
                isArtic[x]=true;
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }

    }
    if ( level[x]==0 && childrenCnt[x]>1){
        isArtic[x]=true;
    }

}
typedef unsigned long long LL;

int v;
LL cnt;
bool vis[SIZE];

void DFS2(int u){
    vis[u] = true;
    cnt++;

    for(int i=0;i<outarrow[u].size();i++){
        long v = outarrow[u][i];
        if( isArtic[v] ){
            sset.insert( v );
            continue;
        }
        if( vis[v] ) continue;
        DFS2( v );
    }
}



int main(){
    freopen("in.txt","r",stdin);

    int a,b,e;
    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%d %d",&v,&e);
        while(e-- ){
            scanf("%d %d",&a,&b);
            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }




        memset( level,-1,sizeof(level));
        memset( childrenCnt,0,sizeof(childrenCnt));
        memset( isArtic,false,sizeof(isArtic) );
        memset(vis,false,sizeof(vis));


        for (int i=0;i<v;++i){
            //printf("%d %d %d\n",i,level[i],low[i]);
            if ( level[i]== -1 ){
                level[i]=0;
                dfs(i);
            }
        }

        int tunnel=0;
        LL way=1;
        for (int i=0;i<v;++i){
            if ( isArtic[i] || vis[i] )continue;
            cnt=0;

            sset.clear();
            DFS2(i);

            if( !sset.size() ){
                if( cnt==1 ){
                    tunnel++;
                }
                else{
                    tunnel += 2;
                    way *= (cnt*(cnt-1))/2;
                }
            }else if( sset.size()==1 ){
                tunnel++;
                way *= cnt;
            }

        }

        printf("Case %d: %d %llu\n",kk,tunnel,way);
        for (int i=0;i<v;++i){
            outarrow[i].clear();
        }
    }
    return 0;

}
