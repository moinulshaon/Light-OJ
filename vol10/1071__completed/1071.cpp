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

#define FO(i,a,b) for (int i = (a); i < (b); i++)

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

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }

#define SIZE 105

int dp[SIZE][SIZE][SIZE][2];
int n,m;
int arr[SIZE][SIZE];

int func(int x,int y,int alt,int can){

    if ( x == n && y == m-1 && alt == m ){
        return 0;
    }

    int &ret = dp[x][y][alt][can];
    if ( ret != -1 )return ret;

    ret = -(1<<29);
    if ( alt+1<=m ){
        ret = max( ret , arr[x][alt+1]+func( x,y,alt+1,0 ) );
    }
    if ( can && y+1<alt ){
        ret = max( ret , arr[x][y+1] + func( x,y+1,alt,1 )  );
    }
    if ( x+1<= n )
        ret = max( ret , arr[x+1][y] + arr[x+1][alt] + func( x+1,y,alt,1 ) );

    return ret;
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                scanf("%d",&arr[i][j]);
            }
        }
        FO(i,1,n+1)FO(j,1,m+1)FO(k,1,m+1)dp[i][j][k][0]=dp[i][j][k][1] = -1;

        printf("Case %d: %d\n",kk,arr[1][1] + arr[1][2] + func( 1,1,2,1 ) );

    }

    return 0;
}
