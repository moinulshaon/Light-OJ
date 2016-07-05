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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 30100
struct tt{
    int a,b,w;
}arr[SIZE];

int dp[SIZE];
int n;

int func( int totake ){

    if ( totake >= n )return 0;

    if ( dp[totake] != -1 )return dp[totake];

    int low = totake+1,high= n;
    int mid ;
    while ( low<=high ){
        mid = (low+high)>>1;
        if ( arr[mid].a > arr[totake].b ){
            high=mid-1;
        }else{
            low = mid+1;
        }
    }
    return dp[totake] = max( arr[totake].w + func( low ) , func( totake+1 ) );
}

bool cmp( const tt&x,const tt&y ){
    return x.a<y.a;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].w);
            arr[i].b+= arr[i].a-1;
        }

        sort( arr,arr+n,cmp );

        for (int i=0;i<=n;++i){
            dp[i] = -1;
        }

        printf("Case %d: %d\n",kk,func(0));
    }


    return 0;
}
