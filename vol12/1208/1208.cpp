#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

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

    bool operator < (const mathv & p)const{
        if ( x != p.x ){
            return x<p.x;
        }else{
            return y<p.y;
        }
    }

};

LL cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}
double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}


#define SIZE 210
mathv arr[SIZE];
mathv con[SIZE];
mathv tar;
vector<mathv> rev;


bool leftturn(mathv a,mathv b,mathv c){
    return cross2D( b-a,c-b )>=0;
}

const double inf = 1e20;

int start,second;
vector<int> out[SIZE];
vector<int> num[SIZE];
vector<double> cost[SIZE];

bool vis[SIZE];
double dp[SIZE];

double func(int prv,int now,int ind){

    if ( now == start ){
        if ( leftturn( rev[prv],rev[now],rev[second] ) ){
            return 0;
        }else{
            return inf;
        }
    }

    double &ret = dp[ind];
    if ( vis[ind] )return ret;
    vis[ind] = true;

    ret = inf;
    for (int i=0;i<out[now].size();++i){
        int &nxt = out[now][i];
        if ( leftturn( rev[prv],rev[now],rev[nxt] ) ){
            ret = min( ret ,  distance2DPointAndPoint( rev[now],rev[nxt] ) + func( now,nxt,num[now][i] ) );
        }
    }
    return ret;
}

int edge;
void add_edge (int x,int y,double w){
    out[x].PB( y );
    num[x].PB( edge++ );
    cost[x].PB( w );
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for ( int kk=1;kase--;++kk ){

        int p;
        scanf("%d %lld %lld",&p,&tar.x,&tar.y);
        map<mathv,int> mp;
        for (int i=0;i<p;++i){
            scanf("%lld %lld",&arr[2*i].x,&arr[2*i].y);
            scanf("%lld %lld",&arr[2*i+1].x,&arr[2*i+1].y);
            mp[ arr[2*i] ];
            mp[ arr[2*i+1] ];
        }

        int cnt = 0;
        rev.clear();
        snuke(mp,itr){
            rev.PB( itr->X );
            itr->Y = cnt++;
        }


        FO( i,0,cnt ){
            out[i].clear();
            cost[i].clear();
            num[i].clear();
        }
        edge=0;

        for ( int i=0;i<p;++i ){
            if ( cross2D( arr[2*i+1]-arr[2*i] ,tar-arr[2*i] ) >= 0 ){
                add_edge( mp[ arr[2*i] ] , mp[ arr[2*i+1] ] , distance2DPointAndPoint( arr[2*i],arr[2*i+1] ) );
            }else{
                add_edge( mp[ arr[2*i+1] ] , mp[ arr[2*i] ] , distance2DPointAndPoint( arr[2*i],arr[2*i+1] ) );
            }
        }

        double ans = inf;

        for (int i=0;i<cnt;++i){
            for ( int j=0;j<out[i].size();++j ){
                start = i;
                second = out[i][j];

                FO(k,0,edge)vis[k]=false;

                ans = min( ans , distance2DPointAndPoint( rev[start],rev[second] )+ func( start,second,num[i][j] ) );
            }
        }

        if ( ans > inf /10 ){
            ans = -0.5;
        }

        printf("Case %d: %.8lf\n",kk,2*ans);
    }

    return 0;
}
