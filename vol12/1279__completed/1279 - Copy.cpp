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

typedef pair<int,int> pint;
typedef map<int,int> mint;

long long BigMod ( long long a, long long p, long long m ){
    long long res = 1;
    long long x = a;

    while ( p>0 ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res % m;
}


#define SIZE 105

int mat[SIZE][SIZE];
int val[SIZE];

bool used[SIZE];

int gauss(int eqn,int var,LL mod){

    CLR(used);
    int rank= 0;
    for (int j=0;j<var;++j){
        int i = 0;
        while ( ( i<eqn ) && (used[i] || (mat[i][j] == 0) ) ) {
            i++;
        }
        if(i == eqn) continue;
        rank++;
        used[i] = true;
        for (int k=0; k<eqn; k++){
            if(!used[k]){
                LL coef = 0;
                coef= ( ( mod-mat[k][j]%mod )%mod*BigMod( mat[i][j],mod-2,mod ) ) %mod;
                while ( (mat[i][j] * coef + mat[k][j]) % mod != 0) {
                    coef++;
                }


                for (int l=0; l<var; l++) {
                    mat[k][l] = (mat[k][l] + mat[i][l] * coef) % mod;
                }
                val[k] = (val[k] + val[i] * coef) % mod;
            }
        }
    }
    for (int i=0; i<eqn; i++) {
         if(!used[i] && val[i] != 0) {
              return -1;
         }
    }
    return rank;
}

vector<int> out[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int v,e,k;
        scanf("%d %d %d",&v,&e,&k);

        for (int i=0;i<v;++i){
            for (int j=0;j<v;++j){
                mat[i][j] = 0;
            }
            val[i]= 0;
            out[i].clear();
        }

        int x,y;
        while ( e-- ){
            scanf("%d %d",&x,&y);
            out[x-1].PB( y-1 );
            out[y-1].PB( x-1 );
        }

        for (int i=0;i<v;++i){
            mat[i][i] = 1;
            for (int j=0;j<out[i].size();++j){
                mat[i][ out[i][j] ] = -1;
            }
        }

        int rank= gauss( v,v,k );

        printf("Case %d: ",kk);

        if ( rank == -1 ){
            printf("0\n");
        }else{
            printf("%lld\n",BigMod( k,v-rank,1000000007 ));
        }

    }

    return 0;
}
