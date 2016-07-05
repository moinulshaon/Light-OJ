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

const int mod=100000007;

int nxt[15002];
int now[15002];

int k;

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,s;
        scanf("%d %d %d",&n,&k,&s);

        CLR(now);
        now[0]=1;

        for (int i=0;i<=n;++i){

            if ( i ){
                for (int j=0;j<=s;++j){
                    now[j]=nxt[j];
                }
            }

            for (int j=1;j<=s;++j){
                nxt[j]= ( nxt[j-1]+now[j-1]-( (j-k-1>=0) ? now[j-k-1]:0 ) )%mod;
            }

        }

        if(  now[s]<0 )now[s]+=mod;
        printf("Case %d: %d\n",kk,now[s]);
    }


    return 0;
}
