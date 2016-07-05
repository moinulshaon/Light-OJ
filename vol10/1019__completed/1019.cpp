#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 100000000

vector <int> edge[110], cost[110];
int total;

struct node
{
    int val,city;

    bool operator < (const node & p)const{return val>p.val;}
};


int dijkstra(int s,int f)
{

    bool vis[110]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;




    priority_queue<node> q;

    q.push(place);


    while (!q.empty())
    {
        temp=q.top();q.pop();
        if (temp.city==f)break;

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;


        for (int i=0;i<edge[temp.city].size();++i)
        {
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            q.push(u);
        }
    }
    if (temp.city==f)
        return temp.val;
    else
        return INF;






}


int main()
{

    freopen("in.txt","r",stdin);

    int a,b,c,kase,e;
    scanf("%d",&kase);

    for (int m=1;kase--;++m)
    {
        scanf("%d %d",&total,&e);
        for (int i=1;i<=total;++i){
            edge[i].clear();
            cost[i].clear();
        }



        while (e--){
            scanf("%d %d %d",&a,&b,&c);

            edge[a].push_back(b);
            cost[a].push_back(c);

            edge[b].push_back(a);
            cost[b].push_back(c);
        }


        int s=1,f=total;


        printf("Case %d: ",m);
        int tmp=dijkstra(s,f);
        if (tmp!=INF)
            printf("%d\n",tmp);
        else
            printf("Impossible\n");
    }

    return 0;
}
