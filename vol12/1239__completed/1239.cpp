#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

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

};

double cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}

double length2D(mathv& v){
    return sqrt(v.x * v.x + v.y * v.y);
}
double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

bool cmp(const mathv& a, const mathv& b){
    if ( a.y!=b.y ){
        return a.y<b.y;
    }else{
        return a.x<b.x;
    }
}
int convexHull(mathv points[],mathv convexPoints[],  int n){
    sort(points, points+n, cmp);
    int m = 0;
    for(int i = 0; i < n; i++){
        while(m >= 2 && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) <= 0)
            m--;
        convexPoints[m++] = points[i];
    }
    for(int i = n-2, t = m+1; i >= 0; i--){
        while(m >= t && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) <= 0)
            m--;
        convexPoints[m++] = points[i];
    }
    return m-1;
}

int main(){


    int kase;
    double PI=acos(-1);
    scanf("%d",&kase);

    mathv pp[60000],ans[60000];

    for (int kk=1;kase--;++kk){
        int n;
        double d;

        scanf("%d %lf",&n,&d);

        for (int i=0;i<n;++i){
            scanf("%lf %lf",&pp[i].x,&pp[i].y);
        }

        if ( n==1 ){
            printf("Case %d: %.8lf\n",kk,2*PI*d);
            continue;
        }else if ( n==2 ){
            printf("Case %d: %.8lf\n",kk,2*PI*d+distance2DPointAndPoint(pp[0],pp[1]));
            continue;
        }

        int m=convexHull(pp,ans,n);
        double rr=0;
        for (int i=0;i<m;++i){
            rr+=distance2DPointAndPoint( ans[i],ans[(i+1)%m] );
        }
        rr+= 2*PI*d;
        printf("Case %d: %.8lf\n",kk,rr);
    }
    return 0;
}
