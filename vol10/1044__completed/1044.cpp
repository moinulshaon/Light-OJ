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

#define SIZE 1010

char arr[SIZE];
char ispal[SIZE][SIZE];
int len;

int dp[SIZE];

char ff( int left,int right ){
    if ( left>right )return 1;

    if ( ispal[left][right] != -1 )return ispal[left][right];

    if ( arr[left]==arr[right] )return ispal[left][right]=ff( left+1,right-1 );
    else return ispal[left][right]=0;
}

int func( int ind ){
    if ( ind<0 )return 0;
    if ( dp[ind] != -1 )return dp[ind];

    int ans=func(ind-1)+1;

    for (int i=0;i<=ind;++i){
        if ( ff( i,ind )  ){
            ans=min( ans,  func( i-1 )+ 1 );
        }
    }
    return dp[ind] = ans;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%s",arr);
        len=strlen(arr);

        NEG(dp);
        for (int i=0;i<len;++i){
            for (int j=0;j<len;++j){
                ispal[i][j]= -1;
            }
        }

        printf("Case %d: %d\n",kk,func( len-1 ));
    }

    return 0;
}
