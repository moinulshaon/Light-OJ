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

#define SIZE 105

vector <int> edge[SIZE], cost[SIZE];
int total;

struct node{
    int val,city,cap;
    bool operator < (const node & p)const{return val>p.val;}
};

bool vis[SIZE][SIZE];
int price[SIZE];

int dijkstra(int s,int f,int lim){

    CLR(vis);

    node place,temp,u;
    place.val=0;
    place.cap=0;
    place.city=s;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();
        if (temp.city==f)return temp.val;

        if (vis[temp.city][temp.cap])
            continue;
        vis[temp.city][temp.cap]=true;


        for (int i=0;i<edge[temp.city].size();++i){
            u.val=temp.val;
            u.city=edge[temp.city][i];
            u.cap= temp.cap - cost[temp.city][i];

            if ( u.cap>=0 && !vis[u.city][u.cap] )
                q.push(u);
        }
        if ( temp.cap+1<=lim){
            u.val=temp.val+price[ temp.city ];
            u.city=temp.city ;
            u.cap= temp.cap +1 ;

            if ( u.cap>=0 && !vis[u.city][u.cap] )
                q.push(u);
        }
    }
    return -1;
}

bool check[SIZE];
bool pos( int x,int f,int lim ){

    if ( x== f )return true;

    check[x]=true;


    for (int i=0;i<edge[x].size()  ;++i){
        int y=edge[x][i];
        if ( !check[y] && cost[x][i]<=lim ){
            if ( pos( y,f,lim ) ){
                return true;
            }
        }
    }
    return false;

}

int main(){
    FRO

    int ee,kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&total,&ee);
        for (int i=0;i<total;++i){
            scanf("%d",&price[i]);
        }
        for (int i=0;i<total;++i){
            edge[i].clear();
            cost[i].clear();
        }
        int a,b,w;

        while ( ee-- ){
            scanf("%d %d %d",&a,&b,&w);
            edge[a].PB(b);
            cost[a].PB(w);

            edge[b].PB(a);
            cost[b].PB(w);
        }

        int qq;
        scanf("%d",&qq);

        printf("Case %d:\n",kk);
        while ( qq-- ){
            scanf("%d %d %d",&w,&a,&b);

            int ans=-1;

            CLR(check);
            if ( pos( a,b,w ) ){
                ans=dijkstra(a,b,w);
            }


            if ( ans== -1 ){
                printf("impossible\n");
            }else{
                printf("%d\n",ans);
            }
        }
    }


    return 0;
}
