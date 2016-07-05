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

#define SIZE 100010

int arr[SIZE];

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        mint mp;
        bool pos=true;
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            if ( arr[i] >= n )pos=false;
            if ( pos ){
                mp[ arr[i] ]++;
                mp[ n-arr[i]-1 ]++;
            }
        }



        for (int i=0;i<n && pos ;++i){
            if ( mp[i] != 2  ){
                pos=false;
                //printf("ss %d\n",i);
            }
        }

        if ( pos )
            printf("Case %d: yes\n",kk);
        else{
            printf("Case %d: no\n",kk);
        }
    }


    return 0;
}
