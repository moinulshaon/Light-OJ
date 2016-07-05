#include <cstdio>
#include <vector>

using namespace std;

typedef vector< vector<int> > MATRIX;

#define DIM 6

int mod;

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

    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    MATRIX ini,rr;
    ini.resize(DIM);
    for (int i=0;i<DIM;++i){
        ini[i].resize(DIM);
    }

    ini[1][0]=ini[2][1]=1;
    ini[4][3]=ini[5][4]=1;

    int f0,f1,f2,g0,g1,g2,q,n;

    for (int kk=1;kase--;++kk){
        scanf("%d %d %d",&ini[0][0],&ini[0][1],&ini[0][5]);
        scanf("%d %d %d",&ini[3][3],&ini[3][4],&ini[3][2]);

        scanf("%d %d %d",&f0,&f1,&f2);
        scanf("%d %d %d",&g0,&g1,&g2);

        scanf("%d",&mod);
        scanf("%d",&q);
        printf("Case %d:\n",kk);
        while (  q-- ){
            scanf("%d",&n);
            if ( n==0 ){
                printf("%d %d\n",f0%mod,g0%mod);
            }else if ( n==1 ){
                printf("%d %d\n",f1%mod,g1%mod);
            }else if ( n==2 ){
                printf("%d %d\n",f2%mod,g2%mod);
            }else{
                rr=powerMatrix(ini,n-2);
                int x=( ( rr[0][0]*f2 )%mod + (rr[0][1]*f1)%mod+(rr[0][2]*f0)%mod+(rr[0][3]*g2)%mod+(rr[0][4]*g1)%mod+(rr[0][5]*g0 )%mod )%mod;
                int y=( ( rr[3][0]*f2 )%mod + (rr[3][1]*f1)%mod+(rr[3][2]*f0)%mod+(rr[3][3]*g2)%mod+(rr[3][4]*g1)%mod+(rr[3][5]*g0 )%mod )%mod;
                printf("%d %d\n",x,y);
            }
        }

    }
    return 0;

}
