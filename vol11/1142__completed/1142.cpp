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

#define SIZE 70
int MOD=10;
class Matrix
{
public:
    int N;
    int matrix[SIZE][SIZE];
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

int tmp[SIZE][SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n,k;
        scanf("%d %d",&n,&k);

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                scanf("%d",&tmp[i][j]);
            }
        }

        printf("Case %d:\n",kk);
        if (  k== 1 ){
            for (int i=0;i<n;++i){
                for (int j=0;j<n;++j){
                    printf("%d",tmp[i][j]%MOD);
                }printf("\n");
            }
            continue;
        }

        base.N= n+n;

        for (int i=0;i<base.N;++i){
            for (int j=0;j<base.N;++j){
                base.matrix[i][j] = 0;
            }
        }

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ( i==j )
                base.matrix[i][j] = 1;
            }
            for (int j=0;j<n;++j){
                base.matrix[i][n+j] = tmp[i][j];
            }
        }

        for (int i=n;i<base.N;++i){
            for (int j=0;j<n;++j){
                base.matrix[i][n+j] = tmp[i-n][j];
            }
        }

        //base.printMatrix();

        Matrix xxx = bigmod( base,k-1 );
        //xxx.printMatrix();

        xxx.N = n;
        Matrix shaon (n);

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                shaon.matrix[i][j] = tmp[i][j];
            }
        }

        Matrix ans= xxx * shaon;

        //ans.printMatrix();

        Matrix other(n);
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                other.matrix[i][j] = xxx.matrix[i][n+j];
            }
        }
        shaon = shaon * other;
        ans = ans + shaon;

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                printf("%d",ans.matrix[i][j]%MOD);
            }printf("\n");
        }

    }


    return 0;
}
