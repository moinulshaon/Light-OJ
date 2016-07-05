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

unsigned BigMod ( unsigned a, unsigned p ){
    unsigned res = 1;
    unsigned x = a;

    while ( p ){
        if ( p & 1 ){
            res = ( res * x );
        }
        x = ( x * x ) ;
        p = p >> 1;
    }

    return res;
}


#define SIZE 55

class Matrix
{
public:
    int N;

    unsigned matrix[SIZE][SIZE];
    Matrix(int n) {N = n;}
    int getDim() {return N;}
    Matrix operator+ (Matrix &A)
    {
        Matrix ret(N);
        int i,j;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j) ret.matrix[i][j] = matrix[i][j] + A.matrix[i][j];
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
                    ret.matrix[i][j] = ret.matrix[i][j]+matrix[i][k]*A.matrix[k][j];
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
            for (j=0; j<N; ++j) printf("%3u ", matrix[i][j]);
            puts("");
        }
        puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    }
} base(SIZE-1);
Matrix bigmod(Matrix A, LL p)
{
    Matrix x= A;
    p--;
    while ( p>0 ){
        if ( p&1 ){
            A= A * x;
        }
        x=x*x;
        p>>=1;
    }
    return A;
}

unsigned dp[SIZE][SIZE];

unsigned func( int n,int r ){
    if ( r>n )return 0;
    if ( n== r || r== 0 )return 1;
    if ( dp[n][r] != -1 )return dp[n][r];

    return dp[n][r] = func( n-1,r-1 ) + func( n-1,r );

}

int main(){

    NEG(dp);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        LL n;
        int k;

        scanf("%lld %d",&n,&k);

        printf("Case %d: ",kk);

        if ( k==0 ){
            printf("%u\n",unsigned(n));
            continue;
        }else if ( n<100 ){
            unsigned ans = 0;
            for (int i=1;i<=n;++i){
                ans= ans + BigMod(  i,k );
            }
            printf("%u\n",ans);
            continue;
        }


        int dim = k+1+1;
        base.N = dim;
        for (int i=0;i<dim;++i){
            for (int j=0;j<dim;++j){
                base.matrix[i][j] = 0;
            }
        }

        base.matrix[0][0] = 1;
        for (int i=1;i<dim;++i){
            base.matrix[0][i]= func( k,i-1 );
        }


        for (int i=1;i<dim;++i){
            int tmp = 0;
            for (int j=i;j<dim;++j){
                //cout<<k-i+1<<" "<<tmp<<" "<<func( k-i+1,tmp )<<endl;
                base.matrix[i][j] = func( k-i+1,tmp++ );
            }
        }
        //base.printMatrix();


        Matrix tmp = bigmod( base, n-1 );
        unsigned ans = 0;
        for (int i=0;i<dim;++i){
            ans = ans + tmp.matrix[0][i];
        }
        printf("%u\n",ans);
    }



    return 0;
}
