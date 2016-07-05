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


typedef pair<LL,LL> pint;
typedef map<int,int> mint;


#define SIZE 55

pint dp[SIZE][SIZE];

pint func( int n,int k ){

    if ( k== 1 )return MP(1,n);
    if ( k>n )return MP(0,0);
    pint &ret = dp[n][k];
    if ( ret.X != -1 )return ret;

    ret.X = func( n-1,k-1 ).X * func( n-1,k-1 ).Y  +  func(n-1,k).X * ( n- func(n-1,k).Y * (k-1)  );
    ret.Y = 1 + func( n-1,k ).Y;

    return ret;
}

int main(){

    NEG(dp);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,k;
        scanf("%d %d",&n,&k);
        cout<<func(n,k).X<<" "<<func(n,k).Y<<endl;
        printf("Case %d: %lld\n",kk,func(n,k).X);
    }

    return 0;
}
