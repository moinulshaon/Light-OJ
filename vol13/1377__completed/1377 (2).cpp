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

const int maxBufSize = (6000000);

struct Input
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	void grabBuffer() {
		bufSize = (maxBufSize); bufPos = 0;
		bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
		buffer[bufEnd] = '\0';
	}
	bool bufEof() {return bufPos == bufEnd;}
	int getChar() {return buffer[bufPos++];}
	void skipWS() {
		while ((buffer[bufPos] == '\n' ||
			buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
			bufPos++;
	}
	int rInt() {
		int n = 0, x; skipWS();
		bool neg=false;
		if (  ( x = getChar() )=='-'  ){
            neg=true;
            x=getChar();
		}

		for (; x <= '9' && x >= '0'; x = getChar())
			n = (n << 3) + (n << 1) + (x - '0');
        if ( neg )return -n;
        else return n;
	}
	inline bool isWhiteSpace(char x) {
		return x == ' ' || x == '\n' || x == '\t';
	}
	char rChar() {skipWS(); return getChar();}
}input;

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


    for (int i=0;i<=row;++i){
        for (int j=0;j<=col;++j){
            vis[i][j][0]=vis[i][j][1]=false;
        }
    }

    char used=0;


    q.push( start );
    vis[ start.x ][start.y][start.nxt]=true;

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

    input.grabBuffer();

    int kase=input.rInt();

    for (int kk=1;kase--;++kk){
        row=input.rInt();
        col=input.rInt();

        int xx,yy;
        tel.clear();

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                board[i][j]=input.rChar();
                if ( board[i][j] == 'P' ){
                    xx=i,yy=j;
                }
                else if ( board[i][j] == '*' ){
                    tel.PB( make_pair(i,j) );
                }
            }
        }

        int ans=bfs(xx,yy);

        printf("Case %d: ",kk);
        if ( ans== -1 ){
            printf("impossible\n");
        }else{
            printf("%d\n",ans);
        }

    }


    return 0;
}
