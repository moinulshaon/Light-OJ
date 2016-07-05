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

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        int num=0;
        int den=n;
        int a;
        for (int i=0;i<n;++i){
            scanf("%d",&a);
            if ( a<0 ){
                den--;
                num+= -a;
            }else{
                num+= a;
            }
        }

        printf("Case %d: ",kk);
        if ( !den ){
            printf("inf\n");
        }else{
            a=__gcd( num,den );
            printf("%d/%d\n",num/a,den/a);
        }

    }


    return 0;
}
