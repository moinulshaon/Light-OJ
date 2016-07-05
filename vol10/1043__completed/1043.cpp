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

const double EPS=1e-7;

int main(){
    FRO

    int kase;
    scanf("%d",&kase);
    double a,b,c,ratio;
    for (int kk=1;kase--;++kk){
        scanf("%lf %lf %lf %lf",&b,&c,&a,&ratio);

        double theta= (b*b+c*c-a*a)/(2*b*c) ;

        double low=EPS,high=b;
        double total= .5*b*c*theta;
        double ans;

        //printf("%lf %lf\n",total);
        while( low<=high ){
            double mid=(low+high)/2;
            double up=.5*mid*c*theta/(b/mid);
            double rem=total-up;

            //printf("%lf %lf %lf\n",mid,up,rem);

            ans=mid;

            if ( up/rem > ratio ){
                high=mid-EPS;
            }else{
                low=mid+EPS;
            }
        }

        printf("Case %d: %.7lf\n",kk,ans);
    }


    return 0;
}
