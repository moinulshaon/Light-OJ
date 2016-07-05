#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 40
class Matrix{
    int N;
public:
    unsigned matrix[SIZE][SIZE];
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
            for (j=0; j<N; ++j) ret.matrix[i][j] = (matrix[i][j] + A.matrix[i][j]);
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
};
Matrix bigmod(Matrix A, LL p){
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


bool pos(int x,int y){
    for (int i=0;i<10;++i){
        if ( x & (1<<i) ){
            for (int j=-1;j<=1;++j){
                if ( i+j>=0 && i+j<10 && ( y & (1<<(i+j) ) ) ){
                    return false;
                }
            }
        }
    }
    return true;
}

bool shaon(int x){

    for (int i=0;i<9;++i){
        if ( (x & (1<<i)) != 0 && (x & ( 1<<(i+1) )) != 0  )return false;
    }
    return true;
}

int main(){


    vector<int> state;
    for (int i=0;i<(1<<10);++i){
        if ( __builtin_popcount(i) == 2 && shaon(i) ){
            state.PB( i );
        }
    }
    Matrix base(state.size());
    for (int i=0;i<state.size();++i){
        for (int j=0;j<state.size();++j){
            base.matrix[i][j] = pos( state[i],state[j] );
        }
    }


    int n,kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        printf("Case %d: ",kk);
        if ( n == 1 ){
            printf("%d\n",state.size());
        }else{
            Matrix ret = bigmod( base,n-1 );
            unsigned ans = 0;
            for (int i=0;i<state.size();++i){
                for (int j=0;j<state.size();++j){
                    ans += ret.matrix[i][j];
                }
            }
            printf("%u\n",ans);
        }
    }


    return 0;
}
