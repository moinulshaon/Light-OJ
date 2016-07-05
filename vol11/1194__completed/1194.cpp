
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;


#define SIZE 100010

int n,m;
int arr[SIZE];
LL ini[20];
int occur[SIZE][20];
LL cost[20][20];
vector<int> pos[20];

LL dp[1<<17];


LL func(int state){

    if ( state == (1<<m)-1 )return 0;

    LL &ret = dp[state];
    if ( ret != -1 )return ret;

    ret = 1LL<<50;
    for (int i=0;i<m;++i){
        if ( ( state & (1<<i) ) == 0 ){

            LL tmp = 0;
            for (int j=0;j<m;++j){
                if ( ( state & (1<<j) ) != 0 ){
                    tmp += cost[i][j];
                }
            }
            ret = min( ret , ini[i]-tmp + func( state | (1<<i) ) );
        }
    }

    return ret;
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);

        for (int i=0;i<m;++i){
            ini[i] = 0;
            pos[i].clear();
            for (int j=0;j<m;++j){
                cost[i][j] = 0;
            }
        }

        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            arr[i]--;
            pos[ arr[i] ].PB( i );
        }

        for (int i=0;i<=n;++i){
            for (int j=0;j<=m;++j){
                occur[i][j] = 0;
            }
        }

        for (int i=1;i<=n;++i){
            for (int j=0;j<m;++j){
                occur[i][j] = occur[i-1][j];
            }
            occur[i][ arr[i] ]++;
        }

        for (int i=1;i<=n;++i){
            ini[ arr[i] ] += i-occur[i][ arr[i] ];
        }

        for (int i=0;i<m;++i){
            for (int j=0;j<m;++j){
                if ( i==j )continue;

                for (  int k=0;k<pos[i].size();++k ){
                    cost[i][j] += occur[ pos[i][k] ][j];
                }

            }
        }

        for (int i=0;i<(1<<m);++i){
            dp[i] = -1;
        }
        printf("Case %d: %lld\n",kk,func(0));
    }

    return 0;
}
