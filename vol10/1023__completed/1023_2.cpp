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

char arr[26];

int main(){

    for (int i=0;i<26;++i){
        arr[i]='A'+i;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,k;
        scanf("%d %d",&n,&k);

        sort( arr,arr+26);
        printf("Case %d:\n",kk);
        int cnt=1;
        do{
            printf("%d  ",cnt++);
            for (int i=0;i<n;++i){
                putchar(arr[i]);
            }
            putchar('\n');
        }while( --k && next_permutation( arr,arr+n ) );
    }

    return 0;
}
