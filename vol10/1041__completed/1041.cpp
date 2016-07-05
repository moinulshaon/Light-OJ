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

const int INF=(1<<29);

int dis[SIZE][SIZE];
int node;
bool vis[SIZE];
int mind[SIZE];

int prim(int start){

    memset(vis,false,sizeof(vis));
    vis[start]=true;

    for (int i=0;i<node;++i){
        mind[i]=dis[start][i];
    }
    int ans=0;

    for (int i=1;i<node;++i){
        int mn=INF,x= -1;

        for (int j=0;j<node;++j){
            if ( !vis[j]  && mind[j]<mn ){
                mn=mind[j];
                x=j;
            }
        }
        //printf("prim %d\n",x);
        if ( x == -1 )return -1;

        vis[x]=true;
        ans+= mind[x];

        for (int j=0;j<node;++j){
            if ( !vis[j] && dis[x][j]<mind[j] ){
                mind[j]=dis[x][j];
            }
        }
    }
    return ans;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        map<string,int> mp;
        string a,b;
        int w,ed,x,y;

        scanf("%d",&ed);
        node=0;

        for (int i=0;i<SIZE;++i){
            for (int j=0;j<SIZE;++j){
                dis[i][j] = INF;
            }
        }

        while( ed-- ){
            cin>>a>>b>>w;
            if ( mp.find( a )==mp.end() ){
                mp[a]=node++;
            }
            if ( mp.find( b )==mp.end() ){
                mp[b]=node++;
            }
            x=mp[a];
            y=mp[b];


            dis[x][y]=dis[y][x]= min( w, dis[x][y] );

        }

        int tt=prim(0);
        if ( tt!= -1 )
            printf("Case %d: %d\n",kk,tt);
        else
            printf("Case %d: Impossible\n",kk);
    }

    return 0;
}
