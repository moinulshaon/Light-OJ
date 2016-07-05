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

#define MP make_pair
#define X first
#define Y second

int dim;

char board[15][15];
pint pos[30];

bool vis[15][15];

int dr[]={-1,0,1,0};
int dc[]={0,-1,0,1};

int bfs( pint start,pint end ,char cc){

    queue<pint> q;
    queue<int> move;


    CLR(vis);

    q.push( start );
    move.push(0);
    vis[start.X][start.Y]=true;
    //cout<<cc<<endl;
    pint save;
    while( !q.empty() ){

        pint tmp=q.front();q.pop();
        int mm=move.front();move.pop();

        for (int i=0;i<4;++i){
            save.X=tmp.X+dr[i];
            save.Y=tmp.Y+dc[i];

            if ( save.X>=0 && save.X<dim && save.Y>=0 && save.Y<dim && !vis[save.X][save.Y]
                 && ( board[save.X][save.Y]=='.' || board[save.X][save.Y]==cc ) ){
                if ( save==end )return mm+1;

                q.push( save );
                move.push(mm+1);
                vis[save.X][save.Y]=true;
            }

        }
    }
    return -1;

}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&dim);

        for (int i=0;i<dim;++i){
            scanf("%s",board[i]);
        }

        int mx=0;
        for (int i=0;i<dim;++i){
            for (int j=0;j<dim;++j){
                if ( board[i][j] >='A' && board[i][j] <='Z' ){
                    mx=max( mx, board[i][j]-'A');
                    pos[ board[i][j]-'A' ]=MP( i,j );
                }
            }
        }

        int ans=0,des=mx;
        for( int i=0;i<mx;++i ){
            int tmp=bfs( pos[i],pos[i+1],i+1+'A');
            if ( tmp== -1 ){
                ans=-1;
                break;
            }
            ans+=tmp;
            board[ pos[i].X ][ pos[i].Y ]='.';
        }
        printf("Case %d: ",kk);
        if ( ans== -1 ){
            printf("Impossible\n");
        }else{
            printf("%d\n",ans);
        }
    }


    return 0;
}
