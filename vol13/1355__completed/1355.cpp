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

#define SIZE 1010

vector<int> out[SIZE];
vector<LL> weight[SIZE];

LL dfs( int x,int p ){

    int y;
    LL grundy = 0;

    for (int i=0;i<out[x].size();++i){
        y = out[x][i];
        if ( y== p )continue;

        if ( weight[x][i]>1 )
            grundy^= ( weight[x][i]%2 ) ^  dfs( y,x );
        else
            grundy^= 1 +  dfs( y,x );


        //if ( p== -1 )cout<<grundy<<endl;
    }
    //cout<<x<<" "<<grundy<<endl;
    return grundy;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        for (int i=0;i<=n;++i){
            out[i].clear();
            weight[i].clear();
        }

        int u,v,w;
        for (int i=1;i<n;++i){
            scanf("%d %d %d",&u,&v,&w);
            out[u].PB( v );
            weight[u].PB( w );

            out[v].PB( u );
            weight[v].PB( w );
        }

        LL grundy=dfs( 0 ,-1);

        //cout<<grundy<<endl;

        printf("Case %d: ",kk);
        if ( grundy>0 ){
            printf("Emily\n");
        }else{
            printf("Jolly\n");
        }

    }


    return 0;
}
