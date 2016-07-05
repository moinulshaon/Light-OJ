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

#define SIZE 26

int fish[SIZE];
int red[SIZE];
int cost[SIZE];
int n;

int dp[SIZE][195][195];

int func(int totake,int now,int have){

    if ( totake == n ){
        return 0;
    }

    int &ret = dp[totake][now][have];
    if ( ret != -1 )return ret;

    ret = 0;

    if ( have -1 >=0 ){
        ret = max( ret , max(0,fish[totake]-red[totake]*now) + func( totake,now+1,have-1 ) );
    }
    if ( have - cost[totake] >=0 ){
        ret = max( ret , func( totake+1,0,have-cost[totake] ) );
    }

    return ret;
}

int ans[SIZE];

void print( int totake,int now,int have ){

    if ( totake == n ){
        return ;
    }
    int ret = func( totake,now,have );

    if ( have -1 >=0 && ret == max(0,fish[totake]-red[totake]*now) + func( totake,now+1,have-1 ) ){
        ans[ totake ]++;
        print( totake,now+1,have-1  );
    }else if ( have - cost[totake] >=0 && ret == func( totake+1,0,have-cost[totake] ) ){
        print( totake+1,0,have-cost[totake] );
    }

}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);
    for (int kk=1; kase-- ;++kk ){
        int h;
        scanf("%d %d",&n,&h);
        h = h *60 /5;

        for (int i=0;i<n;++i){
            scanf("%d",&fish[i]);
        }
        for (int i=0;i<n;++i){
            scanf("%d",&red[i]);
        }
        for (int i=0;i<n-1;++i){
            scanf("%d",&cost[i]);
        }
        cost[n-1] = 0;
        NEG(dp);

        CLR(ans);
        print( 0,0,h );

        printf("Case %d:\n",kk);
        for (int i=0;i<n;++i){
            if ( i )printf(", ");
            printf("%d",ans[i]*5);
        }printf("\n");

        printf("Number of fish expected: %d\n",func( 0,0,h ));
    }

    return 0;
}
