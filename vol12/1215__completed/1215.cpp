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

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

#define N 1000100

vector<LL> pp;

int status[(N/32)+2];
void sieve()
{
     int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
         if( Check(status[i>>5],i&31)==0)
         {
             for( j = i*i; j <= N; j += (i<<1) )
             {
                 status[j>>5]=Set(status[j>>5],j & 31)   ;
             }
         }
     }

     pp.PB(2);
     for(i=3;i<=N;i+=2)
         if( Check(status[i>>5],i&31)==0)
            pp.PB(i);
}

void func( LL x,map<LL,int>& mp ){

    for (int i=0;pp[i]*pp[i]<=x;++i){
        if ( x%pp[i] == 0 ){
            int cnt=0;
            while ( x%pp[i] == 0 ){
                x/=pp[i];
                cnt++;
            }
            mp[ pp[i] ]=cnt;
        }
    }
    if (  x!= 1 )mp[ x ]=1;
}
map<LL,int> mpa,mpb;

LL ff(LL x){
    LL ans=1;
    for (int i=0;pp[i]*pp[i]<=x;++i){
        if ( x%pp[i] == 0 ){
            int cnt=0;
            while ( x%pp[i] == 0 ){
                x/=pp[i];
                cnt++;
            }
            int save= max( mpa[ pp[i] ],mpb[ pp[i] ] );
            if ( cnt< save ){
                return -1;
            }else if ( cnt>save ){
                ans*=LL( pow( pp[i], cnt )+1e-6 );
            }

            mpa[ pp[i] ]-= save;
            mpb[ pp[i] ]-= save;
        }
    }
    if (  x!= 1 ){
        int save=max( mpa[ x ],mpb[ x ] );
        if ( 1< save ){
            return -1;
        }else if ( 1>save ){
            ans*=LL( pow( x, 1 )+1e-6 );
        }

        mpa[ x ]-= save;
        mpb[ x ]-= save;
    }

    for (map<LL,int>::iterator it=mpa.begin();it!=mpa.end();++it){
        if ( it->second >0 ){
            return -1;
        }
    }
    for (map<LL,int>::iterator it=mpb.begin();it!=mpb.end();++it){
        if ( it->second >0 ){
            return -1;
        }
    }

    return ans;
}

int main(){
    FRO

    sieve();

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL a,b,lcm;
        scanf("%lld %lld %lld",&a,&b,&lcm);

        mpa.clear();
        mpb.clear();

        func( a,mpa );
        func( b,mpb );

        LL ans=ff(lcm);

        if ( ans == -1 ){
            printf("Case %d: impossible\n",kk);
        }else{
            printf("Case %d: %lld\n",kk,ans);
        }

    }


    return 0;
}
