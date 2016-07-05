#include <cstdio>
#include <vector>

using namespace std;

typedef vector< vector<int> > MATRIX;

#define DIM 4

int mod=10007;

MATRIX multiply(MATRIX &a, MATRIX &b) {

    MATRIX res;
    res.resize( a.size() );
    for (int i=0;i<res.size();++i){
        res[i].resize( b[0].size() );
    }

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[i].size(); j++)
            for (int k = 0; k < a[i].size() ; k++) //col of A and row of B must be same which is equal to a[i].size()
                res[i][j] = ( res[i][j] + ( ( (a[i][k] % mod ) * (b[k][j] % mod))) % mod ) %mod;

    return res;

}

MATRIX powerMatrix(MATRIX mat,int n){

    if(n == 1)  return mat;
    else if(n % 2 == 0){
        MATRIX tmp=powerMatrix( mat,n/2 );
        return  multiply(tmp,tmp);
    }
    else{
        MATRIX tmp=powerMatrix( mat,n/2 );
        tmp=multiply(tmp,tmp);
        return  multiply(  tmp ,mat);
    }
}


void printMatrix(MATRIX mat){
    for (int i=0;i<mat.size();++i){
        for (int j=0;j<mat[i].size();++j){
            printf("%3d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){

    MATRIX ini;
    int n,c,kase;

    ini.resize(DIM);
    for (int i=0;i<DIM;++i){
        ini[i].resize(DIM);
    }

    ini[0][3]=ini[1][0]=ini[2][1]=ini[3][3]=1;

    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d %d %d",&n,&ini[0][0],&ini[0][2],&c);
        printf("Case %d: ",kk);
        if ( n<=2 ){
            printf("0\n");
        }else{
            MATRIX rr=powerMatrix(ini,n-2);
            //printMatrix(rr);
            printf("%d\n",(rr[0][3]*c)%mod);
        }
    }
    return 0;
}
