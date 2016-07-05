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

char str[12];

LL dp[1<<10][1010];
int n;
int d;

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}


LL func( int state,int r ){
    if ( state== (1<<n)-1 ){
        return r==0;
    }

    LL &ret = dp[state][r];
    if ( ret != -1 )return ret;

    ret = 0;
    for (int i=0;i<n;++i){
        if ( Check(state,i) == 0 ){
            ret += func( Set(state,i) , (10*r+str[i]-'0')%d );
        }
    }
    return ret;

}

LL fact[15];

int main(){

    FRO

    fact[0]=1;
    for (int i=1;i<15;++i){
        fact[i] = fact[i-1]*i;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s %d",str,&d);
        n = strlen(str);

        for (int i=0;i<(1<<n);++i){
            for (int j=0;j<d;++j){
                dp[i][j] = -1;
            }
        }


        LL ans = func(0,0);

        int cnt[12]={0};
        for (int i=0;i<n;++i){
            cnt[ str[i]-'0' ]++;
        }
        for (int i=0;i<10;++i){
            if ( cnt[i] >1 ){
                ans /= fact[ cnt[i] ];
            }
        }

        printf("Case %d: %lld\n",kk,ans);

    }


    return 0;
}
