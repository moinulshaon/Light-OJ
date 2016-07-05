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

#define SIZE 5010

double dp[SIZE];
bool vis[SIZE];

int n;

bool func( int have ){
    if ( have == 0 ){
        return 0;
    }

    double &ret = dp[have];
    if ( vis[have] )return ret;

    double p = double(have)/n;
    vis[have]=true;

    cout<<p<<endl;

    ret = ( p* func( have-1 ) + 1.0 )/p;
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        double ans = 0;
        int b,tmp;

        double avg = 0;
        scanf("%d",&n);

        int cnt = 0;
        for (int i=0;i<n;++i){
            scanf("%d %d",&tmp,&b);
            if ( b == 2 ){
                ++cnt;
                avg += tmp;
            }else{
                ans += tmp;
            }
        }
        if ( cnt >0 )
            avg = avg /cnt;

        CLR(vis);

        ans += func( cnt )*avg;

        printf("%.8lf\n",ans);
    }


    return 0;
}
