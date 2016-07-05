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

char str[210];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL n;
        scanf("%s %lld",str,&n);
        if ( str[0] == '-' )str[0] = '0';

        LL ans = 0;
        for (int i=0;str[i];++i){
            ans = ( ans*10 + (str[i]-'0') ) % n;
        }

        if ( ans ==0 ){
            printf("Case %d: divisible\n",kk);
        }else{
            printf("Case %d: not divisible\n",kk);
        }

    }

    return 0;
}
