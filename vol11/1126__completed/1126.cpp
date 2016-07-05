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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 260000

int prv[SIZE];
int now[SIZE];

int h[55];

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        prv[0]=now[0]=0;
        for (int i=1;i<SIZE;++i){
            prv[i]= now[i] = -(1<<29);
        }
        //CLR(h);
        int sum=0;
        for (int i=0;i<n;++i){
            scanf("%d",&h[i]);
            sum+=h[i];
        }
        sum/=2;

        for (int i=0;i<n;++i){
            for (int j=0;j<=sum;++j){
                now[j]= max( now[j], prv[j] );
                if ( j+h[i]<=sum && h[i]+prv[ j+ h[i] ]>now[j]){
                    now[j]=h[i]+prv[ j+h[i] ];
                }
                int m=abs(j-h[i]);
                if ( m<=sum && h[i]+prv[ m ]>now[j]){
                    now[j]=h[i]+prv[ m ];
                }
            }

            for (int j=0;j<=sum;++j){
                prv[j]=max( prv[j], now[j] );
                //printf("%d ",now[j]);
            }
            //printf("\n");
        }

        printf("Case %d: ",kk);
        if ( now[0] <=0 ){
            printf("impossible\n");
        }else{
            printf("%d\n",now[0]/2);
        }

    }


    return 0;
}
