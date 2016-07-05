#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

#define SIZE 10010

vector<int> outarrow[SIZE];
bool isArtic[SIZE];
int level[SIZE];
int low[SIZE];
int childrenCnt[SIZE];

int stk[SIZE];
int top;
set<int> bcc[SIZE];
int bccCnt;


void dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];
    stk[top++] = x;
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;
            childrenCnt[ x ]++;

            dfs( y );


            low[x]=min( low[x],low[y] );

            if (low[y] >= level[x]){
                int tmp;
                do{
                    tmp = stk[--top];
                    bcc[bccCnt].insert(tmp);
                } while (tmp != y);
                bcc[bccCnt].insert(x);
                bccCnt++;
            }

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


int superNodeCnt[SIZE];
int superNodeEdge[SIZE];
bool vis[SIZE];
int v;

void superDfs( int x ,int cc){

    vis[x]=true;
    //printf("%d\n",x);

    superNodeCnt[cc]++;
    if ( !isArtic[x] )
        superNodeEdge[cc]++;
    int y;
    for (int i=0;i<outarrow[x].size();++i){
        y=outarrow[x][i];

        if( bcc[cc].find(y)==bcc[cc].end() ){
            continue;
        }

        if ( !vis[y] )
            superDfs( y ,cc );
    }
}

typedef unsigned long long LL;


int main(){
    freopen("in.txt","r",stdin);

    int kase,a,b,e;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&v,&e);
        for (int i=0;i<v;++i){
            outarrow[i].clear();
            bcc[i].clear();
        }

        while(e-- ){
            scanf("%d %d",&a,&b);
            outarrow[a].push_back(b);
            outarrow[b].push_back(a);
        }




        memset( level,-1,sizeof(level));
        memset( childrenCnt,0,sizeof(childrenCnt));
        memset( isArtic,false,sizeof(isArtic) );

        bccCnt=0;
        top=0;

        for (int i=0;i<v;++i){
            //printf("%d %d %d\n",i,level[i],low[i]);
            if ( level[i]== -1 ){
                level[i]=0;
                dfs(i);
            }
        }




        memset( superNodeCnt,0,sizeof(superNodeCnt) );
        memset( superNodeEdge,0,sizeof(superNodeEdge) );
        //printf("%d\n",bccCnt);
        for (int i=0;i<bccCnt;++i){
            memset( vis,false,sizeof(vis) );
            int x;
            for (int j=0;j<v;++j){
                if( bcc[i].find(j)!=bcc[i].end() ){
                    x=j;
                    break;
                }
            }
            superDfs(x,i);
            superNodeEdge[i]=superNodeCnt[i]-superNodeEdge[i];
            //printf("%d %d\n",superNodeCnt[i],superNodeEdge[i]);
        }

        int tunnel=0;
        LL way=1;
        for (int i=0;i<bccCnt;++i){
            if ( superNodeEdge[i]==1 ){
                ++tunnel;
                if ( superNodeCnt[i] ){
                    way=way*LL( superNodeCnt[i]-1 );
                }
            }else if ( superNodeEdge[i]==0 ){
                if ( superNodeCnt[i]>1 ){
                    tunnel+=2;
                    way=way*LL( superNodeCnt[i])*LL(superNodeCnt[i]-1)/2;
                }else{
                    tunnel++;
                }
            }
            //printf("%d %d\n",superNodeCnt[i],superNodeEdge[i]);
        }

        printf("Case %d: %d %llu\n",kk,tunnel,way);

    }
    return 0;

}
