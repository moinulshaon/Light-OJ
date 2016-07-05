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

#define SIZE 50100

pint given[SIZE];

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d %d",&given[i].X,&given[i].Y);
        }
        sort( given,given+n );
        int ans = 0;
        for (int i=0;i+ans < n;++i){
            for (int j=i+ans;j<n;++j){
                if ( given[j].X <= given[i].Y ){
                    ans++;
                }else{
                    break;
                }
            }
        }

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
