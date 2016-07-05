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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 100010

LL ans;
int n;
LL arr[SIZE];

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int qq;
        scanf("%d %d",&n,&qq);
        ans= 0;

        for (int i=0;i<n;++i){
            scanf("%lld",&arr[i]);
            ans -= arr[i] * i - arr[i]* ( n-i-1 );
        }


        printf("Case %d:\n",kk);
        int cc;
        int x;
        LL y;
        while ( qq-- ){
            scanf("%d",&cc);
            if ( cc== 1  ) {
                printf("%lld\n",ans);
            }else{
                scanf("%d %lld",&x,&y);
                ans += arr[x] * x - arr[x]* ( n-x-1 );
                arr[x]= y;
                ans -= arr[x] * x - arr[x]* ( n-x-1 );
            }
        }

    }

    return 0;
}
