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

#define SIZE 2005

int arr[SIZE];
int n;

int bsearch( int x,int lim ){
    int low = lim,high= n-1;

    while ( low<=high ){
        int mid = (low+high)/2;
        if ( arr[mid]<x ){
            low= mid+1;
        }else{
            high= mid-1;
        }
    }
    //cout<<low<<" "<<lim<<endl;
    return low-lim;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);

        int ans = 0;

        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                ans+= bsearch( arr[i]+arr[j] , j+1 );
                //cout<<i<<" "<<j<<" "<<bsearch( arr[i]+arr[j],j+1 )<<endl;
            }
        }

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
