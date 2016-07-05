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

double dp[SIZE][SIZE][2];
bool vis[SIZE][SIZE][2];
int n;

double func( int totake,int have,bool three ){

    if ( totake == n ){
        return 0;
    }

    double &ret = dp[totake][have][three];
    if ( vis[totake][have][three] )return ret;

    ret = 0;
    double p3 = double(have)/(n-totake);
    if ( three ){
        if ( have-1>=0 )
            ret += p3* func( totake+1,have-1, 1 );
        ret +=  (1.0-p3)* ( 1 + func( totake+1,have,0 ) );
    }else{
        if ( have-1>=0 )
            ret += p3* ( 1+ func( totake+1,have-1, 1 ) );
        ret +=  (1.0-p3)* (  func( totake+1,have,0 ) );
    }
    vis[totake][have][three]=true;
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int have;
        scanf("%d %d",&n,&have);

        have = have-2*n;

        CLR(vis);

        printf("Case %d: %.8lf\n",kk,func(0,have,1));

    }


    return 0;
}
