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
    mathv(LL a,LL b){x=a;y=b;}
    LL x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

};
LL dot2D(mathv& v1, mathv& v2){
    return v1.x * v2.x + v1.y * v2.y;
}
LL cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}

bool inConvexPolygon(mathv convexPoint[], int total, mathv p) {

	int left = 1, right = total - 1, mid;
	while(right - left > 1) {
		mid = (left + right)/2;
		if(cross2D(convexPoint[0]-convexPoint[mid],convexPoint[0]-p) < 0) right = mid;
		else left = mid;

	}
    //printf("%d %d\n",left,right);
	if(cross2D(convexPoint[0]- convexPoint[left],convexPoint[0]-p) < 0) return false;
	if(cross2D(convexPoint[left]-convexPoint[right],convexPoint[left]-p) < 0) return false;
	if(cross2D(convexPoint[right]-convexPoint[0],convexPoint[right]-p) < 0) return false;
	return true;
}


bool cmp(const mathv& a, const mathv& b){
    if ( a.y!=b.y ){
        return a.y<b.y;
    }else{
        return a.x<b.x;
    }
}

#define SIZE 100100

mathv given[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,qq;
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%lld %lld",&given[i].x,&given[i].y);
        }

        //sort( given,given+n,cmp );
        printf("Case %d:\n",kk);
        mathv tmp;
        scanf("%d",&qq);
        while ( qq-- ){
            scanf("%lld %lld",&tmp.x,&tmp.y);
            if ( inConvexPolygon( given,n,tmp ) ){
                printf("y\n");
            }else{
                printf("n\n");
            }
        }
    }


    return 0;
}
