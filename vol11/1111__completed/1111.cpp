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

#define SIZE 1010

vector<int> out[SIZE];
int reach[SIZE];
int cnt;
bool vis[SIZE];

void dfs(int x){
    if ( vis[x] )return ;

    vis[x]=true;
    if ( reach[x] )cnt+=reach[x];

    for (int i=0;i<out[x].size();++i){
        dfs( out[x][i] );
    }
}

int main(){


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int u,v,person,node,edge;
        scanf("%d %d %d",&person,&node,&edge);
        CLR(reach);

        for (int i=0;i<person;++i){
            scanf("%d",&u);
            reach[u]++;
        }

        for (int i=0;i<=node;++i){
            out[i].clear();
        }
        while(edge--){
            scanf("%d %d",&u,&v);
            out[v].PB(u);
        }
        int ans=0;
        for (int i=1;i<=node;++i){

            cnt=0;
            CLR(vis);
            dfs(i);
            if ( cnt==person ){
                ans++;
                //cout<<i<<endl;
            }

        }
        printf("Case %d: %d\n",kk,ans);

    }

    return 0;
}
