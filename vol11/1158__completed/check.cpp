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

char str[15];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        scanf("%s",str);

        LL d ;
        scanf("%lld",&d);

        int n= strlen(str);
        sort( str,str+n );
        int ans = 0;
        do{
            LL tmp ;
            sscanf(str,"%lld",&tmp);
            ans += ( tmp%d==0 );
        }while ( next_permutation(str,str+n) );

        cout<<ans<<endl;

    }


    return 0;
}
