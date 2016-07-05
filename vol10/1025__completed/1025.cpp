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

char arr[62];
LL dp[62][62];

LL func( int left,int right ){
    if ( left>right )return 1;
    //if ( left==right )return 1;

    if ( dp[left][right] != -1 )return dp[left][right];

    LL tmp=0;
    tmp+= func(left+1,right);
    tmp+= func(left,right-1);
    tmp -= func(left+1,right-1);
    if ( arr[left]==arr[right] )tmp+= func(left+1,right-1);

    return dp[left][right]=tmp;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%s",arr);

        NEG(dp);

        printf("Case %d: %lld\n",kk,func(0,strlen(arr)-1)-1);
        /*
        for (int i=0;i<strlen(arr);++i){
            for (int j=0;j<strlen(arr);++j){
                printf("%3d",dp[i][j]);
            }
            printf("\n");
        }
        */
    }


    return 0;
}
