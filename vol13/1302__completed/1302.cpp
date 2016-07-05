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

#define SIZE 80

LL dp[SIZE][SIZE];
char str[SIZE];
int n;

LL func( int low,int high ){

    if ( low > high )return 1;

    LL &ret = dp[low][high];
    if ( ret != -1 )return ret;

    ret = 0;
    for (int i=low+1;i<=high;++i){
        for (int j=i+1;j<=high;++j){
            if ( str[low]+str[i]+str[j] >= 2 ){
                ret += func( low+1,i-1 ) * func( i+1,j-1 ) * func( j+1,high );
            }
        }
    }

    return ret;
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",str);
        n = strlen( str );

        for (int i=0;i<n;++i){
            if ( str[i] == 'B' ){
                str[i] = 1;
            }else{
                str[i] = 0;
            }
        }

        NEG(dp);
        printf("Case %d: %lld\n",kk,func( 0,n-1 ));

    }


    return 0;
}
