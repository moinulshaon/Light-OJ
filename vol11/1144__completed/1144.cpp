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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 1000001

bool prime[SIZE];
int dp[SIZE];
int max_prime[SIZE];
int mul[SIZE];

int fact[10];

int main(){

    FRO

    for (int i=2;i<SIZE;++i){
        prime[i]=true;
        mul[i] = 1;
    }

    for (int i=2;i<SIZE;++i){
        if ( prime[i] ){
            mul[i] = i;
            max_prime[i] = i;

            for (int j=i+i;j<SIZE;j+=i){
                prime[j]=false;
                mul[j] *= i;
                max_prime[j] = i;
            }
        }
    }


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m;
        scanf("%d %d",&n,&m);

        if ( m<n )swap( n,m );

        printf("Case %d: ",kk);

        if ( n == 0 && m == 0 ){
            printf("0\n");
            continue;
        }else if ( n == 0 ){
            printf("1\n");
            continue;
        }

        LL ans = 2;

        int len;
        for (int i=1;i<=n;++i){

            if ( mul[i] != i ){
                dp[i] = dp[ mul[i] ];
            }else{
                dp[i] = 0;
                len = 0;
                for ( int tmp=i ; tmp!= 1 ;tmp /= max_prime[tmp] ){
                    fact[len++] = max_prime[tmp];
                }

                for (int state = 1;state<(1<<len);++state){
                    int tmp = 1,cnt = 0;
                    for (int j=0;j<len;++j){
                        if ( state & (1<<j) ){
                            tmp *= fact[j];
                            cnt++;
                        }
                    }
                    if ( cnt &1  ){
                        dp[i] += m/tmp;
                    }else{
                        dp[i] -= m/tmp;
                    }
                }
/*
                cout<<i<<" "<<dp[i]<<endl;
                for (int j=0;j<len;++j){
                    cout<<fact[j]<<" ";
                }cout<<endl;
*/
            }
            //cout<<i<<" "<<dp[i]<<endl;
            ans += m-dp[i];
        }
        printf("%lld\n",ans);
    }

    return 0;
}
