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

const int INF=(1<<29);

#define SIZE 105

int w[SIZE],p[SIZE],req[SIZE];
int n;

int luv[10100];


struct node{
    int val,city;
    bool operator < (const node & p)const{return val<p.val;}
};


int dijkstra(int s){

    node place,temp,u;
    place.val=0;
    place.city=s;

    priority_queue<node> q;

    if ( place.city>=0 )
        q.push(place);


    while (!q.empty()){
        temp=q.top();q.pop();

        if ( luv[temp.city]>=temp.val )
            continue;
        luv[ temp.city ]=temp.val;
        for (int i=0;i<n;++i){
            u.val=temp.val+p[i];
            u.city=temp.city-w[i];
            if ( u.city>=0 && luv[u.city]<u.val )
                q.push(u);
        }
    }
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int sack;
        scanf("%d %d",&n,&sack);

        for (int i=0;i<n;++i){
            scanf("%d %d %d",&p[i],&req[i],&w[i]);
            sack-=req[i]*w[i];
        }

        memset(luv,-1,sizeof(luv));

        dijkstra(sack);

        int ans= -1;
        for (int i=0;i<=sack;++i){
            if ( luv[i]>ans ){
                ans=luv[i];
            }
        }

        if (ans<0){
            printf("Impossible\n");
        }else{
            printf("%d\n",ans);
        }
    }

    return 0;
}
