#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define SIZE 5100

vector <int> edge[SIZE], cost[SIZE];
int total;

struct node{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};

int dist[SIZE][2];

void dijkstra(int s,int f){

    memset(dist,-1,sizeof(dist));

    node place,temp,u;
    place.val=0;
    place.city=s;


    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){
        temp=q.top();q.pop();

        if (dist[temp.city][0]== -1){
            dist[temp.city][0]=temp.val;
        }else if (temp.val!=dist[temp.city][0] &&  dist[temp.city][1]== -1){
            dist[temp.city][1]=temp.val;
            if ( temp.city==f )return ;
        }else{
            continue;
        }


        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            q.push(u);
        }
    }
}
int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int vertex,ee;
        scanf("%d %d",&vertex,&ee);

        for (int i=0;i<=vertex;++i){
            edge[i].clear();
            cost[i].clear();
        }

        int a,b,w;
        while(ee--){
            scanf("%d %d %d",&a,&b,&w);

            edge[a].PB(b);
            cost[a].PB(w);

            edge[b].PB(a);
            cost[b].PB(w);
        }

        dijkstra(1,vertex);
        printf("Case %d: %d\n",kk,dist[vertex][1]);
    }

    return 0;
}
