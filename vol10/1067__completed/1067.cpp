#include <cstdio>
#include <cmath>

using namespace std;


long long square(long long k)
{
    return k * k;
}

long long BigMod(long long a, long long n, long long p)
{
    if(n == 1)  return a % p;
    else if(n % 2 == 0)  return square(BigMod(a, n/2, p)) % p;
    else return ((square(BigMod(a, n/2, p))%p)*(a % p)) % p;
}

const int mmm=1000003;

#define sz 1000001

long long factorial[sz];
long long inverseFac[sz];

int main(){

    factorial[0]=1;
    for (int i=1;i<sz;++i){
        factorial[i]=(factorial[i-1]*i)%mmm;
    }
    inverseFac[0]=1;
    for (int i=1;i<sz;++i){
        inverseFac[i]=( inverseFac[i-1]  *BigMod( i,mmm-2,mmm ) )%mmm;
    }
    int kase;
    scanf("%d",&kase);
    int a,b;
    for (int kk=1;kase--;++kk){
        scanf("%d %d",&a,&b);

        printf("Case %d: %lld\n",kk,( factorial[a]*inverseFac[b]*inverseFac[a-b] )%mmm  );


    }
    return 0;

}
