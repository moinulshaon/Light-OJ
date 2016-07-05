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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

long long square(long long k){
    return k * k;
}

long long BigMod(long long a, long long n, long long p){
    if ( n==0 )return 1;
    else if(n == 1)  return a % p;
    else if(n % 2 == 0)  return square(BigMod(a, n/2, p)) % p;
    else return ((square(BigMod(a, n/2, p))%p)*(a % p)) % p;
}

int base,k;
char arr[25];
int len;
map<int,int> mp;
LL dp[1<<17][21];

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}


LL func( int state,int rem ,int taken){

    if ( state== (1<<len)-1 )return rem==0;

    if ( dp[state][rem] != -1 )return dp[state][rem];

    LL tmp=0;


    for (int i=0;i<len;++i){
        if ( Check(state,i)==0 ){
            tmp+= func( Set( state,i ),( rem+mp[ arr[i] ]*BigMod( base,taken,k ) )%k,taken+1 );
        }
    }
    return dp[state][rem]=tmp;
}

int main(){
    FRO

    for (char cc='0';cc<='9';++cc){
        mp[cc]=cc-'0';
    }
    for (char cc='A';cc<='F';++cc){
        mp[cc]=cc-'A'+10;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&base,&k);
        scanf("%s",arr);
        len=strlen(arr);

        for (int i=0;i<(1<<len);++i){
            for (int j=0;j<k;++j){
                dp[i][j]=-1;
            }
        }

        LL ans= func( 0,0 ,0 );

        printf("Case %d: %lld\n",kk,ans);
    }

    return 0;
}
