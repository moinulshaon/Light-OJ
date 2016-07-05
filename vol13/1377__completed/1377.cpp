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

int row,col;

char board[205][205];
bool vis[205][205][2];

vector<pint> tel;


struct tt{
    int x,y;
    bool nxt;
    int step;
};

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int bfs( int x,int y ){

    tt start,save;
    start.x=x;
    start.y=y;
    start.nxt=true;
    start.step=0;

    queue<tt> q;

    char used=0;

    CLR(vis);

    q.push( start );
    vis[ start.x ][start.y][start.nxt]=1;

    while ( !q.empty() ){

        tt tmp=q.front();q.pop();

        //printf("%d %d %d\n",tmp.x,tmp.y,tmp.step);

        for (int i=0;i<4 && tmp.nxt ;++i){
            save.x=tmp.x+dr[i];
            save.y=tmp.y+dc[i];
            save.step=tmp.step+1;

            if ( board[ save.x ][ save.y ] != '#' && !vis[ save.x ][save.y][save.nxt]  ){
                save.nxt= ( board[ save.x ][ save.y ] !='*' );
                if ( board[ save.x ][ save.y ] == 'D' )return save.step;
                q.push( save );
                vis[ save.x ][save.y][save.nxt]=true;
            }
        }

        if ( board[ tmp.x ][ tmp.y ] == '*'  && used<=2 ){
            for (int i=0;i<tel.size();++i){
                if ( tel[i].first!= tmp.x || tel[i].second!= tmp.y  ){
                    save.x=tel[i].first;
                    save.y=tel[i].second;
                    save.step=tmp.step+1;
                    save.nxt=true;

                    if ( board[ save.x ][ save.y ] != '#' && !vis[ save.x ][save.y][save.nxt] ){
                        if ( board[ save.x ][ save.y ] == 'D' )return save.step;
                        q.push( save );
                        vis[ save.x ][save.y][save.nxt]=true;
                    }
                }
            }
            used++;
        }


    }
    return -1;
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

        tel.clear();

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == '*' ){
                    tel.PB( make_pair(i,j) );
                }
            }
        }

        int ans;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] == 'P' ){
                    ans=bfs(i,j);
                    i=j=1000;
                }
            }
        }

        printf("Case %d: ",kk);
        if ( ans== -1 ){
            printf("impossible\n");
        }else{
            printf("%d\n",ans);
        }

    }


    return 0;
}
