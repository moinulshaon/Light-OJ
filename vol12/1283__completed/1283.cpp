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

#define SIZE 105

int dp[SIZE][SIZE][SIZE];
int n;
int arr[SIZE],tmp[SIZE];

int func( int totake,int le,int ri ){

    if (le>ri){
        return -(1<<29);
    }
    if ( totake == n ){
        return 0;
    }

    int &ret = dp[totake][le][ri];
    if ( ret != -1 )return ret;

    ret = func( totake+1,le,ri );
    if ( arr[totake] >= le ){
        ret= max( ret , 1+func( totake+1,arr[totake],ri ) );
    }
    if ( arr[totake] <= ri ){
        ret= max( ret , 1+func( totake+1,le,arr[totake] ) );
    }
    return ret;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            tmp[i] = arr[i];
        }
        map<int,int> mp;
        sort( tmp,tmp+n );
        int cnt = 1;
        for (int i=0;i<n;++i){
            if ( mp.find( tmp[i] )== mp.end() )
                mp[ tmp[i] ] = cnt++;
        }
        cnt++;

        for (int i=0;i<n;++i){
            arr[i] = mp[ arr[i] ];
            //cout<<arr[i]<<endl;
        }
        //cout<<cnt<<endl;

        for (int i=0;i<n;++i){
            for (int j=0;j<=cnt;++j){
                for (int k=0;k<=cnt;++k){
                    dp[ i ][ j ][ k ] = -1;
                }
            }
        }


        printf("Case %d: %d\n",kk,func( 0,0,cnt ));
    }


    return 0;
}
