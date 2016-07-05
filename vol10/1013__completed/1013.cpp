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

#define SIZE 32

char str1[SIZE],str2[SIZE];
int len1,len2;

LL dp[SIZE][SIZE];

LL func( int x,int y ){
    if ( x==0 || y ==0 )return 0;

    if ( dp[x][y]!= -1 )return dp[x][y];

    if ( str1[x]==str2[y] ){
        return dp[x][y]=1+func( x-1,y-1 );
    }else{
        return dp[x][y]=max( func( x-1,y ),func( x,y-1 ) );
    }
}

LL dp2[SIZE][SIZE];
LL func2( int x,int y ){
    if ( x==0 || y ==0 )return 1;

    if ( dp2[x][y]!= -1 )return dp2[x][y];

    if ( str1[x]==str2[y] ){
        return dp2[x][y]=func2( x-1,y-1 );
    }else{
        LL tmp=0;
        if ( func(x-1,y)>= func(x,y-1) )
            tmp+=func2( x-1,y ) ;
        if ( func(x,y-1)>= func(x-1,y) )
            tmp+=func2( x,y-1 ) ;
        return  dp2[x][y]=tmp;
    }
}

int main(){
    //FRO
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s %s",&str1[1],&str2[1]);

        len1=strlen(&str1[1]);
        len2=strlen(&str2[1]);

        NEG(dp);

        LL lcs=func( len1,len2 );

        NEG(dp2);
        LL ans=func2(len1,len2);
        printf("Case %d: %lld %lld\n",kk,len1+len2-lcs,ans);
    }


    return 0;
}
