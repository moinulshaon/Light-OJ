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

LL calc(LL x){
    return x*(x+1)/2;
}

int main(){

    int kase;
    scanf("%d",&kase);

    int n;
    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        LL ans = 0;

        for (int i=2;i*i<=n;++i){
            LL tmp = n/i;
            if ( tmp-i+1 <=0 )continue;
            ans += ( tmp-i+1 )*i;
            ans += calc(tmp)-calc(i);
        }
        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}
