#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define sz 31000

int total;
vector<int> outarrow[sz];
vector<int> cost[sz];

int dis1[sz],dis2[sz],dis3[sz];


bool vis[sz];

void DFS(int n,int s){

    vis[n]=true;
    dis1[n]=s;
    for (int i=0;i<outarrow[n].size();++i){
        if (!vis[ outarrow[n][i] ]){
            DFS( outarrow[n][i],s+cost[n][i] );
        }
    }
}

void DFS2(int n,int s){

    vis[n]=true;
    dis2[n]=s;
    for (int i=0;i<outarrow[n].size();++i){
        if (!vis[ outarrow[n][i] ]){
            DFS2( outarrow[n][i],s+cost[n][i] );
        }
    }
}

void DFS3(int n,int s){

    vis[n]=true;
    dis3[n]=s;
    for (int i=0;i<outarrow[n].size();++i){
        if (!vis[ outarrow[n][i] ]){
            DFS3( outarrow[n][i],s+cost[n][i] );
        }
    }
}

int main(){

    freopen("in.txt","r",stdin);

    int kase,a,b,c;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&total);

        for (int i=0;i<total;++i){
            outarrow[i].clear();
            cost[i].clear();
            dis1[i]= dis2[i]= -1;
        }
        //for (int i=0;i<total;++i)vis[i]=false;


        for (int i=1;i<total;++i){

            scanf("%d %d %d",&a,&b,&c);
            outarrow[a].push_back( b );
            cost[a].push_back(c);


            outarrow[b].push_back( a );

            cost[b].push_back(c);

        }
        int leaf;
        for (int i=0;i<total;++i){
            if (outarrow[i].size()==1){
                leaf=i;
                //printf("%d\n",leaf);

                break;
            }
        }
        memset(vis,false,sizeof(vis));

        DFS(leaf,0);

        int mxDist=-1,mxNode=-1;

        for (int i=0;i<total;++i){
            if (dis1[i]>mxDist){
                mxDist=dis1[i];
                mxNode=i;
            }
        }

        memset(vis,false,sizeof(vis));
        DFS2(mxNode,0);

        mxDist=-1,mxNode=-1;
        for (int i=0;i<total;++i){
            if (dis2[i]>mxDist){
                mxDist=dis2[i];
                mxNode=i;
            }
        }

        memset(vis,false,sizeof(vis));
        DFS3(mxNode,0);




        printf("Case %d:\n",kk);

        for (int i=0;i<total;++i){
            //printf("%d %d %d\n",dis1[i],dis2[i],dis3[i]);
            printf("%d\n",max( max(dis1[i],dis2[i]),dis3[i] )  );
        }

    }
    return 0;

}
