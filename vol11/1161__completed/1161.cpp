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



#define SIZE 10005
int cnt[SIZE];
int arr[SIZE];

bool prime[SIZE];

vector<int> p;

void calc( int x,vector<int>&v ){
    for (int i=0;p[i]*p[i]<=x;++i){
        if ( x %p[i] == 0 ){
            v.PB( p[i] );
            while ( x%p[i] == 0 )
                x/= p[i];
        }
    }
    if ( x != 1 )v.PB( x );
}

LL ncr(int n,int r){
    if ( r >n )return 0;
    LL ret = 1;
    for (int i=0;i<r;++i){
        ret = ret * (n-i) / (i+1);
    }
    return ret;
}

int main(){

    FRO

    for (int i=2;i<SIZE;++i){
        prime[i] = true;
    }
    for (int i=2;i*i<=SIZE;++i){
        if ( prime[i] ){
            for (int j=i+i;j<SIZE;j+=i){
                prime[j]=false;
            }
        }
    }

    for (int i=2;i<SIZE;++i){
        if ( prime[i] ){
            p.PB( i );
        }
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        CLR(cnt);

        for (int i=0;i<n;++i){
            vector<int> fac;
            calc( arr[i],fac );
            int b = fac.size();

            for (int state=1;state<(1<<b);++state){
                int tmp = 1;
                for (int j=0;j<b;++j){
                    if ( state & (1<<j) ){
                        tmp*= fac[j];
                    }
                }
                cnt[ tmp ]++;
            }
        }
/*
        for (int i=0;i<10;++i){
            cout<<i<<" "<<cnt[i]<<endl;
        }cout<<endl;
*/
        LL ans = ncr(n,4);
        LL sum = 0;

        for (int i=0;i<n;++i){
            vector<int> fac;
            calc( arr[i],fac );
            int b = fac.size();



            LL shaon = 0;

            for (int state=1;state<(1<<b);++state){
                int tmp = 1;
                int ccc = 0;
                for (int j=0;j<b;++j){
                    if ( state & (1<<j) ){
                        tmp*= fac[j];
                        ccc ++;
                    }
                }


                if ( ccc &1 )
                    shaon += ncr( cnt[tmp]-1 , 3 );
                else
                    shaon-= ncr( cnt[tmp]-1 , 3 );
            }
            //cout<<arr[i]<<" "<<shaon<<endl;
            sum += shaon;
        }


        //cout<<ans<<" x "<<sum<<endl;
        sum /= 4;

        ans = ans - sum;

        printf("Case %d: %lld\n",kk,ans);

    }

    return 0;
}
