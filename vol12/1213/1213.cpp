#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL square(LL k)
{
    return k * k;
}

LL BigMod(LL a, LL n, LL p)
{
    if(n == 1)  return a % p;
    else if(n % 2 == 0)  return square(BigMod(a, n/2, p)) % p;
    else return ((square(BigMod(a, n/2, p))%p)*(a % p)) % p;
}


LL arr[35001];


int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);
    LL n,k,mod;
    for (int kk=1;kase--;++kk){
        scanf("%lld %lld %lld",&n,&k,&mod);

        for (int i=0;i<n;++i){
            scanf("%lld",&arr[i]);
        }

        LL mul= ( BigMod( n,k,mod ) * k )%mod /n ;

        LL ans=0;
        for (int i=0;i<n;++i){
            ans=( ans+arr[i]*mul )%mod;
        }
        printf("Case %d: %lld\n",kk,ans);
    }
    return 0;
}
