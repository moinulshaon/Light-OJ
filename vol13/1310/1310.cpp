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

mint dp[9][105][1<<8];
char str[9][105];
int row,col;

inline int get1(int state){
    return ( ( state|( 1<<(row-1) ) |( 1<<(row-2) ) ) << ( 2 ) ) | 3 ;
}
inline int get2(int state){
    return ( ( state|( 1<<(row-1) ) |( 1<<(row-2) )|( 1<<(row-3) ) ) << ( 3 ) ) | 7 ;
}


bool can1[9][1<<17];
bool can2[9][1<<17];

int func(int r,int c, int state){
    if ( r >= row ){
        r = 0;
        c = c+1;
    }
    if ( c == col ){
        return 0;
    }

    state&=(1<<(row+row))-1;

    if ( dp[r][c][state&( (1<<8)-1) ].count( state>>8 ) ){
        return dp[r][c][state&( (1<<8)-1) ][ state>>8 ];
    }

    int ret = func( r+1,c,( state<<1 ) | ( str[r][c] != '.' ) );


    if ( r+1< row && c-2>=0 && str[r][c] == '.' && str[r+1][c] == '.'
        && can1[row][state] ){
        ret = max( ret , 1+func( r+2,c,get1(state) ) );
    }

    if ( r+2< row &&  c-1>=0 && str[r][c] == '.' && str[r+1][c] == '.' && str[r+2][c] == '.'
        && can2[row][state] ){
        ret = max( ret , 1+func( r+3,c,get2(state) ) );
    }
    return dp[r][c][state&( (1<<8)-1) ][ state>>8 ]=ret;
}

int main(){

    FRO

    for (int r=1;r<9;++r){
        for (int state=0;state<(1<<(r+r));++state){
            if ( ( state&(1<<(r-1)) ) == 0 && ( state&(1<<(r-2)) ) == 0 && ( state&(1<<(r+r-1)) ) == 0 && ( state&(1<<(r+r-2)) ) == 0 ){
                can1[r][state] = true;
            }else{
                can1[r][state] = false;
            }
        }
    }

    for (int r=1;r<9;++r){
        for (int state=0;state<(1<<(r+r));++state){
            if ( ( state&(1<<(r-1)) ) == 0 && ( state&(1<<(r-2)) ) == 0 && ( state&(1<<(r-3)) ) == 0 ){
                can2[r][state] = true;
            }else{
                can2[r][state] = false;
            }
        }
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&row,&col);
        for (int i=0;i<row;++i){
            scanf("%s",str[i]);
        }
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                for (int k=0;k<(1<<8);++k){
                    dp[i][j][k].clear();
                }
            }
        }

        printf("Case %d: %d\n",kk,func( 0,0,0 ));
    }


    return 0;
}
