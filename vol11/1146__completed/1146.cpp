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
    mathv(){x=0;y=0;}
    mathv(double a,double b){x=a;y=b;}
    double x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

}a,b,c,d;
double distance2DPointAndPoint(mathv v1, mathv v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

const double EPS = 1e-8;

mathv ff1( double x ){

    mathv tmp;
    tmp.x = a.x +  ( b.x-a.x ) * x;
    tmp.y = a.y +  ( b.y-a.y ) * x;
    return tmp;
}

mathv ff2( double x ){

    mathv tmp;
    tmp.x = c.x +  ( d.x-c.x ) * x;
    tmp.y = c.y +  ( d.y-c.y ) * x;
    return tmp;
}

double func( double x ){
    return distance2DPointAndPoint( ff1(x),ff2(x) );
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%lf %lf",&a.x,&a.y);
        scanf("%lf %lf",&b.x,&b.y);
        scanf("%lf %lf",&c.x,&c.y);
        scanf("%lf %lf",&d.x,&d.y);

        double low= 0 ,high= 1;

        //cout<<func( 1 )<<endl;

        while (  low<high+EPS ){

            double one = low+( high-low )/3;
            double two = high-( high-low )/3;

            //cout<<low<<' '<<high<<' '<<one<<' '<<two<<' '<<func(one)<<' '<<func(two)<<endl;

            if ( func( one ) > func( two )  ){
                low= one+EPS;
            }else{
                high = two-EPS;
            }

        }


        printf("Case %d: %.7lf\n",kk,func( (low+high)/2 )+EPS );

    }


    return 0;
}
