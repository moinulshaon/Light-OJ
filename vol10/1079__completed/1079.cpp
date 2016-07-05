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

int n;

double pp[110];
int money[110];

double lim;

double dp[10010];

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%lf %d",&lim,&n);

        int sum=0;
        for (int i=0;i<n;++i){
            scanf("%d %lf",&money[i],&pp[i]);
            sum+= money[i];
        }

        for (int i=0;i<=sum+1;++i){
            dp[i]= 1;
        }

        dp[0]=0;
        for (int i=0;i<n;++i){
            for (int j=sum;j>=0;--j){
                if ( j-money[i] >=0 ){
                    dp[j]= min( dp[j], dp[ j-money[i] ] + ( 1-dp[ j-money[i] ] )*pp[i]   );
                }
            }
        }

        int ans;
        for (int i=sum;i>=0;--i){
            if ( dp[i]<lim ){
                ans=i;
                break;
            }
            //printf("%lf\n",dp[i]);
        }

        printf("Case %d: %d\n",kk,ans);
    }

    return 0;
}
