
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

#define EPS  1e-10

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        double ini,fin,n,c;
        scanf("%lf %lf %lf",&ini,&n,&c);
        fin = ini*( 1+n*c );

        //cout<<fin<<endl;

        double ans= 0,low = 0 , high = ini;
        while ( fabs(low-high)>EPS ){
            double mid= ( low+high )/2;
            double r = ini*ini/( 8*mid ) + mid/2;

            double theta = 2*asin( ini/(2*r) );
            double tmp = r*theta;

            ans = mid;

            if (tmp>fin){
                high=mid-EPS;
            }else{
                low=mid+EPS;
            }

            //cout<<low<<" "<<high<<endl;
        }

        printf("Case %d: %.8lf\n",kk,ans);
    }



    return 0;
}
