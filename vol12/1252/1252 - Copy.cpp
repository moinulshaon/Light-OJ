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

vector<int> dp[SIZE][SIZE][SIZE];

int func( int totake,int childno ,int left,int mx,int prv,int carry ){

    if ( childno >= out[totake].size() )return 0;


    int &ret = dp[totake][left][mx][childno];


    //cout<<dp[totake][left][mx].size()<<" "<<childno<<endl;

    if ( ret != -1 )return ret;

    if (  out[totake].size()<= ( prv != 0 ) )return 0;

    else if ( out[totake][childno] == prv )return func( totake,childno+1,left,mx,prv,carry );


    ret = 1+func( out[totake][childno],0,lim,lim,totake,0 ) + func( totake,childno+1,left,mx,prv,carry );
    ret = min( ret , func( out[totake][childno] ) )
    for (int i=cost[totake][childno];i<=mx;++i){
        ret = min( ret, func( out[totake][childno],0,left,i-cost[totake][childno],totake,0 )
                        +( (carry)?func( totake,childno+1, left,left-i ,prv,1 ):
                                func(totake,childno+1,left,min(left-i,mx),prv,1) ) );
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
            for (int j=0;j<=lim;++j){
                for (int k=0;k<=lim;++k){
                    dp[i][j][k].clear();
                    dp[i][j][k].resize( out[i].size() );
                    for (int a=0;a<dp[i][j][k].size();++a){
                        dp[i][j][k][a]= -1;
                    }
                }
            }
        }

        printf("Case %d: %d\n",kk,1+func( 1, 0,lim,lim,0,0 ));
    }


    return 0;
}
