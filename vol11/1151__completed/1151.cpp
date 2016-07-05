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

#define SIZE 103

double tbl[SIZE][SIZE];


void gauss( int eqn ){

    //doing forward elimination

    int mx;
    for (int i=0;i<eqn;++i){
        mx=i;
        for (int j=i+1;j<eqn;++j){
            if ( fabs( tbl[j][i] ) > fabs( tbl[mx][i] ) ){
                mx=j;
            }
        }

        if ( mx!=i ){
            for ( int j=0;j<=eqn;++j ){
                swap( tbl[i][j],tbl[mx][j] );
            }
        }

        if ( fabs( tbl[i][i] )<1e-6 ){
            exit(5);
            return ;
        }

        for (int j = eqn ; j >= i; --j){
            for (int k = i + 1; k < eqn; ++k){
                tbl[k][j] -= tbl[k][i]/tbl[i][i] * tbl[i][j];
            }
        }
    }

    //doing backword elimination
    for (int i = eqn - 1; i >= 0; --i) {
        if ( fabs( tbl[i][i] )<1e-6 ){
            exit(5);
            return ;
        }
        tbl[i][eqn] = tbl[i][eqn] / tbl[i][i];
        tbl[i][i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            tbl[j][eqn] -= tbl[j][i] * tbl[i][eqn];
            tbl[j][i] = 0;
        }
    }
}

bool taken[SIZE];

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1; kase-- ;++kk){
        int x,y,n=100,change,cnt;
        scanf("%d",&cnt);

        CLR(tbl);
        CLR(taken);

        change=0;


        for (int i=0;i<cnt;++i){
            scanf("%d %d",&x,&y);
            taken[x-1]=true;
            tbl[change][x-1]=1;
            tbl[change][y-1]=-1;
            change++;
        }

        tbl[99][99]=1;

        for (int i=0;i<99;++i){
            if ( !taken[i] ){
                int ext=i+6-99;
                if ( ext>0 ){
                    tbl[change][i] = 1.0 - ext/6.0 ;
                    for (int j=1;j<=6-ext;++j){
                        tbl[ change ][ i+j ]= -1.0/6.0;
                    }
                    tbl[change][100]=1;
                }else{
                    tbl[change][i]= 6;
                    for (int j=1;j<=6;++j){
                        tbl[change][i+j]= -1;
                    }
                    tbl[change][100]=6;
                }
                change++;
            }
        }
        /*
        for (int i=0;i<=100;++i){
            printf("%d %.3lf\n",i,tbl[98][i]);
        }printf("%d\n",change);
        */
        gauss(100);


        printf("Case %d: %.8lf\n",kk,tbl[0][100]);
    }


    return 0;
}
