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

#define SIZE 105

int mat[SIZE][SIZE];
int val[SIZE];

bool used[SIZE];

int gauss(int eqn,int var,int mod){

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
                int coef = 0;
                //coef= ( ( mod-mat[k][j]%mod )%mod*BigMod( mat[i][j],mod-2,mod ) ) %mod;
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

LL arr[SIZE];
int save[SIZE][SIZE];
int ss[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        LL mx = -100;
        for (int i=0;i<n;++i){
            scanf("%lld",&arr[i]);
            mx=max( mx, arr[i] );
        }

        int dim = -1;
        for (int i=63;i>=0;--i){
            if ( mx & ( 1LL<<i ) ){
                dim = i;
                //cout<<(1LL<<i)<<endl;
                break;
            }
        }
        //cout<<dim<<endl;
        printf("Case %d: ",kk);
        if ( dim == -1 ){
            printf("0\n");
            continue;
        }

        for (int i=0;i<n;++i){
            for (int j=0;j<=dim;++j){
                if ( arr[i] & (1LL<<(dim-j)) ){
                    save[j][i] = 1;
                }else{
                    save[j][i] = 0;
                }
            }
        }
        /*
        for (int i=0;i<=dim;++i){
            for (int j=0;j<n;++j){
                cout<<save[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        CLR(ss);
        for (int i=1;i<=dim+1;++i){

            for (int p=0;p<i;++p){
                for (int q=0;q<n;++q){
                    mat[p][q] =save[p][q];
                }
            }

            for (int p=0;p<i-1;++p){
                val[p] = ss[p];
            }
            val[i-1] = ss[i-1] = 1;
            if ( gauss( i,n,2 ) == -1 ){
                //val[i-1] = 0;
                ss[i-1] = 0;
                continue;
            }
            //cout<<(dim-i+1)<<endl;
        }

        LL ans = 0;
        for (int i=0;i<=dim;++i){
            if ( ss[i] ){
                ans |= (1LL<<(dim-i) );
            }
        }

        printf("%lld\n",ans);
    }


    return 0;
}
