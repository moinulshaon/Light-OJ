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

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

#define N 10000100

int status[(N/32)+2];
LL p[N/10];
void sieve(){
     int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 ){
         if( Check(status[i>>5],i&31)==0){
             for( j = i*i; j <= N; j += (i<<1) ){
                 status[j>>5]=Set(status[j>>5],j & 31)   ;
             }
         }
     }
     int cnt = 0;
     p[cnt++] = 2;
     for(i=3;i<=N;i+=2)
         if( Check(status[i>>5],i&31)==0)
            p[cnt++] = i;
}

int main(){

    sieve();

    int kase;
    scanf("%d",&kase);

    LL x;
    for (int kk=1;kase--;++kk){
        scanf("%lld",&x);
        LL ans = 1;
        int tmp ;

        for (int i=0;p[i]*p[i]<= x;++i){
            if ( x %p[i] == 0 ){
                tmp = 0;
                while ( x%p[i] == 0 ){
                    x/=p[i];
                    tmp++;
                }
                ans = ans * ( 2LL * (tmp+1) -1 );
            }
        }
        if ( x != 1 ){
            ans = ans * 3;
        }

        printf("Case %d: %lld\n",kk,(ans+1)/2  );
    }


    return 0;
}
