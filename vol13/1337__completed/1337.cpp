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

char board[510][510];
bool vis[510][510];
int ans[510][510];

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int dfs(int r,int c){

    vis[r][c]=true;

    int sum=0;

    if ( board[r][c] == 'C' )sum++;

    int rr,cc;
    for (int i=0;i<4;++i){
        rr=r+dr[i];
        cc=c+dc[i];
        if ( rr>=0 && rr<row && cc>=0 && cc<col && !vis[rr][cc] && board[rr][cc] != '#' ){
            sum+= dfs( rr,cc );
        }
    }


    return sum;
}

int flood(int r,int c,int val){

    ans[r][c]=val;

    int rr,cc;
    for (int i=0;i<4;++i){
        rr=r+dr[i];
        cc=c+dc[i];
        if ( rr>=0 && rr<row && cc>=0 && cc<col && ans[rr][cc]== -1 && board[rr][cc] != '#' ){
            flood( rr,cc ,val);
        }
    }
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int qq;
        scanf("%d %d %d",&row,&col,&qq);

        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }
        int x,y;
        printf("Case %d:\n",kk);
        CLR(vis);
        NEG(ans);
        while ( qq-- ){
            scanf("%d %d",&x,&y);
            x--;
            y--;
            if ( !vis[x][y] ){
                int aa=dfs(x,y);
                flood(x,y,aa);
            }
            printf("%d\n",ans[x][y]);
        }
    }


    return 0;
}
