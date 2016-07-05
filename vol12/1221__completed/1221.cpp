#include <cstdio>
#include <vector>
#define INF 1000000000


using namespace std;

int totalnode,totaledge;
struct EDGES
{
    int start,finish,weight;
}edge[10000];

int d[220];


bool bellmanford(int source)
{
        for (int i = 1; i <= totalnode; ++i)
            d[i] = INF;

        d[source] = 0;

        for (int i = 0; i < totalnode - 1; ++i)
                for (int j = 0; j < totaledge; ++j)
                        if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;


        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
            {
                return true;
            }
        return false;


}

int busy[220];
int main()
{
    freopen("in.txt","r",stdin);
    int a,b,test,q;

    scanf("%d",&test);

    for (int kk=1;test--;++kk)
    {
        scanf("%d %d %d",&totalnode,&totaledge,&q);

        for (int i=0;i<totaledge;++i){
            scanf("%d %d %d %d",&edge[i].start,&edge[i].finish,&a,&b);
            edge[i].weight=b*q-a;
        }


        printf("Case %d: ",kk);
        if (bellmanford(0))
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
