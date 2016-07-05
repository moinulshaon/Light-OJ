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

double dp[2][SIZE][2];
int n;

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int have;
        scanf("%d %d",&n,&have);

        have = have-2*n;

        for (int i=0;i<=have;++i){
            dp[0][i][0] = dp[0][i][1] = 0;
            dp[1][i][0] = dp[1][i][1] = 0;
        }

        for (int i=n-1;i>=0;--i){
            for (int j=0;j<=n-i;++j){
                for (int k=0;k<2;++k){

                    double &ret = dp[i&1][j][k];
                    ret = 0;
                    double p3 = double(j)/(n-i);


                    if ( k ){
                        if ( j-1>=0 )
                            ret += p3 * dp[ (i&1)^1 ][ j-1][ 1 ];
                        ret +=  (1.0-p3)* ( 1 + dp[ (i&1)^1][j][0] );
                    }else{
                        if ( j-1>=0 )
                            ret += p3 * ( 1 + dp[ (i&1)^1 ][ j-1 ][ 1 ] );
                        ret +=  (1.0-p3)* ( dp[ (i&1)^1 ][j][0] );
                    }
                }
            }
        }

        printf("Case %d: %.8lf\n",kk,dp[0][have][1]);

    }


    return 0;
}
