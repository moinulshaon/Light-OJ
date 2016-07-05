#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


#define FO(i,a,b) for (int i = (a); i < (b); i++)

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
    mathv(int a,int b){x=a;y=b;}
    int x,y;
    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }
};
int cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
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

#define SIZE 150

bool adj[SIZE][SIZE];
bool res[SIZE][SIZE];
bool now[SIZE][SIZE];


int floyd(mathv *point,int n,mathv *mine,int m){

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if ( i == j ){
                res[i][j]=adj[i][j] = false;
                continue;
            }
            bool inside = true;
            for (int k=0;k<m;++k){
                if ( cross2D( point[j]-point[i] , mine[k]-point[i] ) < 0 ){
                    inside = false;
                    break;
                }
            }

            if ( inside ){
                //printf("%d %d %d %d\n",hull[i].x,hull[i].y,hull[j].x,hull[j].y);
                res[i][j]=adj[i][j] = true;
            }else{
                res[i][j]=adj[i][j] = false;
            }

        }
    }


    FO(s,1,n+1){

        FO(i,0,n){
            if ( res[i][i] )return s;
        }

        FO(i,0,n)FO(j,0,n){
            now[i][j] = res[i][j];
        }

        FO(i,0,n)FO(k,0,n)if(now[i][k])FO(j,0,n){
            res[i][j] |= adj[k][j];
        }

    }

    return -1;
}


mathv point[SIZE];
mathv hull[SIZE];
mathv mine[SIZE];




int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m,g,p;
        scanf("%d %d %d %d",&n,&m,&g,&p);

        for (int i=0;i<n;++i){
            scanf("%d %d",&point[i].x,&point[i].y);
        }
        for (int i=0;i<m;++i){
            scanf("%d %d",&mine[i].x,&mine[i].y);
        }

        int t = convexHull( point,hull,n );



        int cnt = 0;
        int ans = 0;
        for (int i=0;i<m;++i){
            bool inside = true;
            for (int j=0;j<t;++j){
                if ( cross2D( hull[(j+1)%n]-hull[j] , mine[i]-hull[j] ) <0 ){
                    inside = false;
                    break;
                }
            }
            if ( inside ){
                mine[cnt++] = mine[i];
            }else{
                ans += g;
            }
        }
        if ( cnt >0 )
            ans += p * floyd(point,n,mine,cnt);

        printf("Case %d: %d\n",kk,ans);
    }



    return 0;
}
