#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define SIZE 10100

vector<int> outarrow[SIZE];
bool isArtic[SIZE];
int level[SIZE];
int low[SIZE];
int childrenCnt[SIZE];


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

int main(){

    int kase,a,b,v,e;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&v,&e);
        for (int i=1;i<=v;++i){
            outarrow[i].clear();
        }

        while(e-- ){
            scanf("%d %d",&a,&b);
            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }


        memset( level,-1,sizeof(level));
        memset( childrenCnt,0,sizeof(childrenCnt));
        memset( isArtic,false,sizeof(isArtic) );

        level[1]=0;
        dfs(1);
        int cnt=0;
        for (int i=1;i<=v;++i){
            //printf("%d %d %d\n",i,level[i],low[i]);
            if ( isArtic[i] ){
                //printf("%d\n",childrenCnt[i]);
                ++cnt;
            }
        }
        printf("Case %d: %d\n",kk,cnt);

    }
    return 0;

}


