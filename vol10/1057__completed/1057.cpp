#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <iostream>

using namespace std;
char board[25][25];

const int INF=100000000;

typedef pair<int,int> ppi;
map<ppi,int> mp;
ppi start;
ppi node[18];
int cnt;
int row,col;

int dis[18][18];
int d[18];

bool vis[25][25];

int dr[]={+1,+0,-1,-1,+1,+1,+0,-1,};
int dc[]={+1,+1,+1,+0,+0,-1,-1,-1};

void BFS( ppi start ,int *change){

    memset(vis,false,sizeof(vis));

    queue<ppi> q;
    queue<int> m;

    q.push( start );
    vis[ start.first ][ start.second ]=true;
    m.push(0);

    while( !q.empty() ){
        ppi tmp=q.front();q.pop();
        int f=m.front();m.pop();

        for (int i=0;i<8;++i){
            int r=tmp.first+dr[i];
            int c=tmp.second+dc[i];

            if ( c>=0 && c<col && r>=0 && r<row && !vis[r][c]  ){

                ppi me=make_pair(r,c);
                if (  board[r][c]== 'g' ){
                    change[ mp[me] ]=f+1;
                }
                vis[ r ][ c ]=true;
                q.push( me );
                m.push( f+1 );

            }
        }
    }
}

int set(int N,int pos){
    return N=N | (1<<pos);
}
int reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool check(int N,int pos){
    return (bool)(N & (1<<pos));
}


int dp[1<<18][18];

int func( int state,int now ){
    if ( state == (1<<cnt)-1 )return d[now];

    if ( dp[ state ][ now ] != -1 )return dp[ state ][ now ];

    int cost=INF;
    for (int i=0;i<cnt ;++i){
        if ( check(state,i)==0 ){
            cost= min( cost, dis[now][i]+func( set( state,i ),i ) );
        }
    }
    return dp[state][now]=cost;
}

int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk ){

        scanf("%d %d",&row,&col);
        for (int i=0;i<row;++i){
            scanf("%s",board[i]);
        }

        mp.clear();
        cnt=0;

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                if ( board[i][j]=='x' ){
                    start=make_pair( i,j );
                }else if( board[i][j]=='g' ) {
                    node[cnt]=make_pair( i,j );
                    mp[ node[cnt] ]=cnt;
                    //printf("%d %d\n", node[cnt] .first ,node[cnt] .second);
                    cnt++;
                }
            }
        }

        if ( cnt==0 ){
            printf("Case %d: 0\n",kk);
            continue;
        }

        for (int i=0;i<cnt;++i){
            d[i]=INF;
        }
        for (int i=0;i<cnt;++i){
            for (int j=0;j<cnt;++j){
                dis[i][j]=INF;
            }
        }

        BFS( start,d );
        for (int i=0;i<cnt;++i){
            BFS( node[i],dis[i] );
        }


        int rr=INF;
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<cnt ;++i){
            rr=min( rr, d[i] + func( set(0,i),i ) );
        }

        printf("Case %d: %d\n",kk,rr);
    }
    return 0;
}
