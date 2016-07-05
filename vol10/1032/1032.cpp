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

#define SIZE 100

int dp[10][SIZE];

int shaon(int left,int prv){

    if ( left ==0 ){
        return 0;
    }

    int &ret=dp[left][prv];

    if ( ret != -1 )return ret;

    ret = 0;
    for (int i=0;i<2;++i){
        ret+= shaon( left-1,i );
    }
    if ( prv==1 )ret++;
    return ret;
}

LL func( int x ){

    if ( x==0 )return 0;

    char str[35];
    int len=0;

    while ( x!=0 ){
        if ( x&1 ){
            str[len++]='1';
        }else{
            str[len++]='0';
        }
        x>>=1;
    }
    reverse( str,str+len );
    str[len]='\0';

    //printf("%s\n",str);



    LL ans = 0;
    int prv=0;

    LL cnt =0;
    for (int i=0;i<len;++i){
        int left = len-i;

        int lim = str[i]-'0';
        if ( lim==1 ){
            ans+= shaon( left-1, 0 );
            ans+=
        }else{

        }

        if ( prv==1 ){
            cnt++;
        }

        prv= lim;
    }
    return ans;
}


int main(){




    return 0;
}
