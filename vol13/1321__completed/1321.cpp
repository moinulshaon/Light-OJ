#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int> edge[102];
vector <double> cost[102];

struct node{
    double val;
    int city;
    bool operator < (const node & p)const{return val<p.val;}
};


double dijkstra(int s,int f){

    bool vis[102]={false};

    node place,temp,u;
    place.val=1;
    place.city=s;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();
        if (temp.city==f)return temp.val;

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;


        for (int i=0;i<edge[temp.city].size();++i){

            u.val=cost[temp.city][i]*temp.val;
            u.city=edge[temp.city][i];

            if ( !vis[u.city] )
                q.push(u);
        }
    }
    return -1;
}


int main(){

    freopen("in.txt","r",stdin);

    int kase=1;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk)
    {

        for (int i=0;i<102;++i){
            edge[i].clear();
            cost[i].clear();
        }


        int u,v,n,m,s,k;
        double tmp;

        scanf("%d %d %d %d",&n,&m,&s,&k);
        while ( m-- ){
            scanf("%d %d %lf",&u,&v,&tmp);
            tmp/=100;
            edge[u].push_back( v );
            cost[u].push_back( tmp );

            edge[v].push_back( u );
            cost[v].push_back( tmp );

        }

        double pp=dijkstra(0,n-1);

        printf("Case %d: %lf\n",kk,2.0*k*s/pp);

    }

    return 0;
}
