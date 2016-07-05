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

#define SIZE 1001

double dp[SIZE][SIZE];
bool vis[SIZE][SIZE];


double func( int t,int d  ){

    if ( t<0 ||d <0 )return 0;
    if ( t==0 )return 1;


    if ( vis[t][d] )return dp[t][d];


    dp[t][d] =  2 * t * d* func( t ,d-1) +  t*(t-1) * func( t-2,d ) + 2*d* func( t,d-1 );
    dp[t][d] /= double ( t+d )*(t+d+1)- double (d)*(d-1);

    vis[t][d]=true;
    return dp[t][d];
}

int main(){

    for (int i=1;i<SIZE;++i){
        for (int j=1;j<SIZE;++j){
            func(i,j);
        }
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int t,d;
        scanf("%d %d",&t,&d);
        printf("Case %d: %.8lf\n",kk,func(t,d));
    }


    return 0;
}
