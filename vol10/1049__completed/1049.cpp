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

#define SIZE 110

int node;

vector<int> out[SIZE],cost[SIZE];

int ans;

bool vis;

void dfs( int x,int parent,int sum ){
    //printf("%d\n",x);
    if ( x==1 ){
        if ( vis ){
            ans=min(ans,sum);
            return ;
        }
        vis=true;
    }


    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != parent ){
            dfs( out[x][i],x,sum+cost[x][i] );
        }
    }

}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&node);
        for (int i=0;i<=node;++i){
            out[i].clear();
            cost[i].clear();
        }

        int u,v,w;
        for (int i=0;i<node;++i){
            scanf("%d %d %d",&u,&v,&w);
            out[u].PB(v);
            cost[u].PB(0);

            out[v].PB(u);
            cost[v].PB(w);
        }

        ans=(1<<29);

        vis=false;
        dfs(1,0,0);

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
