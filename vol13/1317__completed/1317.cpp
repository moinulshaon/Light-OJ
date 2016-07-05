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
    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        int n,m,k;
        double p;
        scanf("%d %d %d %lf",&n,&m,&k,&p);
        double ans=0;
        for (int i=1;i<=k;++i){
            ans+= n*p;
        }
        printf("Case %d: %.8lf\n",kk,ans);
    }
    return 0;
}
