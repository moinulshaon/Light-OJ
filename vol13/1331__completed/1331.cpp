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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

const double PI = acos( -1 );

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        double r1,r2,r3;
        scanf("%lf %lf %lf",&r1,&r2,&r3);

        double a = r1+r2;
        double b = r2+r3;
        double c = r1+r3;

        double A = acos( (b*b+c*c-a*a)/( 2*b*c )  );
        double B = acos( (a*a+c*c-b*b)/( 2*a*c )  );
        double C = acos( (b*b+a*a-c*c)/( 2*b*a )  );


        double s = ( a+b+c )/2;
        double area = sqrt( s* (s-a) *(s-b)*(s-c) );

        area -= A /( 2*PI ) * PI * r3*r3;
        area -= B /( 2*PI ) * PI * r1*r1;
        area -= C /( 2*PI ) * PI * r2*r2;

        printf("Case %d: %.8lf\n",kk,area);
    }


    return 0;
}
