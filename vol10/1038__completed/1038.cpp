#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

bool vis[100100][31];
double rr[100100][31];

double step(int n,int left){

    if ( !left || n==1 )return 0;
    else if ( vis[n][left] )return rr[n][left];
    double sum=0;
    int tmp=int ( sqrt(n)+1e-6 ),cnt=0;
    for (int i=1;i<=tmp;++i){
        if ( n%i==0 ){
            if ( i != n/i ){
                sum+=1+step( i,left-1 );
                sum+=1+step( n/i,left-1 );
                cnt+=2;
            }else{
                sum+=1+step( i,left-1 );
                cnt++;
            }
        }
    }
    vis[n][left]=true;
    return rr[n][left]=sum/cnt;
}

int main(){

    int kase,n;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);

        printf("Case %d: %.8lf\n",kk,step(n,30));

    }
    return 0;

}
