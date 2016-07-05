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

long long BigMod ( long long a, long long p, long long m ){
    long long res = 1;
    long long x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res % m;
}

#define SIZE 1010000

LL fact[SIZE];
LL mod = 100000007;

LL ncr(int n,int r){
    if ( r >n )return 0;
    return ( fact[n]* BigMod( ( fact[n-r]*fact[r] )%mod,mod-2,mod ) )%mod;
}

vector<int> vec;
int k,n;

int main(){

    FRO

    fact[0] = 1;
    for (int i=1;i<SIZE;++i){
        fact[i] = ( fact[i-1]*i )%mod;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&k,&n);

        vec.clear();
        vec.resize(k);

        int sum = 0;
        int a,b;
        for (int i=0;i<k;++i){
            scanf("%d %d",&a,&b);
            b++;
            sum += a;
            vec[i] = b-a;
        }

        printf("Case %d: ",kk);
        if ( sum>n ){
            printf("0\n");
        }else if ( sum == n ){
            printf("1\n");
        }else{
            n -= sum;
            //cout<<n<<endl;

            LL ans = ( ncr( n+k-1 ,k-1 ) )%mod;

            //cout<<ans<<endl;

            LL ee= 0;
            for (int state = 1 ; state <(1<<k) ; ++state ){

                LL tmp = n ;
                for (int i=0;i<k;++i){
                    if ( state & (1<<i) ){
                        tmp -= vec[i];
                    }
                }

                if ( tmp<0 )continue;

                if ( __builtin_popcount(state) & 1 ){
                    ee += ncr( tmp+k-1,k-1 );
                }else{
                    ee -= ncr( tmp+k-1,k-1 );
                }
                ee %= mod;
            }
            cout<<ans<<" "<<ee<<endl;
            ans = ( ans - ee )%mod;
            if ( ans <0 )ans += mod;

            printf("%lld\n",ans);

        }

    }


    return 0;
}
