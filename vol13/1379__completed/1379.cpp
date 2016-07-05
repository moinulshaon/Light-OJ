#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 10010
const int INF=(1<<29);

vector <int> edge[SIZE], cost[SIZE],redge[SIZE],rcost[SIZE];
int total;

struct node
{
    int val,city;
    bool operator < (const node & p)const{
        return val>p.val;
    }
};

int forwardd[SIZE];
int backwardd[SIZE];


void dijkstra(int s,int f){
    bool vis[SIZE]={false};

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
        forwardd[ temp.city ]=temp.val;

        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];
            q.push(u);
        }
    }
}


void dijkstra2(int s,int f){
    bool vis[SIZE]={false};

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
        backwardd[ temp.city ]=temp.val;

        for (int i=0;i<redge[temp.city].size();++i){
            u.val=rcost[temp.city][i]+temp.val;
            u.city=redge[temp.city][i];
            q.push(u);
        }
    }
}

struct ttt{
    int start,end,w;
}hhh[50010];



void makeinf(int arr[]){
    for (int i=1;i<=total;++i){
        arr[i]=INF;
    }
}

bool cmp( const ttt&a,const ttt&b ){
    return a.w>b.w;
}

int main()
{

    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    for (int m=1;kase--;++m){
        int s,f,taka,ee;
        scanf("%d %d %d %d %d",&total,&ee,&s,&f,&taka);

        for (int i=1;i<=total;++i){
            edge[i].clear();
            cost[i].clear();

            rcost[i].clear();
            redge[i].clear();
        }

        int x,y,w,cnt=0;
        while(ee--){
            scanf("%d %d %d",&x,&y,&w);
            edge[x].push_back(y);
            cost[x].push_back(w);

            redge[y].push_back( x );
            rcost[y].push_back( w );

            hhh[cnt].start=x;
            hhh[cnt].end=y;
            hhh[cnt].w=w;
            cnt++;
        }
        makeinf(forwardd);
        dijkstra(s,f);
        makeinf(backwardd);
        dijkstra2(f,s);

        sort(hhh,hhh+cnt,cmp);
        int ans= -1;
        for (int i=0;i<cnt;++i){
            if ( forwardd[ hhh[i].start ]+hhh[i].w+backwardd[ hhh[i].end ]<=taka ){
                ans=hhh[i].w;
                break;
            }
        }
        printf("Case %d: %d\n",m,ans);
    }
    return 0;
}
