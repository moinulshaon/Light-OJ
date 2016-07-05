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

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        double ans=1;
        int x=1;
        for (int i=1;i<n;++i){
            ans *= double(n-i)/n;
            if ( ans +1e-6  <.5){
                x=i;
                break;
            }
        }
        printf("Case %d: %d\n",kk,x);
    }


    return 0;
}
