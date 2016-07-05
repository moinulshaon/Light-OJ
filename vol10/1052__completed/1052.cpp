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

#define SIZE 2
LL MOD=1000000007;
class Matrix
{
    int N;
public:
    LL matrix[SIZE][SIZE];
    Matrix(int n) {N = n;}
    int getDim() {return N;}
    void setVal(int array[][SIZE])
    {
        int i,j;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j) matrix[i][j] = array[i][j];
        }
    }
    Matrix operator+ (Matrix &A)
    {
        Matrix ret(N);
        int i,j;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j) ret.matrix[i][j] = (matrix[i][j] + A.matrix[i][j])%MOD;
        }
        return ret;
    }
    Matrix operator* (Matrix &A)
    {
        Matrix ret(N);
        int i,j,k;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j)
            {
                ret.matrix[i][j] = 0;
                for (k=0; k<N; ++k)
                {
                    ret.matrix[i][j] += matrix[i][k]*A.matrix[k][j];
                    ret.matrix[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    void printMatrix()
    {
        int i,j;
        puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j) printf("%3d ", matrix[i][j]);
            puts("");
        }
        puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    }
} base(2);
Matrix bigmod(Matrix A, int K){
    if (K==1) return base;
    if (K&1)
    {
        Matrix ret = bigmod(A, K-1);
        ret = ret * base;
        return ret;
    }
    Matrix ret = bigmod(A, K>>1);
    ret = ret*ret;
    return ret;
}

LL fibonacci( int x ){
    if ( x==0 )return 0;
    if ( x<=2 )return 1;

    base.matrix[0][0]=base.matrix[0][1]=base.matrix[1][0]=1;
    base.matrix[1][1]= 0;

    Matrix tmp= bigmod(base,x-2);

    return ( tmp.matrix[0][0] + tmp.matrix[0][1] )%MOD;

}

long long BigMod ( long long a, long long p, long long m ){
    long long res = 1;
    long long x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res % m;
}


int main(){

    FRO


    base.matrix[0][0]=base.matrix[0][1]=base.matrix[1][0]=1;
    base.matrix[1][1]= 0;

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL n,x,m,y,k;

        scanf("%lld %lld %lld %lld %lld",&n,&x,&m,&y,&k);

        if ( n>m ){
            swap(n,m);
            swap(x,y);
        }

        LL p= -1,q= -1;

        if (  n>2 && m>2 ){

            LL fn1=fibonacci(n-1);
            LL fn2=fibonacci(n-2);


            LL fm1=fibonacci(m-1);
            LL fm2=fibonacci(m-2);

            LL den= ( fn2* fm1 - fn1*fm2 );


            if (  ( x*fm1 - y* fn1 ) % den ==0 ){
                p =( x*fm1 - y* fn1 ) / den;
            }
            if ( ( fn2*y - x*fm2 )% den==0 ){
                q = ( fn2*y - x*fm2 )/ den;
            }


        }else{
            if ( n==1 ){
                p=x;
                q= ( y - fibonacci( m-2 )*x );

                LL tt = fibonacci( m-1 );
                if ( q%tt == 0 ){
                    q/=tt;
                }else{
                    q= -1;
                }

            }else if ( n==2 ){
                q = x;
                p = ( y- fibonacci( m-1 )*x );

                LL tt = fibonacci( m-2 );
                if ( p%tt == 0 ){
                    p/=tt;
                }else{
                    p= -1;
                }

            }
        }


        printf("Case %d: ",kk);
        if ( p<=0 || q<=0 ||  p>q || 2*p<q  ){
            printf("Impossible\n");
        }else{

            if ( k==1 ){
                printf("%lld\n",p);
            }else if ( k==2 ){
                printf("%lld\n",q);
            }else{
                Matrix tmp= bigmod(base,k-2);
                printf("%lld\n", (tmp.matrix[0][0]* q + tmp.matrix[0][1]* p)%MOD );
            }


        }

    }
    return 0;
}
