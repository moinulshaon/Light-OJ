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

int n,lim;
vector<int> out[SIZE],cost[SIZE];

int dp[SIZE][SIZE][SIZE][2];
int save[SIZE];

int func( int totake,int childno ,int mx,int prv,bool carry ){

    int &ret = dp[totake][childno][mx][carry];

    //cout<<totake<<endl;

    if ( ret != -1 )return ret;

    if (  out[totake].size()<= ( prv != 0 ) )return 0;

    if ( childno==0 )save[totake] = mx;

    if ( childno==out[totake].size() )return 0;
    else if ( out[totake][childno] == prv )return func( totake,childno+1,mx,prv,carry );


    ret = 1+func( out[totake][childno],0,lim,totake ,false ) + func( totake,childno+1,mx,prv,false );

    for (int i=cost[totake][childno];i<=mx;++i){
        ret = min( ret, func( out[totake][childno],0,i-cost[totake][childno],totake,false )
                        +( (carry)?func( totake,childno+1, min(mx,save[totake]-i) ,prv,true ):
                                func(totake,childno+1,mx-i,prv,true) ) );
    }

    //cout<<totake<<" "<<childno<<" "<<mx<<" "<<" "<<ret<<endl;
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&lim);

        for (int i=1;i<=n;++i){
            out[i].clear();
            cost[i].clear();
        }

        int a,b,w;
        for (int i=1;i<n;++i){
            scanf("%d %d %d",&a,&b,&w);
            out[a].PB(b);
            cost[a].PB(w);

            out[b].PB(a);
            cost[b].PB(w);
        }

        for (int i=1;i<=n;++i){
            for (int j=0;j<out[i].size();++j){
                for (int k=0;k<=lim;++k){
                    dp[i][j][k][0] = dp[i][j][k][1] =  -1;
                }
            }
        }

        printf("Case %d: %d\n",kk,1+func( 1, 0,lim,0,false ));
    }


    return 0;
}
