#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define sz 110
#define INF 1000000000

int mat[sz][sz];
int n;

void rd(int r,int c){
    for (int i=0;i<c;++i){
        scanf("%d",&mat[c-i][i]);
        //printf("%d %d\n",c-i,i);
    }

    scanf("%d",&mat[r][c]);
    //printf("%d %d\n",r,c);
}
void rd2(int r,int c){

    scanf("%d",&mat[r][c]);
    //printf("%d %d\n",r,c);

    for (int i=0;c+i+1<n;++i){
        scanf("%d",&mat[r-i-1][c+i+1]);
        //printf("%d %d\n",r-i-1,c+i+1);
    }


}

int dp[sz][sz];

int func(int r,int c){

    if (r==n-1 && c==n-1)return mat[r][c];
    else if (r==n || c==n)return -INF;

    if (dp[r][c]!=-1)return dp[r][c];

    return dp[r][c]=mat[r][c]+max( func(r+1,c),func(r,c+1) );

}

int main(){
    freopen("in.txt","r",stdin);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);
        for (int i=0;i<n;++i){
            rd(0,i);
        }
        for (int i=1;i<n;++i){
            rd2(n-1,i);
        }

        memset(dp,-1,sizeof(dp));

        /*
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                printf("%3d",mat[i][j]);
            }
            printf("\n");
        }
        */

        printf("Case %d: %d\n",kk,func(0,0));


    }
    return 0;

}
