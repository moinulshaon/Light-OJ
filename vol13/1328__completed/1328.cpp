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


long long GetDiffSum( LL a[], int n )
{
    long long sum = 0;
    int i, j;
    for( i = 0; i < n; i++ ){

        LL tmp = 0;
        for( j = i + 1; j < n; j++ ){
                    sum += abs( a[i] - a[j] ); // abs means absolute value
            tmp+= abs( a[i] - a[j] );
        }
        cout<<tmp<<endl;
    }
    return sum;
}

#define SIZE 100100

LL arr[SIZE],sum[SIZE];
LL mod = 1000007;

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int k,c,n,a;
        scanf("%d %d %d %d",&k,&c,&n,&a);

        arr[0] = a;
        for (int i=1;i<n;++i){
            arr[i]=( k * arr[i-1] + c ) % mod;
        }

        sort( arr,arr+n );

        sum[0]=arr[0];
        for (int i=1;i<n;++i){
            sum[i] = sum[i-1]+arr[i];
        }


        LL ans = 0;
        for (int i=0;i<n;++i){
            ans+= sum[n-1]-sum[i] - (n-i-1)*arr[i];
            //cout<<sum[n-1]-sum[i] <<endl;
        }

        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}
