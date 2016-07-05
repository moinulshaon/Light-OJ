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

#define SIZE 110

int arr[SIZE];
int pos[SIZE];

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            pos[ arr[i] ] = i;
        }
        int cnt = 0;
        for (int i=1;i<=n;++i){
            if ( arr[i] != i ){
                pos[ arr[i] ] = pos[ i ];
                swap( arr[ i ] , arr[ pos[i] ] );
                cnt++;
            }
        }
        printf("Case %d: %d\n",kk,cnt);
    }


    return 0;
}
