#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}

typedef long long LL;
#define SIZE 66000

bool prime[SIZE];
vector<LL> pp;

vector<LL> rr;
vector<LL> cnt;
LL n,m;

void div( LL x ){

    for (int i=0;x!=1 && i<pp.size() && pp[i]*pp[i]<=x;++i){
        LL count=0;
        while (x%pp[i]==0){
            x/=pp[i];
            ++count;
        }
        if ( count ){
            rr.push_back(pp[i]);
            cnt.push_back(count*m);
        }
    }
    if ( x!=1 ){
        rr.push_back(x);
        cnt.push_back(m);
    }
}



LL square(LL k)
{
    return k * k;
}

const LL mod=1000000007;

LL BigMod(LL a, LL n){
    if(n == 1)  return a % mod;
    else if(n % 2 == 0)  return square(BigMod(a, n/2)) % mod;
    else return ((square(BigMod(a, n/2))%mod)*(a % mod)) % mod;
}


int main(){
    freopen("in.txt","r",stdin);

    for (int i=2;i<SIZE;++i){
        prime[i]=true;
    }

    for (int i=2;i<=256;++i){
        if ( prime[i] ){
            for (int j=2*i;j<SIZE;j+=i){
               prime[j]=false;
            }
        }
    }
    for (int i=0;i<SIZE;++i){
        if ( prime[i] ){
            pp.push_back(i);
        }
    }

    int kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        n=fastIn<LL>();
        m=fastIn<LL>();

        rr.clear();
        cnt.clear();

        div(n);

        LL num=1;

        for (int i=0;i<rr.size();++i){
            num=( num * ( BigMod(rr[i],cnt[i]+1 )-1  ) )%mod;
        }

        LL den=1;
        for (int i=0;i<rr.size();++i){
            den=( den * ( rr[i]-1  ) )%mod;
        }
        //printf("%lld\n",num);
        num=( num* BigMod(den,mod-2) )%mod;
        if ( num<0 ){
            num+=mod;
        }

        printf("Case %d: %lld\n",kk,num);

    }
    return 0;
}
