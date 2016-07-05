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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 15

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


LL r[SIZE],p[SIZE];

LL overflowmod(LL a,LL b,LL c){
    LL x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}


int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        scanf("%d",&n);

        LL mul = 1;
        for (int i=0;i<n;++i){
            scanf("%lld %lld",&p[i],&r[i]);
            mul *= p[i];
        }
        LL ans = 0;
        for (int i=0;i<n;++i){
            ans=( ans+ r[i] * overflowmod ( ( mul/p[i] ) , BigMod( (mul/p[i])%p[i] ,p[i]-2,p[i] ) , mul ) )%mul;
        }
        printf("Case %d: %lld\n",kk,ans);

    }



    return 0;
}
