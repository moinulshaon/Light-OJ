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

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


#define SIZE 50010

vector <int> edge[SIZE];

struct node{
    int val,city,prv;
    bool operator < (const node & p)const{
        if ( val!=p.val )
            return val>p.val;
        else
            return prv>p.prv;

    }
};

int prvnode[SIZE];
bool vis[SIZE];

void dijkstra(int s,int f){

    NEG(prvnode);
    CLR(vis);

    node place,temp,u;
    place.val=0;
    place.city=s;
    place.prv= -1 ;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();


        if (vis[temp.city])
            continue;
        vis[temp.city]=true;

        prvnode[ temp.city ]= temp.prv ;

        if (temp.city==f)break;

        for (int i=0;i<edge[temp.city].size();++i){

            u.val=1+temp.val;
            u.city=edge[temp.city][i];
            u.prv= temp.city ;

            q.push(u);
        }
    }

    int to=f;

    while (prvnode[to]!=-1){
        printf("%d ",to);
        to=prvnode[to];
    }

    printf("%d\n",to);

}

int main(){
    FRO


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        for (int i=0;i<SIZE;++i){
            edge[i].clear();
        }

        int tmp,start,end,u,v;
        scanf("%d",&tmp);
        scanf("%d",&u);
        start=u;
        tmp--;
        while ( tmp-- ){
            scanf("%d",&v);
            edge[u].PB(v);
            edge[v].PB(u);

            //printf("%d %d\n",u,v);

            u=v;
        }

        end=v;

        printf("Case %d:\n",kk);
        dijkstra(end,start);

    }


    return 0;
}
