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

int main(){

    int kase;
    scanf("%d",&kase);
    int n;

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);

        printf("Case %d: ",kk);
        if ( n == 1 ){
            printf("1\n");
        }else if ( n == 2 ){
            printf("3\n");
        }else if ( n == 3 ){
            printf("5\n");
        }else{
            int s = sqrt( n )+1e-8;
            LL ans = 0;
            for (int i=1;i<s;++i){
                ans += LL(n)/i;
                ans +=  LL(i)*( n/i - n/(i+1) );
            }
            if ( s*s == n ){
                ans += s;
            }else{
                ans += LL(n)/s;
                ans +=  LL(s)*( n/s - s );
            }
            printf("%lld\n",ans);
        }

    }


    return 0;
}
