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

LL dp[20];

LL shaon( int s ){
    //cout<<"saon "<<s<<endl;
    if ( s<=0 )return 1;

    LL &ret = dp[s];
    if ( ret!= -1 )return ret;

    ret = 1;

    for (int i=0;i<s; i+=2 ){
        ret= ret*10;
    }
    return ret;
}

LL func( LL x ){

    if ( x<0 )return 0;
    else if ( x==0 )return 1;

    char tmp[20];
    sprintf(tmp,"%lld",x);
    int len=strlen(tmp);

    LL ans = 0;


    int back=len-1;
    int lim = tmp[0]-'0';

    for (int i=0;i<len; i++ ){

        if ( i>0 ){
            for (int j=1;j<lim;++j){
                ans+= shaon( len-i-2 );
            }
        }


        if ( i==0  ){
            if ( tmp[back]>=tmp[0] )
                ans+= (tmp[0]-'0')*shaon( len-2 );
            else {
                ans+= min( (tmp[0]-'0'),tmp[back]-'0' )*shaon( len-2 );
            }
        }

        lim = 10;
        //cout<<ans<<endl;
    }
    return ans+1;
}

int main(){

    FRO

    NEG(dp);
    //cout<<func(100)<<endl;


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL a,b;
        scanf("%lld %lld",&a,&b);

        if ( b<a )swap( a,b );

        printf("Case %d: %lld\n",kk,func(b)-func(a-1));
    }



    return 0;
}
