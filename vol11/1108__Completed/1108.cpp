#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 100000000


using namespace std;

int totalnode,totaledge;
struct EDGES
{
    int start,finish,weight;
}edge[2100];

vector<int>result;
int d[1100];
bool vis[1100];

void bellmanford()
{
        for (int i = 0; i < totalnode; ++i)
            d[i] = INF;

        //d[0] = 0;

        for (int i = 0; i < totalnode - 1; ++i)
                for (int j = 0; j < totaledge; ++j)
                        if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;

        //printf("%d\n",d[1]);

        memset(vis,false,sizeof(vis));
        for (int i = 0; i < totalnode - 1; ++i)
        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
            {
                vis[ edge[j].start ]=vis[ edge[j].finish ] =true;
                d[edge[j].finish]=d[edge[j].start]=-INF;
            }

        for (int i=0;i<totalnode;++i){
            if (vis [i])
                result.push_back(i);
        }
}


int main()
{
    freopen("in.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for (int kk=1;test--;++kk)
    {
        scanf("%d %d",&totalnode,&totaledge);



        for (int i=0;i<totaledge;++i)
        {
            scanf("%d %d %d",&edge[i].finish,&edge[i].start,&edge[i].weight);
        }
        result.clear();
        bellmanford();

        printf("Case %d:",kk);
        if (result.size()==0){
            printf(" impossible");
        }else{
            for (int i=0;i<result.size();++i){
                printf(" %d",result[i]);
            }
        }
        printf("\n");

    }

    return 0;
}
