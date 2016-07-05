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

#define SIZE 102
#define MP make_pair
#define X first
#define Y second

int mid;
char dp[SIZE][SIZE][SIZE];
int n;

pint arr[SIZE];

char func( int totake,int havea,int haveb ){

    if ( havea<0 )havea=0;
    if ( haveb<0 )haveb=0;

    if ( havea==0 && haveb == 0 ){
        return 1;
    }
    if ( totake == n ){
        return 0;
    }
    char &ret = dp[totake][havea][haveb];
    if ( ret != -1 )return ret;

    for ( int i=0;i<=havea && arr[totake].X*i <= mid ;++i ){
        if ( func( totake+1 , havea-i,haveb- ( (mid-arr[totake].X*i)/arr[totake].Y ) ) >0 ){
            return ret = 1;
        }
    }
    return ret = 0;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    int m;
    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&m);

        for (int i=0;i<n;++i){
            scanf("%d %d",&arr[i].X,&arr[i].Y);
        }

        int low=0,high=51000;
        int ans= -1;

        while( low<=high ){
            mid=(low+high)/2;
            for (int i=0;i<n;++i){
                for (int j=0;j<=m;++j){
                    for (int k=0;k<=m;++k){
                        dp[i][j][k] = -1;
                    }
                }
            }
            if ( func(0,m,m) >0 ){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
