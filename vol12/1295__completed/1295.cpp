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


#define SIZE 1010

struct tt{
    int level,source,percost,req;
}arr[SIZE];
int n;

int dp[SIZE][11];

int func(int totake,int val){

    if ( totake == n )return 0;

    int &ret = dp[totake][val];
    if ( ret != -1 )return ret;

    ret = min( arr[totake].source + min( arr[totake].percost,val )*arr[totake].req  + func( totake+1, min( arr[totake].percost,val ) ) ,
              val * arr[totake].req + func( totake+1,val ) );
    return ret;
}

bool cmp( const tt&a,const tt&b ){return a.level>b.level;}

int main(){

    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d %d %d %d",&arr[i].level,&arr[i].source,&arr[i].percost,&arr[i].req);
        }
        sort( arr,arr+n,cmp );

        for (int i=0;i<n;++i){
            for (int j=0;j<11;++j){
                dp[i][j] = -1;
            }
        }

        printf("Case %d: %d\n",kk,arr[0].source + arr[0].percost*arr[0].req + func( 1,arr[0].percost ));

    }

    return 0;
}
