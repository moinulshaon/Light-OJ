#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define DIM 2

int xx[DIM][DIM],rr[DIM][DIM],zz[DIM][DIM];
int mod;

void multiply(int a[DIM][DIM], int b[DIM][DIM],int lim) {

    memset(zz,0,sizeof(zz));

    for (int i = 0; i < lim; i++)
        for (int j = 0; j < lim; j++)
            for (int k = 0; k < lim ; k++) //col of A and row of B must be same which is equal to a[i].size()
                zz[i][j] = ( zz[i][j] + ( ( (a[i][k] % mod ) * (b[k][j] % mod))) % mod ) %mod;
    memcpy(a,zz,sizeof(zz));
}
int x,y;
int powerMatrix(int n){

    if(n == 0) return x;
    else if ( n==1 )return x+y;

    n-=2;
    memcpy(rr,xx,sizeof(xx));
    while(n){
        if(n&1){
            multiply(rr,xx,DIM);
        }
        multiply(xx,xx,DIM);
        n >>= 1;
    }
    return ( rr[0][0]*y+rr[0][1]*x )  %mod;
}

void buildmatrix(){
    for (int i=0;i<DIM;++i){
        for (int j=0;j<DIM;++j){
           xx[i][j]=1;
        }
    }
    xx[1][1]=0;
}

int main(){
    int kase,m,n;


    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        buildmatrix();
        scanf("%d %d %d %d",&x,&y,&n,&m);
        mod= pow(10,m)+1e-6 ;
        printf("Case %d: %d\n",kk,powerMatrix(n));
    }
    return 0;
}
