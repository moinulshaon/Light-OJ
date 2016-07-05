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


#define SIZE 10010

vector<pint> dp[SIZE][2];
vector<int> out[SIZE];

int mod = 10007;

pint ccc( pint a,pint b ){
    return MP( a.X+b.X ,(a.Y*b.Y)%mod );
}

pint get(pint a,pint b){
    if ( a.X > b.X ){
        return a;
    }else if ( a.X < b.X ){
        return b;
    }else{
        return MP( a.X , (a.Y+b.Y)%mod );
    }
}

pint func( int x,int child,int have ){


    if ( child == out[x].size() ){
        return MP(0,1);
    }

    pint &ret = dp[x][have][child];


    if ( ret.X != -1 )return ret;

    ret = ccc( func( x,child+1,have ) , func( out[x][child] , 0,1 ) );
    if ( have ){
        ret = get( ret , ccc( MP(1,1), ccc( func( x,child+1,0 ) , func( out[x][child] , 0 , 0 ) ) ) );
    }

    return ret;

}


int main(){

    FRO

    int kase;
    scanf("%d",&kase);;

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        for (int i=1;i<=n;++i){
            dp[i][0].clear();
            dp[i][1].clear();
            out[i].clear();
        }

        int id,tmp,v;
        for (int i=0;i<n;++i){
            scanf("%d %d",&id,&tmp);
            while ( tmp-- ){
                scanf("%d",&v);
                out[id].PB( v );
            }

            dp[id][0].resize( out[id].size() );
            dp[id][1].resize( out[id].size() );
        }

        for (int i=1;i<=n;++i){
            for (int j=0;j<dp[i][0].size();++j){
                dp[i][0][j].X = -1;
            }
            for (int j=0;j<dp[i][1].size();++j){
                dp[i][1][j].X = -1;
            }
        }

        pint ans = func( 1,0,1 );

        printf("Case %d: %d %d\n",kk,ans.X,ans.Y);

    }

    return 0;
}
