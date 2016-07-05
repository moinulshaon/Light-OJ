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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define MP make_pair
#define X first
#define Y second

typedef pair<int,int> pint;
typedef map<int,int> mint;

bool colpos[10][10];
bool rowpos[10][10];
bool semipos[10][10];

char board[11][11];

int get(int x,int y){
    return (x/3)*3+(y/3);
}

pair<pint,int> mrv(){

    pint ret = MP(-1,-1);
    int val = (1<<29);

    for (int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if ( board[i][j] != '.' )continue;

            int cnt = 0;
            for (int k=0;k<9;++k){
                if ( !rowpos[i][k] || !colpos[j][k] || !semipos[get(i,j)][k] )continue;
                cnt++;
            }
            if ( cnt<val ){
                val = cnt;
                ret = MP(i,j);
            }
        }
    }
    return MP(ret,val);
}
int shaon = 0;
bool backtrack(int done){

    if ( done == 9*9 ){
        return true;
    }

    pair<pint,int> v = mrv();
    if ( v.Y >=(1<<29) || v.Y == 0 ){
        return false;
    }


    pint &pos=v.X;

    for (int i=0;i<9;++i){

        if ( !rowpos[pos.X][i] || !colpos[pos.Y][i] || !semipos[get(pos.X,pos.Y)][i] )continue;
        board[pos.X][pos.Y] = '1'+i;

        rowpos[pos.X][i] = colpos[pos.Y][i] = semipos[get(pos.X,pos.Y)][i] = false;

        if (  backtrack(done+1) )return true;
        board[pos.X][pos.Y] = '.';
        rowpos[pos.X][i] = colpos[pos.Y][i] = semipos[get(pos.X,pos.Y)][i] = true;

    }
    return false;
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        for (int i=0;i<9;++i){
            scanf("%s",board[i]);
        }

        memset(colpos,true,sizeof(colpos));
        memset(rowpos,true,sizeof(rowpos));
        memset(semipos,true,sizeof(semipos));


        int done = 0;
        for (int i=0;i<9;++i){
            for (int j=0;j<9;++j){
                if ( board[i][j] != '.' ){
                    rowpos[i][ board[i][j]-'1' ]=false;
                    colpos[j][ board[i][j]-'1' ]=false;
                    semipos[ get(i,j) ][ board[i][j]-'1' ]=false;
                    done++;
                }
            }
        }

        backtrack(done);


        //printf("%d\n",completed);

        printf("Case %d:\n",kk);
        for (int i=0;i<9;++i){
            printf("%s\n",board[i]);
        }

    }


    return 0;
}
