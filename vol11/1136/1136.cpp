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

int func(int x){
    if(!x) return 0;
    int m = x % 10;
    return ( (x / 10) * 45 + (m * m + m) / 2 + func(x / 10) )%3;
}


int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",func( b )-func( a-1 ));
    }


    return 0;
}
