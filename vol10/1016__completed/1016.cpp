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

#define SIZE 51000

LL arr[SIZE];

int main(){
    FRO

    int kase;
    LL n,w;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%lld %lld",&n,&w);

        LL tmp;
        for (int i=0;i<n;++i){
            scanf("%lld %lld",&tmp,&arr[i]);
        }
        sort(arr,arr+n);
        LL ans=0;

        for (int i=0;i<n;++i){
            ans++;
            tmp=0;
            for (int j=1;i+j<n;++j){
                if ( arr[i+j]-arr[i]<=w ){
                    tmp++;
                }
            }
            i+=tmp;
        }
        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}
