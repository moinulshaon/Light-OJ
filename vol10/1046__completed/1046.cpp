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

#define X first
#define Y second

typedef pair<int,int> pint;
typedef map<int,int> mint;

int total,row,col;
char board[15][15];

bool pos[15][15];
int sum[15][15];

int vis[15][15];

int dr[]={1,1,2,2,-1,-1,-2,-2};
int dc[]={2,-2,1,-1,2,-2,1,-1};

void bfs( pint start,int pp ){

    NEG(vis);

    queue<pint> q;
    q.push( start );

    queue<int> move;
    move.push(0);

    while( !q.empty() ){
        pint tmp=q.front();q.pop();
        int mm=move.front();move.pop();
        if ( vis[ tmp.X ][ tmp.Y ] != -1 )continue;

        //printf("%d %d\n",tmp.X,tmp.Y);

        vis[ tmp.X ][ tmp.Y ] = mm;
        for (int i=0;i<8;++i){
            pint bal= make_pair( tmp.X+dr[i],tmp.Y+dc[i] );
            if (bal.X>=0 && bal.X<row && bal.Y>=0 && bal.Y<col && vis[ bal.X ][ bal.Y ] == -1 ){
                q.push( bal );
                move.push( mm+1 );
            }
        }
    }

    for (int i=0;i<row;++i){
        for (int j=0;j<col;++j){
            if ( vis[i][j]== -1 ){
                pos[i][j]=false;
            }else{
                sum[i][j] += vis[i][j]/pp + ((vis[i][j]%pp)?1:0 );
            }
        }
    }

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
                pos[i][j]=true;
            }
        }
        CLR(sum);

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j] != '.' ){
                    bfs( make_pair(i,j) ,board[i][j]-'0' );
                }
            }
        }

        int ans= (1<<29);

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( pos[i][j] ){
                    ans=min( ans,sum[i][j] );
                    //printf("sahon %d %d %d\n",i,j,sum[i][j]);
                }
            }
        }
        if ( ans == (1<<29) )ans = -1;

        printf("Case %d: %d\n",kk,ans);

    }


    return 0;
}
