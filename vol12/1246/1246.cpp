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

LL mod = 1000000007;

LL save[410][410];
LL ncr(int n,int r){
    if ( r<0 || r>n )exit(5);

    if ( r==0 || r==n )return 1;
    LL &ret = save[n][r];
    if ( ret != -1 )return ret;
    return ret = ( ncr( n-1,r ) + ncr( n-1,r-1 ) )%mod;
}

LL dp[450][55];

LL func( int itemleft,int colorleft ){

    if ( itemleft == 0 ){
        if ( colorleft == 0 )return 1;
        else return 0;
    }
    if ( colorleft == 0 ){
        return 0;
    }

    LL &ret = dp[itemleft][colorleft];
    if ( ret != -1 )return ret;

    ret = 0;
    for (int i=1;i<=itemleft;++i){
        ret += ncr(itemleft,i) * func(itemleft-i,colorleft-1);
        ret%=mod;
    }
    ret%=mod;

    return ret%mod;
}

int main(){

    FRO

    NEG(save);
    NEG(dp);


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);

        printf("Case %d: ",kk);
        if ( n==0 && m== 0 ){
            printf("%d\n",k);
            continue;
        }

        int tot = (n+1)*(m+1);

        int black = 0;
        for (int i=1;i<=(n+1);++i){
            if ( i%2 == 1 ){
                black += (m+1)/2+(m+1)%2;
            }else{
                black += (m+1)/2;
            }
        }

        int white= tot-black;

        //if ( white > black )swap( white,black );

        //cout<<black<<" "<<white<<endl;

        LL ans = 0;
        for (int i=0;i<=k;++i){
            for (int j=0;i+j<=k;++j){
                ans += ( ncr(k,i)*func( black,i )  )%mod * ( ( ncr(k-i,j) * func(white,j) )%mod );
                ans %=mod;
            }
        }

        ans %= mod;
        //if ( ans<0 )ans +=mod;

        printf("%lld\n",ans);
    }

    return 0;
}
