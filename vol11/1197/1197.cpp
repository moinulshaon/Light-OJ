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

#define SIZE 100100

bool segment[SIZE];

vector<LL> p;

int segmented_sieve(LL a, LL b){
    int cnt = (a<=2 && 2<=b)? 1 : 0;
    if(b<2) return 0;
    if(a<3) a = 3;
    if(a%2==0) a++;
    CLR(segment);
    for(int i=0; p[i]*p[i] <= b; i++) {
        LL j = p[i] * ( (a+p[i]-1) / p[i] );
        if(j%2==0) j += p[i];
        for(LL k=p[i]<<1; j<=b; j+=k){
            if(j!=p[i]) {
                segment[j-a]=true;
            }
        }
    }
    for(int i=0; i<=b-a; i+=2){
        if(!segment[i]){
            cnt++;
        }
    }
    return cnt;
}

bool prime[47000];

int main(){

    for (int i=2;i<=217;++i){
        if ( !prime[i] ){
            for (int j=i+i;j<47000;j+=i){
                prime[j] = true;
            }
        }
    }

    for ( int i=2;i<50000;++i ){
        if ( !prime[i] ){
            p.PB( i );
        }
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int a,b;
        scanf("%d %d",&a,&b);

        printf("Case %d: %d\n",kk,segmented_sieve( a,b ) );
    }


    return 0;
}
