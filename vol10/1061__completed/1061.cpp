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


#define SIZE 8

int ccc[SIZE][SIZE][SIZE][SIZE];

int calc( pint a,pint b ){

    if ( a == b )return 0;

    int &ret = ccc[a.X][a.Y][b.X][b.Y];

    if ( ret != -1 )return ret;

    if ( a.X == b.X || a.Y == b.Y ){
        return ret = 1;
    }
    for (int i= -8;i<=8;++i ){
        pint tmp = MP( a.X+i,a.Y+i );
        if ( tmp.X>=0 && tmp.X<8 && tmp.Y>=0 && tmp.Y<8 ){
            if ( tmp == b ){
                return ret = 1;
            }
        }

        tmp = MP( a.X+i,a.Y-i );
        if ( tmp.X>=0 && tmp.X<8 && tmp.Y>=0 && tmp.Y<8 ){
            if ( tmp == b ){
                return ret = 1;
            }
        }
    }
    return ret = 2;
}


vector< vector<pint> > ans;
vector<pint> now;

bool row[SIZE];
int rightdiag[2*SIZE+1];
int leftdiag[2*SIZE+1];

void solution(int n){
    if (n==8){
        ans.PB( now );
    }

    for (int i=0;i<8;++i){
        if ( row[i] && rightdiag[n-i+8] && leftdiag[n+i] ){
            row[i]=rightdiag[n-i+8] =leftdiag[n+i]=false;
            now.PB( MP( i,n ) );
            solution(n+1);
            now.pop_back();
            row[i]=rightdiag[n-i+8] =leftdiag[n+i]=true;;
        }
    }
}


char board[SIZE+1][SIZE+1];

int cost[SIZE][SIZE];
int dp[SIZE][1<<SIZE];

int func( int totake,int state ){
    if ( totake == SIZE )return 0;

    int &ret = dp[totake][state];
    if ( ret != -1 )return ret;

    ret = (1<<29);
    for (int i=0;i<SIZE;++i){
        if ( ( state & (1<<i) ) == 0 ){
            ret= min( ret, cost[totake][i]+func( totake+1,state | (1<<i) ) );
        }
    }
    return ret;
}

int main(){

    memset(row,true,sizeof(row));
    memset(rightdiag,true,sizeof(rightdiag));
    memset(leftdiag,true,sizeof(leftdiag));
    solution(0);

    NEG(ccc);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        for (int i=0;i<SIZE;++i){
            scanf("%s",board[i]);
        }

        now.clear();
        for (int i=0;i<8;++i){
            for (int j=0;j<8;++j){
                if ( board[i][j] == 'q' ){
                    now.PB( MP( i,j ) );
                }
            }
        }

        int val = (1<<29);
        for (int i=0;i<ans.size();++i){
            for (int j =0;j<SIZE;++j){
                for (int k=0;k<SIZE;++k){
                    cost[j][k] = calc( ans[i][j], now[k] );
                }
            }
            NEG(dp);
            val = min( val , func( 0,0 ) );
        }
        printf("Case %d: %d\n",kk,val);
    }


    return 0;
}
