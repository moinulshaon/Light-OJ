#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define sz 510

vector <int> edge[sz], cost[sz];
int total;

struct node
{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};

int result[sz];
bool vis[sz];

void dijkstra(int s)
{

    memset(vis,0,sizeof(vis));

    node place,temp,u;
    place.val=0;
    place.city=s;




    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;

        result[ temp.city ]=temp.val;

        for (int i=0;i<edge[temp.city].size();++i){

            u.val=max( cost[temp.city][i], temp.val );
            u.city=edge[temp.city][i];

            q.push(u);
        }
    }



}

int main(){

    freopen("in.txt","r",stdin);

    int kase,e,a,b,c;

    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&total,&e);

        memset(result,-1,sizeof(result));

        for (int i=0;i<total;++i){
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

        printf("Case %d:\n",kk);
        scanf("%d",&a);
        dijkstra(a);

        for (int i=0;i<total;++i){
            if (result[i]!=-1)
                printf("%d\n",result[i]);
            else
                printf("Impossible\n");
        }


    }
    return 0;
}
