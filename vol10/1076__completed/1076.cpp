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

#define SIZE 1010

int arr[SIZE];
int n,m;

bool pos(int x){

    int cnt = 1;
    int left = x;
    for (int i=0;i<n;++i){
        if ( arr[i] >left ){
            cnt++;
            if ( cnt>m ){
                return false;
            }
            left= x;
        }
        left-= arr[i];
    }
    return true;
}

int main(){

    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);

        int mx = INT_MIN;
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            mx = max( mx,arr[i] );
        }

        int low = mx,high= (1<<30);
        int ans = -1;
        while ( low<=high ){
            int mid = (low+high)/2;
            if ( pos( mid ) ){
                high=mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }

        printf("Case %d: %d\n",kk,ans);

    }


    return 0;
}
