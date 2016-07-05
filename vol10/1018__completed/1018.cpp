#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
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


int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

#define SIZE 18
#define X first
#define Y second

int dp[(1<<SIZE)+5];

int n;
pint point[SIZE];

int mask[SIZE][SIZE];


int func( int state ){

    if ( state==(1<<n)-1 )return 0;
    //printf("sahon\n");
    if ( dp[state]!= -1 )return dp[state];

    int ans=(1<<29);
    int save=0;
    for (int i=0;i<n;++i){
        if ( Check(state,i)==0 ){
            for (int j=0;j<n;++j){
                if ( Check(state,j)==0 ){
                    ans=min( ans,1+func( state | mask[i][j] ) );
                }
            }

            break;
        }
    }
    return dp[state]=ans;
}



int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d %d",&point[i].X,&point[i].Y);
        }

        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                int mm=0;

                for (int k=0;k<n;++k){
                    if ( (point[i].Y-point[j].Y)*(point[i].X-point[k].X) == (point[i].Y-point[k].Y)*(point[i].X-point[j].X) ){
                        mm=Set( mm,k );
                    }
                }

                if ( i==j ){
                   mask[i][j]=Set(0,i);
                }else{
                    mask[i][j]=mm;
                }

                //printf("%5d",mm);
            }
            //printf("\n");
        }

        int ans=(1<<29);

        NEG(dp);

        printf("Case %d: %d\n",kk,func(0));
    }

    return 0;
}
