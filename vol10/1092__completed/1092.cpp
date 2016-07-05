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

const int inf = (1<<29);

#define SIZE 8
int row,col;
int board[15];
int bit[1<<SIZE];
int flip[1<<SIZE];

int dp[SIZE][1<<SIZE][1<<SIZE];

int func( int totake, int prv ,int now ){

    if ( totake == row ){
        if ( prv == 0 )return 0;
        else return inf;
    }

    int &ret = dp[totake][prv][now];
    if ( ret != -1 )return ret;

    ret = inf;
    for (int mov =0;mov<(1<<col);++mov ){
        if ( ( prv ^ flip[mov] ) == 0 ){
            ret = min( ret , bit[mov] + func( totake+1,now^flip[mov],board[totake+1]^flip[mov] )  );
        }
    }
    return ret;

}
int save[1<<SIZE];

int main(){

    FRO

    bit[0] =0;
    for (int i=1;i<(1<<SIZE);++i){
        bit[i] = __builtin_popcount(i);
    }

    for (int i=0;i<(1<<SIZE);++i){
        save[i] = 0;
        for (int j=0;j<SIZE;++j){
            if ( i & (1<<j) ){
                save[i] ^= (1<<j);
                save[i] ^= ( 1<<(j+1) );
                if ( j-1>=0 ){
                    save[i] ^= ( 1<<(j-1) );
                }
            }
        }
    }
    char str[SIZE];

    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%d %d",&row,&col);

        for (int i=0;i<row;++i){
            scanf("%s",str);
            board[i] = 0;
            for (int j=0;j<col;++j){
                if ( str[j] == '.' ){
                    board[i] |= (1<<j);
                }
            }
            //cout<<board[i]<<endl;
        }

        for (int i=0;i<(1<<col);++i){
            flip[i] = save[i] %(1<<col);
            //cout<<i<<" "<<flip[i]<<endl;
        }

        for (int i=0;i<row;++i){
            for (int j=0;j<(1<<col);++j){
                for (int k=0;k<(1<<col);++k){
                    dp[i][j][k] = -1;
                }
            }
        }

        int ans = inf;

        for (int state = 0;state<(1<<col);++state){
            ans = min( ans , bit[state] + func( 1,board[0] ^ flip[state],board[1] ^ flip[state] ) );
        }

        if ( ans >= inf ){
            printf("Case %d: impossible\n",kk);
        }else{
            printf("Case %d: %d\n",kk,ans);
        }
    }

    return 0;
}
