#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

vector <int> edge[10100], cost[10100],censorededge[10100],censoredcost[10100];
int total;

struct node
{
    int val,city;
    int alreadyIn;
    bool operator < (const node & p)const{return val>p.val;}
};

bool vis[10100][15];
int limit;
void dijkstra(int s,int f)
{

    memset(vis,false,sizeof(vis));

    node place,temp,u;
    place.val=0;
    place.city=s;
    place.alreadyIn=0;



    priority_queue<node> q;

    q.push(place);


    while (!q.empty())
    {
        temp=q.top();q.pop();
        if (temp.city==f){
            printf("%d\n",temp.val);
            return ;
        };

        if (vis[temp.city][temp.alreadyIn])
            continue;
        vis[temp.city][temp.alreadyIn]=true;


        for (int i=0;i<edge[temp.city].size();++i)
        {
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            u.alreadyIn=temp.alreadyIn;
            q.push(u);
        }
        if (temp.alreadyIn != limit){
            for (int i=0;i<censorededge[temp.city].size();++i)
            {
                u.val=censoredcost[temp.city][i]+temp.val;
                u.city=censorededge[temp.city][i];
                u.alreadyIn=temp.alreadyIn+1;
                q.push(u);
            }
        }
    }
    printf("Impossible\n");

}


int main()
{
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);
    int temp,temp2,temp3,temp4,temp5;

    for (int m=1;kase--;++m)
    {
        scanf("%d %d %d %d",&total,&temp,&temp5,&limit);

        for (int i=0;i<total;++i){
            edge[i].clear();
            cost[i].clear();
            censorededge[i].clear();
            censoredcost[i].clear();
        }


        while (temp--)
        {
            scanf("%d %d %d",&temp2,&temp3,&temp4);
            edge[temp2].push_back(temp3);
            cost[temp2].push_back(temp4);

        }
        while (temp5--)
        {
            scanf("%d %d %d",&temp2,&temp3,&temp4);
            censorededge[temp2].push_back(temp3);
            censoredcost[temp2].push_back(temp4);

        }
        int s=0,f=total-1;

        printf("Case %d: ",m);
        dijkstra(s,f);
    }

    return 0;
}
