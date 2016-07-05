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

#define SIZE 100000001
#define LIM 15

int dp[SIZE/LIM+10];
int mod = 10000;

int main(){
    int cnt = 0;

    dp[0] = 1;
    dp[cnt++] = 1;
    int prv = 1;
    int now ;
    for (int i=1;i<SIZE;++i){
        now = ( prv*(i%mod)+1 )%mod;
        if ( i%LIM ==0 )dp[cnt++] = now;
        prv = now;
    }

    int kase;
    scanf("%d",&kase);

    int n;
    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        now =prv= dp[n/LIM];

        for (int i=LIM*(n/LIM)+1;i<=n;++i){
            now = ( prv*(i%mod)+1 )%mod;
            prv = now;
        }
        printf("Case %d: ",kk);
        if ( n>=10 )printf("%04d\n",now);
        else printf("%d\n",now);
    }


    return 0;
}
