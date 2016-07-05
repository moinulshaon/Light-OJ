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
vector<int> reverseEdge[1100];

int d[1100];
bool vis[1100];

void bellmanford(int source)
{
        for (int i = 0; i < totalnode; ++i)
            d[i] = INF;

        //d[source] = 0;

        for (int i = 0; i < totalnode - 1; ++i)
                for (int j = 0; j < totaledge; ++j)
                        if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
                                d[edge[j].finish] = d[edge[j].start] + edge[j].weight;

        bool negcycle=false;
        vector<int>st;
        for (int j = 0; j < totaledge; ++j)
            if (d[edge[j].start] + edge[j].weight < d[edge[j].finish])
            {
                negcycle=true;
                st.push_back(edge[j].finish);
                st.push_back(edge[j].start);
            }

        memset(vis,0,sizeof(vis));
        for (int i=0;i<st.size();++i){

            if (vis[ st[i] ])continue;

            queue<int> q;
            q.push(st[i]);

            vis[st[i]]=true;

            while ( !q.empty() ){
                int tmp=q.front();q.pop();

                for (int j=0;j<reverseEdge[ tmp ].size();++j){

                    if (!vis[ reverseEdge[ tmp ][j] ]){
                        q.push(reverseEdge[ tmp ][j] );
                        vis[ reverseEdge[ tmp ][j] ]=true;
                    }

                }

            }

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

        for (int i=0;i<totalnode;++i){
            reverseEdge[i].clear();
        }

        for (int i=0;i<totaledge;++i)
        {
            scanf("%d %d %d",&edge[i].start,&edge[i].finish,&edge[i].weight);
            reverseEdge[ edge[i].finish ].push_back( edge[i].start );
        }

        bellmanford(0);

        vector<int>result;
        for (int i=0;i<totalnode;++i){
            if (vis[i])
                result.push_back(i);
        }
        sort(result.begin(),result.end());
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
