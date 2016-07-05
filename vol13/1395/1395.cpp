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



#define SIZE 105

int n;
int ps;
int ns;
int rem;

double pos;
double neg;

bool vis[SIZE];
double dp[SIZE];

double func( int x ){

    if ( x  == ns ){
        return pos/ps;
    }

    double &ret = dp[x];
    if ( vis[x] )return ret;

    int all = n-x;
    if ( x == rem ){
        double tmp = 1.0 - double(ns-x)/all;
        ret = ( pos / all )  + ( ( 1.0 - double(x)/ns )* neg ) / all;
        ret /= tmp;
    }else{
        ret = pos / all;
        //show( "xx",ps,ns-x,( 1.0 - double(x)/ns )* neg );
        ret += ( ( 1.0 - double(x)/ns )* neg+ (ns-x)* func( x+1 ) ) / all ;
    }
    //show( x,ret );
    return ret;

}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk = 1; kase-- ;++kk ){
        scanf("%d %d",&n,&rem);

        pos = neg = 0;
        int tmp;
        ns = ps = 0;
        for (int i=0;i<n;++i){
            scanf("%d",&tmp);
            if ( tmp <0 ){
                ns ++ ;
                neg += -tmp;
            }else{
                ps++;
                pos += tmp;
            }
        }
        //show( pos,neg );

        printf("Case %d: ",kk);
        if ( pos < 0.5 ){
            printf("-1\n");
            continue;
        }

        CLR(vis);

        printf("%.8f\n",func(0));

    }

    return 0;
}
