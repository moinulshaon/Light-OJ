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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define X first
#define Y second

int row,col;
char board[25][25];

bool vis[25][25];

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int bfs( pint start ){

    queue<pint> q;
    queue<int> move;

    CLR(vis);

    q.push( start );
    move.push(0);

    vis[start.X][start.Y]=true;

    pint save;

    int cnt=0;
    int ans=0;
    while(  !q.empty() && cnt<3 ){

        pint tmp=q.front();q.pop();
        int mm=move.front();move.pop();

        for (int i=0;i<4;++i){
            save.X=tmp.X+dr[i];
            save.Y=tmp.Y+dc[i];

            if ( save.X >=0 && save.X<row && save.Y >=0 && save.Y < col
                && !vis[ save.X ][ save.Y ] && board[ save.X ][ save.Y ]!='#' ){

                if ( board[ save.X ][save.Y] != '.' ){
                    ans=max( ans,mm+1 );
                    cnt++;
                }

                vis[ save.X ][save.Y]=true;

                q.push(save);
                move.push(mm+1);

            }
        }

    }
    return ans;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&row,&col);

        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == 'm' ){
                    board[i][j] = '#';
                }
            }
        }


        int ans=0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == 'h' ){
                    ans=bfs( make_pair(i,j) );
                    i=j=30;
                }
            }
        }

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
