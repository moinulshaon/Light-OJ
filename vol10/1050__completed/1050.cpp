#include <cstdio>


using namespace std;

#define SIZE 501

bool vis[SIZE][SIZE][2];
double dp[SIZE][SIZE][2];

double func(int a,int b,int f){

    if ( a==0 && b==1 )return 1;
    else if ( a==0 && b==0 )return 0;
    else if ( b==0 )return 0;
    else if ( a<0 )return 0;

    if ( vis[a][b][f] )return dp[a][b][f];
    vis[a][b][f]=true;
    if ( f==0 )
        return dp[a][b][f]=func( a-1,b,!f )*a/(a+b) + func( a,b-1,!f )*b/(a+b);
    else
        return dp[a][b][f]=func( a,b-1,!f );
}

int main(){
    int kase,a,b;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&a,&b);

        printf("Case %d: %.8lf\n",kk,func(a,b,0));
    }
    return 0;
}
