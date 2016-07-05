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



#define SIZE 4
int MOD=10007;
class Matrix
{
    int N;
public:
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
} base(SIZE);
Matrix bigmod(Matrix A, int K)
{
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

int main(){

    for (int i=0;i<SIZE;++i){
        for (int j=0;j<SIZE;++j){
            base.matrix[i][j]=0;
        }
    }

    for (int i=0;i<4;++i){
        base.matrix[0][i]=1;
    }
    base.matrix[1][0]=1;
    base.matrix[2][1]=1;
    base.matrix[2][3]=1;
    base.matrix[3][1]=1;
    base.matrix[3][2]=1;

    int kase,x;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&x);
        printf("Case %d: ",kk);
        if ( x==1 )printf("1\n");
        else if ( x==2 )printf("2\n");
        else{
            Matrix tmp=bigmod( base,x-2 );
            int ans=( tmp.matrix[0][0]*2+tmp.matrix[0][1]+tmp.matrix[0][2]+tmp.matrix[0][3] )%MOD;
            printf("%d\n",ans);
        }
    }


    return 0;
}
