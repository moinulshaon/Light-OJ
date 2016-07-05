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

#define CLR(arr) memset( (arr),0,SIZEof(arr) );
#define NEG(arr) memset( (arr),-1,SIZEof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 1000010


int phi[SIZE];
int ans[SIZE];
bool prime[SIZE];
int rev[SIZE];

int main(){

    for (int i=2;i<SIZE;++i){
        prime[i]=true;
        phi[i]=i;
    }
    phi[1]=0;
    for (int i=2;i<SIZE;++i){
        if (prime[i]){
            phi[i]=i-1;
            for (int j=i*2;j<SIZE;j+=i){
                prime[j]=false;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }

    for (int i=0;i<SIZE;++i){
        rev[i] = INT_MAX;
    }

    ans[SIZE-1] = INT_MAX;
    for (int i=SIZE-2;i>0;--i){
        rev[ phi[i] ] = min( rev[ phi[i] ]  , i );
        ans[i] = min( ans[i+1], rev[i] );
    }


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int tmp,n;
        scanf("%d",&n);

        LL sum = 0;
        while ( n-- ){
            scanf("%d",&tmp);
            sum += ans[tmp];
        }
        printf("Case %d: %lld Xukha\n",kk,sum);
    }



    return 0;
}
