#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define INF 1100000000

typedef long long LLL;

struct mathv{
    mathv(){x=0;y=0;}
    mathv(LLL a,LLL b){x=a;y=b;}
    LLL x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

};

LLL dot2D(mathv& v1, mathv& v2){
    return v1.x * v2.x + v1.y * v2.y;
}
LLL dot2D(mathv& o, mathv& a, mathv& b){
    return (a.x-o.x) * (b.x-o.x) - (a.y-o.y) * (b.y-o.y);
}
LLL cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}
LLL cross2D(mathv& o, mathv& a, mathv& b){
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}

double length2D(mathv v){
    return sqrt(v.x * v.x + v.y * v.y);
}
double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}


struct mathl{
    mathv p1,p2;
};
double distance2DPointAndLine(mathv& p, mathl& l){
    mathv v1 = p - l.p1, v2 = l.p2 - l.p1;
    return fabs(cross2D(v1, v2)) / length2D(v2);
}
double distance2DPointAndSegment(mathv& p, mathl& s)
{
    mathv p1p = p - s.p1, p1p2 = s.p2 - s.p1;
    mathv p2p = p - s.p2, p2p1 = s.p1 - s.p2;


    if (dot2D(p1p, p1p2) > 0 && dot2D(p2p, p2p1) > 0)
        return distance2DPointAndLine(p, s);
    else
        return min( distance2DPointAndPoint(p, s.p1),distance2DPointAndPoint(p, s.p2) );
}


bool intersect2DSegmentAndPoint(mathl& s, mathv& p){
    return cross2D(s.p1, s.p2, p) == 0 && dot2D(p, s.p1, s.p2) <= 0;
}

bool isColinearThreePoint(mathv& p1, mathv& p2, mathv& p){
    return p.x >= min(p1.x, p2.x)
        && p.x <= max(p1.x, p2.x)
        && p.y >= min(p1.y, p2.y)
        && p.y <= max(p1.y, p2.y);
}
bool isColinearFourPoint(mathv& a1, mathv& a2, mathv& b1, mathv& b2)
{
    return isColinearThreePoint(a1, a2, b1)
        || isColinearThreePoint(a1, a2, b2)
        || isColinearThreePoint(b1, b2, a1)
        || isColinearThreePoint(b1, b2, a2);
}
bool intersectTwoSegment(mathv& a1, mathv& a2, mathv& b1, mathv& b2)
{
    double c1 = cross2D(a1, a2, b1);
    double c2 = cross2D(a1, a2, b2);
    double c3 = cross2D(b1, b2, a1);
    double c4 = cross2D(b1, b2, a2);

    if (c1 * c2 < 0 && c3 * c4 < 0) return true;
    if (c1 == 0 && isColinearThreePoint(a1, a2, b1)) return true;
    if (c2 == 0 && isColinearThreePoint(a1, a2, b2)) return true;
    if (c3 == 0 && isColinearThreePoint(b1, b2, a1)) return true;
    if (c4 == 0 && isColinearThreePoint(b1, b2, a2)) return true;
    return false;
}
bool intersectTwoSegment(mathl& s1,mathl& s2){
    return intersectTwoSegment(s1.p1, s1.p2, s2.p1, s2.p2);
}
mathv intersectionTwoLines(mathv a,mathv b,mathv p,mathv q)
{
    double det=(b.x-a.x)*(p.y-q.y)-(p.x-q.x)*(b.y-a.y);
    double t1=(p.x-a.x)*(p.y-q.y)-(p.x-q.x)*(p.y-a.y);
    if(det==0)
    {
        mathv tmp(INF,INF);
        return tmp;
    }
    t1=t1/det;

    mathv tmp( a.x+( b.x-a.x)*t1 ,a.y+( b.y-a.y)*t1  );
    return tmp;
}

mathv basePoint;
int distance2DPointAndPointSqueredVersion(const mathv& v1,const  mathv& v2){
    return (v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y);
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


    for (int i=0;i<n-1;++i){
        if ( points[i].x==points[ i+1 ].x && points[i].y==points[ i+1 ].y ){
            swap( points[i],points[--n] );
            --i;
        }
    }
    /*
    for (int i=0;i<n;++i){
        printf("%lld %lld\n",points[i].x,points[i].y);
    }
    */
    if ( n<3 )return n;
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

int areaPolygon(mathv points[],int np) {
    int area = 0;
    for(int i = 0; i < np; i++) {
        area += points[i].x * points[ (i+1)%np ].y - points[i].y * points[(i+1)%np].x;
    }
    return abs(area);
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

const int maxBufSize = (5000000);

struct Input
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	void grabBuffer() {
		bufSize = (maxBufSize); bufPos = 0;
		bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
		buffer[bufEnd] = '\0';
	}
	bool bufEof() {return bufPos == bufEnd;}
	int getChar() {return buffer[bufPos++];}
	void skipWS() {
		while ((buffer[bufPos] == '\n' ||
			buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
			bufPos++;
	}
	int rInt() {
		int n = 0, x; skipWS();
		bool neg=false;
		if (  ( x = getChar() )=='-'  ){
            neg=true;
            x=getChar();
		}

		for (; x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
        if ( neg )return -n;
        else return n;
	}
	inline bool isWhiteSpace(char x) {
		return x == ' ' || x == '\n' || x == '\t';
	}
	char rChar() {skipWS(); return getChar();}
};
Input input;

double degree( mathv a,mathv b){
    return acos( dot2D(a,b)/( length2D(a)*length2D(b) ) );
}
mathv points[110000],convexPoints[110000];
int main(){

    freopen("in.txt","r",stdin);

    input.grabBuffer();



    int kase;
    kase=input.rInt();
    int n;
    double PI=acos(-1);

    for (int kk=1;kase--;++kk){

        n=input.rInt();



        for (int i=0;i<n;++i){
            points[i].x=input.rInt();
            points[i].y=input.rInt();
        }

        if ( n< 3 ){
            printf("Case %d: %.7lf\n",kk,double(0));
            continue;
        }

        int m=convexHull(points,convexPoints,n);
        //cout<<m<<endl;
        /*
        for (int i=0;i<m;++i){
            cout<<points[i].x<<" "<<points[i].y<<endl;
        }
        */
        if ( m< 3 ){
            printf("Case %d: %.7lf\n",kk,double(0) );
            continue;
        }

        double deg= degree( convexPoints[m-1]-convexPoints[0] ,convexPoints[1]- convexPoints[0] )   ;
        //cout<<deg*180/PI<<endl;
        //continue;
        for (int i=1;i<=m;++i){
            deg=min( deg, degree( convexPoints[i-1]-convexPoints[i] ,convexPoints[ (i+1)%m ]- convexPoints[i] )  );
            //cout<<i<<" "<<deg*180/PI<<endl;
        }
        printf("Case %d: %.7lf\n",kk,deg*180/PI);

    }
    return 0;

}
