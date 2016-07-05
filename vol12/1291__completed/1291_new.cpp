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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 10100

vector<int> out[SIZE];
bool isArtic[SIZE];
int level[SIZE];
int low[SIZE];
int childrenCnt[SIZE];

vector< pint > vec;

vector<int> super[SIZE];

int ans;

int num[SIZE];
int global;

bool vis[SIZE];

void func( int x ){

    vis[x]=true;

    int y;
    int tmp=0;
    for (int i=0;i<super[x].size();++i){
        y= super[x][i];

        if ( vis[y] )continue;

        tmp++;
        func( y );
    }

    if ( x==0 ){
        if ( tmp==1 )
            ans++;
    }else{
        if ( tmp==0 )
            ans++;
    }
}

void another(int x,int now ){

    //cout<<x<<endl;

    num[x]=now;
    vis[x]=true;

    int y;
    for (int i=0;i<out[x].size();++i){
        y= out[x][i];

        if ( vis[y]  )continue;

        if ( find( vec.begin(),vec.end(),MP( min(x,y),max(x,y) ) ) == vec.end() ){
            another( y,now );
        }else{
            another( y,++global );
        }
    }

}
void dfs( int x ){
    //printf("%d %d\n",x,level[x]);
    low[x]=level[x];
    int y;
    for (int i=0;i<out[x].size();++i){
        y=out[x][i];
        if ( level[ y ]== -1 ){

            level[ y ]=level[x]+1;
            childrenCnt[ x ]++;

            dfs( y );

            low[x]=min( low[x],low[y] );

            if ( low[y]>level[x] ){
                vec.PB( MP( min(x,y),max(x,y) ) );
            }
        }else if ( level[y]< level[x]-1 ){
            low[x]=min( low[x],level[y] );
        }
    }
}

int main(){

    FRO

    int kase,a,b,v,e;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&v,&e);
        for (int i=0;i<v;++i){
            out[i].clear();
        }

        while(e-- ){
            scanf("%d %d",&a,&b);
            out[a].push_back(b);
            out[b].push_back(a);
        }


        memset( level,-1,sizeof(level));
        memset( childrenCnt,0,sizeof(childrenCnt));
        memset( isArtic,false,sizeof(isArtic) );

        level[0]=0;
        vec.clear();

        dfs(0);

        sort( vec.begin(),vec.end() );
        global= -1 ;

        for (int i=0;i<v;++i){
            vis[i]=false;
        }

        another(0,++global);

        ans=0;

        for (int i=0;i<=global;++i){
            vis[i]=false;
        }
        for (int i=0;i<=global;++i){
            super[i].clear();
        }

        for (int i=0;i<v;++i){
            for (int j=0;j<out[i].size();++j){
                super[ num[i] ].PB( num[ out[i][j] ] );
            }
        }


        func( 0 );

        printf("Case %d: %d\n",kk,ans/2 + ans%2 );
    }
    return 0;

}

