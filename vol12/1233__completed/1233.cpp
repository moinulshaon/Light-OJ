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


bool dp[100010];
int use[100010];
int coin[102],cnt[102];
int n,target;


int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&target);

        for (int i=1;i<=n;++i){
            scanf("%d",&coin[i]);
        }
        for (int i=1;i<=n;++i){
            scanf("%d",&cnt[i]);
        }

        CLR(dp);
        dp[0]=true;

        int ans=0;
        for (int i=1;i<=n;++i){
            CLR(use);
            for (int j=1;j<=target;++j){
                if ( j-coin[i]>=0 && dp[ j-coin[i] ] && !dp[j] && use[ j-coin[i] ] < cnt[i]  ){
                    dp[j]=true;
                    use[j]=use[ j-coin[i] ]+1;
                    ++ans;
                }
            }
        }
        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
