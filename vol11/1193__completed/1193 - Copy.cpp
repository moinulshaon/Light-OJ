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

LL mod = 100000007;

LL dp[2][15010];
LL k;

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n,s;
        scanf("%d %lld %d",&n,&k,&s);

        for (int i=0;i<=s;++i){
            dp[0][i] = dp[1][i] = 0;
        }

        dp[0][0]=1;
        for (int i=1;i<=n;++i){
            for (int j=0;j<=s;++j){
                dp[i&1][j] = 2*dp[i&1][j-1]- k* ( (j-k-1>=0)?dp[(i&1)^1][j-k-1]:0 )
                            -( (j-2>=0)? dp[i&1][j-2]:0 )+ k* ( (j-k-2>=0)? dp[(i&1)^1][j-k-2]:0 )
                            + dp[(i&1)^1][j-1]-((j-k-1>=0)?dp[(i&1)^1][j-k-1]:0);
                //if ( abs(dp[i&1][j])>=mod )
                dp[i&1][j]%=mod;
            }
            //cout<<(i&1)<<" "<<( (i&1)^1 )<<endl;
        }

        if ( dp[n&1][s]<0 )dp[n&1][s]+=mod;

        printf("Case %d: %lld\n",kk,dp[n&1][s]%mod);
    }


    return 0;
}
