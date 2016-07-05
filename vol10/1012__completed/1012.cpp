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

#define SIZE 25

bool vis[SIZE][SIZE];
int row,col;

char board[SIZE][SIZE];

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int flood( int r,int c ){
    vis[r][c]=true;
    int ss=1;
    int rr,cc;

    for (int i=0;i<4;++i){
        rr=r+dr[i];
        cc=c+dc[i];
        if ( rr>=0 && rr<row && cc>=0 && cc<col && board[rr][cc]!='#' && !vis[rr][cc] ){
            ss+= flood(rr,cc);
        }
    }
    return ss;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&col,&row);

        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }
        CLR(vis);
        int ans=0;
        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j]=='@' ){
                    ans=flood( i,j );
                    i=j=25;
                }
            }
        }
        printf("Case %d: %d\n",kk,ans);
    }

    return 0;
}
