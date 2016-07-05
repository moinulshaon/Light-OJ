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

#define SIZE 1005

char A[SIZE];
char B[SIZE];

int dp[SIZE][SIZE];

LL mod = 1000007;
LL pre[SIZE][SIZE];

int func(int r,int c){
    if ( r == 0 || c == 0 )return 1;

    int &ret = pre[r][c];
    if ( ret != -1 )return ret;

    if ( A[r] == B[c] ){
        ret = 1+func( r-1,c-1 );
    }else{
        if ( dp[r-1][c] == dp[r][c-1] ){
            ret = ( func(r-1,c) + func( r,c-1 ) - func(r-1,c-1) )%mod;
        }else if ( dp[r-1][c] > dp[r][c-1] ){
            ret = func( r-1,c );
        }else{
            ret = func( r,c-1 );
        }
    }
    return ret;

}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",&A[1]);
        scanf("%s",&B[1]);
        int n = strlen(&A[1]);
        int m = strlen(&B[1]);

        for (int i=0;i<=n;++i){
            dp[i][0] = 0;
        }
        for (int i=0;i<=m;++i){
            dp[0][i] = 0;
        }

        for (int i=0;i<=m;++i){
            printf("%c ",B[i]);
        }printf("\n");

        for (int i=1;i<=n;++i){
            printf("%c ",A[i]);
            for (int j=1;j<=m;++j){
                if ( A[i] == B[j] )dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
                printf("%d ",dp[i][j]);
            }printf("\n");
        }

        for (int i=0;i<=n;++i){
            for (int j=0;j<=m;++j){
                pre[i][j] = -1;
            }
        }

        printf("Case %d: %d\n",kk,( dp[n][m] == 0 )?1: func(n,m));
    }


    return 0;
}
