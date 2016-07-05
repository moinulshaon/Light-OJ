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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 60

class Matrix{
    int N;
public:
    unsigned matrix[SIZE][SIZE];
    Matrix(int n) {N = n;}
    int getDim() {return N;}
    void setVal(unsigned array[][SIZE]){
        int i,j;
        for (i=0; i<N; ++i){
            for (j=0; j<N; ++j) matrix[i][j] = array[i][j];
        }
    }
    Matrix operator+ (Matrix &A){
        Matrix ret(N);
        int i,j;
        for (i=0; i<N; ++i)
        {
            for (j=0; j<N; ++j) ret.matrix[i][j] = (matrix[i][j] + A.matrix[i][j]);
        }
        return ret;
    }
    Matrix operator* (Matrix &A){
        Matrix ret(N);
        int i,j,k;
        for (i=0; i<N; ++i){
            for (j=0; j<N; ++j){
                ret.matrix[i][j] = 0;
                for (k=0; k<N; ++k){
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


int n;
char str[SIZE];
int failure[SIZE];
int len;
vector<char>have;

void pre(){
    len = strlen(str);
    for (int i=1, j=failure[0]= -1; i<len; ++i){
        while (j >= 0 && str[j+1] != str[i])
            j = failure[j];
        if (str[j+1] == str[i]) j++;
        failure[i] = j;
    }
    /*
    for (int i=0;i<len;++i){
        cout<<failure[i]<<" ";
    }cout<<endl;
    */
}

int get(int j,char x){
    while ( j >= 0 && str[j+1] != x)
        j = failure[j];
    if ( str[j+1] == x )j++;
    return j;
}

unsigned f[2][SIZE];
unsigned brute(unsigned alp){

    f[1][0] = alp-1;
    f[1][1] = 1;

    for (int i=2;i<len;++i){
        f[1][i] = 0;
    }

    for (int i=2;i<=n;++i){
        for (int j=0;j<len;++j){
            f[i&1][j] = 0;
        }

        for (int j=0;j<len;++j){
            for (int k=0;k<have.size();++k){
                int g  = get( j-1,have[k] );
                f[i&1][g+1] += f[(i&1)^1][j];
                //cout<<g<<" "<<j-1<<" "<<have[k]<<endl;
            }
        }
        /*
        for (int j=0;j<len;++j){
            cout<<f[i&1][j]<<" ";
        }
        cout<<endl;
        */
    }

    unsigned ret = 0;
    for (int i=0;i<len;++i){
        ret += f[n&1][i];
    }
    return ret;
}


unsigned expo(unsigned alp){

    Matrix base(len);
    for (int i=0;i<SIZE;++i){
        for (int j=0;j<SIZE;++j){
            base.matrix[i][j] = 0;
        }
    }

    for (int j=0;j<len;++j){
        for (int k=0;k<have.size();++k){
            int g  = get( j-1,have[k] );
            if ( g+1<len )
                base.matrix[g+1][j]++;
        }
    }

//base.printMatrix();
    base = bigmod( base,n-1 );
//base.printMatrix();
    unsigned ret = 0;

    for (int i=0;i<len;++i){
        ret += base.matrix[i][0]*unsigned(alp-1U) ;
        if ( len>1 )
            ret +=base.matrix[i][1];
    }
    return ret;
}

unsigned calc(int alp){

    if ( alp == 1 ){
        if ( len > n )return 1;
        else return 0;
    }

    if ( n< 55 ){
        return brute(alp);
    }else{
        return expo(alp);
    }
}


int main(){

    FRO
    freopen("out1.txt","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);

        scanf("%s",str);
        have.clear();
        for (int i=0;str[i];++i){
            have.PB( str[i] );
        }

        scanf("%s",str);
        pre();

        printf("Case %d: %u\n",kk,calc( have.size() ));

    }


    return 0;
}
