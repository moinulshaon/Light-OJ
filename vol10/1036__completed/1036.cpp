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

#define SIZE 510

int ur[SIZE][SIZE];
int rad[SIZE][SIZE];
int row,col;

int dp[SIZE][SIZE];

int func( int cc,int rr ){
    if ( cc>col )return 0;

    if ( dp[cc][rr] != -1 )return dp[cc][rr];

    int tt=0;
    for (int i=rr;i<=row;++i){
        tt=max( tt, rad[i][cc]-rad[0][cc] +  ur[row][cc]-ur[i][cc] +func( cc+1,i ) );
    }
    return dp[cc][rr]=tt;
}

int main(){
    FRO
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&row,&col);

        for (int i=0;i<=row;++i){
            ur[i][0]=0;
            rad[i][0]=0;
        }
        for (int i=0;i<=col;++i){
            ur[0][i]=0;
            rad[0][i]=0;
        }

        for (int i=1;i<=row;++i){
            for (int j=1;j<=col;++j){
                scanf("%d",&ur[i][j]);
                ur[i][j]+= ur[i-1][j] ;
            }
        }

        for (int i=1;i<=row;++i){
            for (int j=1;j<=col;++j){
                scanf("%d",&rad[i][j]);
                rad[i][j]+= rad[i-1][j] ;
            }
        }

        NEG(dp);

        int  ans=func( 1,0 );
        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
