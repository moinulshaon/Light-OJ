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

#define SIZE 100000100

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

typedef unsigned shaon;
shaon status[5800000];
shaon p[5800000];
int sz = 0;
void sieve()
{
     int i, j, sqrtN;
     sqrtN = int( sqrt( SIZE ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
         if( Check(status[i>>5],i&31)==0)
         {
             for( j = i*i; j < SIZE; j += (i<<1) )
             {
                 status[j>>5]=Set(status[j>>5],j & 31)   ;
             }
         }
     }

     p[sz++]=2;
     for(i=3;i<SIZE;i+=2)
         if( Check(status[i>>5],i&31)==0)
            p[sz++]=i;
}





int main(){

    FRO

    sieve();

    //cout<<p.size()<<endl;
    status[0]=2;
    for (int i=1;i<5800000;++i){
        status[i]= status[i-1]* p[i];
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL n;
        scanf("%lld",&n);

        shaon ans=1;

        for (int i=0;LL(p[i])*p[i]<=n;++i){
            LL tmp=LL(p[i])*p[i];
            while ( tmp<= n ){
                tmp*=p[i];
                ans= ans*p[i];
            }
        }

        //cout<<ans<<endl;

        int low=0,high=sz-1;

        while ( low<=high ){
            int mid= (low+high)/2;

            if ( p[mid] > n ){
                high= mid-1;
            }else{
                low=mid+1;
            }
        }



        printf("Case %d: %u\n",kk,ans*status[low-1]);

    }

    return 0;
}
