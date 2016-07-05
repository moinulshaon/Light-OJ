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

LL extendedgcd(LL a,LL b){
    LL div,temp,x0=1,x1=0,y0=0,y1=1;
    while (b!=0){
        div=a/b;
        temp=a;
        a=b;
        b=temp%b;

        temp=x1;
        x1=x0-div*x1;
        x0=temp;

        temp=y1;
        y1=y0-div*y1;
        y0=temp;
    }
    return x0;
}

LL inverse(LL x , int m ){
    return ( extendedgcd( x,m )%m +m )%m;
}

#define SIZE 1100
bool prime[SIZE];
vector<int> pr;

vector<pint> factorize(int x){
    vector<pint> ret ;
    for (int i=0;pr[i]*pr[i]<=x;++i){
        if ( x%pr[i] == 0 ){
            int cnt = 0;
            while ( x%pr[i] == 0 ){
                cnt++;
                x/=pr[i];
            }
            ret.PB( MP(pr[i],cnt) );
        }
    }
    if ( x != 1 ){
        ret.PB( MP(x,1) );
    }
    return ret;
}

void pre(){
    for (int i=2;i<SIZE;++i){
        prime[i] = true;
    }
    for (int i=2;i*i<=SIZE;++i){
        if ( prime[i] ){
            for (int j=i+i;j<SIZE;j+=i){
                prime[j] = false;
            }
        }
    }
    for (int i=0;i<SIZE;++i){
        if ( prime[i] ){
            pr.PB( i );
        }
    }
}

LL calc( LL n,int pe, int p ){

    if ( n == 0 )return 1;

    LL car = 1;
    LL save = 1;
    for (int i=1;i<=pe;++i){
        if ( i%p != 0 )car = ( car * i )%pe;
        if ( n%pe == i )save = car;
    }

    LL ret = ( BigMod( car,n/pe,pe ) * save )%pe;
    ret = ( ret * calc( n/p,pe,p ) )%pe;

    return ret;
}

LL ncr(LL n,LL r,int pe,int p){

    LL num = calc( n,pe,p );
    LL den = ( calc( n-r,pe,p ) * calc( r,pe,p ) )%pe;

    return ( num* inverse( den,pe ) )%pe;
}

LL recur(LL n,LL x){
    if ( n == 0 )return 0;
    else return n/x + recur(n/x,x);
}

LL solve(LL n , LL r ,int pe,int p){
    LL ret = BigMod( p , recur(n,p)-recur(n-r,p)-recur(r,p) , pe );
    ret = ( ret * ncr( n,r,pe,p ) )%pe;
    return ret;
}


LL crt( vector<int> base,vector<int> rem,LL mul ){
    LL ans = 0;
    for (int i=0;i<base.size();++i){
        ans += rem[i] * ( ( mul/base[i] ) * inverse( (mul/base[i])%base[i] ,base[i] ) )%mul;
        ans%=mul;
    }
    return ans;
}


LL shaon( LL n,LL r,int m ){
    vector<pint> fff =factorize(m);
    int s= fff.size();
    vector<int> mul(s);
    for (int i=0;i<s;++i){
        mul[i] = 1;
        for (int j=0;j<fff[i].Y;++j){
            mul[i] *= fff[i].X;
        }
    }
    vector<int> rem(s);
    for (int i=0;i<s;++i){
        rem[i] = solve( n,r,mul[i],fff[i].X);
        //show( mul[i],rem[i] );
    }
    return crt(mul,rem,m);
}

int main(){

    FRO

    pre();

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        LL K,L,M;

        scanf("%d %lld %lld %lld",&n,&K,&L,&M);

        printf("Case %d: ",kk);

        LL ans;
        if ( M == 0 ){
            ans = BigMod( K,L,n );
        }else{
            n = n*2;
            ans = shaon( L,M,n );
            ans = ( ans * BigMod( K,L,n ) )%n;
            ans = ( ans * BigMod( K-1,M,n ) )%n;
            ans/= 2;
        }

        printf("%lld\n",ans+1);
    }


    return 0;
}
