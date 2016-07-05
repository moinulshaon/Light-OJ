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

#define SIZE 100100

int arr[SIZE];
int sum[SIZE];
int cnt[SIZE];

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m;
        scanf("%d %d",&n,&m);

        sum[0] = 0;
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            sum[i] = ( sum[i-1]+arr[i] )%m;
        }
        for (int i=0 ;i<m;++i){
            cnt[i] = 0;
        }

        LL ans = 0;
        cnt[0] = 1;
        for (int i=1;i<=n;++i){
            ans += cnt[ sum[i] ];
            cnt[ sum[i] ]++;
        }

        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}
