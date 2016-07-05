#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>

using namespace std;

#define SIZE 10100

vector<int> outarrow[SIZE];
int level[SIZE];
int low[SIZE];

int color[SIZE];


set< pair<int,int> > removedEdge;

void dfs( int x ){

    low[x]=level[x];
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;


            dfs( y );

            low[x]=min( low[x],low[y] );

            if (  low[y]>level[x] ){
                removedEdge.insert( make_pair(x,y) );
                removedEdge.insert( make_pair(y,x) );
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }

    }

}

int checkBipartite(int x){

    queue<int> q;

    q.push(x);
    color[x]=0;
    bool bipartitePossible=true;
    int cnt=0;

    while ( !q.empty() ){
        int tmp=q.front();
        q.pop();
        cnt++;

        for (int i=0;i<outarrow[tmp].size();++i){
            if ( removedEdge.find( make_pair(tmp,outarrow[tmp][i]) )!=removedEdge.end() )continue;

            if ( color[ outarrow[tmp][i] ]== -1 ){
                color[ outarrow[tmp][i] ]=  !color[tmp];
                q.push( outarrow[tmp][i] );
            }
            else if ( color[ outarrow[tmp][i] ] ==  color[tmp]){
                bipartitePossible=false;
            }
        }
    }
    if (bipartitePossible){
        return 0;
    }else{
        return cnt;
    }
}
int main(){

    int kase,a,b,v,e;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&v,&e);
        for (int i=0;i<v;++i){
            outarrow[i].clear();
        }


        while(e-- ){
            scanf("%d %d",&a,&b);
            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }


        memset( level,-1,sizeof(level));
        removedEdge.clear();

        for (int i=0;i<v;++i){
            if ( level[i]== -1 ){
                level[i]=0;
                dfs(i);
            }
        }
        int cnt=0;
        memset( color,-1,sizeof(color));
        for (int i=0;i<v;++i){
            if ( color[i]== -1 ){
                cnt+=checkBipartite(i);
            }
        }
        printf("Case %d: %d\n",kk,cnt);

    }
    return 0;

}


