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

struct mathv{
    double x,y,z;
}a,b,c;

const double EPS = 1e-8;

double func( double x ){
    mathv tmp;
    tmp.x = a.x +  ( b.x-a.x ) * x;
    tmp.y = a.y +  ( b.y-a.y ) * x;
    tmp.z = a.z +  ( b.z-a.z ) * x;


    return sqrt( pow( tmp.x-c.x,2 )+pow( tmp.y-c.y,2 )+pow( tmp.z-c.z,2 ) );
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for( int kk=1;kase--;++kk){
        scanf("%lf %lf %lf",&a.x,&a.y,&a.z);
        scanf("%lf %lf %lf",&b.x,&b.y,&b.z);
        scanf("%lf %lf %lf",&c.x,&c.y,&c.z);


        double low = 0,high = 1;

        while ( low<high+EPS ){

            double one = low+(high-low)/3;
            double two = high-(high-low)/3;

            if ( func( one )<func(two) ){
                high = two-EPS;
            }else{
                low = one+EPS;
            }
        }
        printf("Case %d: %.8lf\n",kk,func( (low+high)/2 ) );
    }


    return 0;
}
