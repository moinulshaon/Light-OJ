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

#define SIZE 55

int dis[SIZE][SIZE];
int node;
bool vis[SIZE];
int mind[SIZE];

int prim(int start){

    memset(vis,false,sizeof(vis));
    vis[start]=true;

    for (int i=0;i<node;++i){
        mind[i]=dis[start][i];
    }
    int ans=0;

    for (int i=1;i<node;++i){
        int mn=(1<<29),x= -1;

        for (int j=0;j<node;++j){
            if ( !vis[j] && mind[j] && mind[j]<mn ){
                mn=mind[j];
                x=j;
            }
        }
        //printf("prim %d\n",x);
        if ( x == -1 )return -1;

        vis[x]=true;
        ans+= mind[x];

        for (int j=0;j<node;++j){
            if ( !vis[j] && dis[x][j] &&( dis[x][j]<mind[j] || !mind[j]) ){
                mind[j]=dis[x][j];
            }
        }
    }
    return ans;
}

const int maxBufSize = (4000000);

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

int main(){
    FRO

    input.grabBuffer();
    int kase;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){

        node=input.rInt();
        int total=0;
        for (int i=0;i<node;++i){
            for (int j=0;j<node;++j){
                dis[i][j]=input.rInt();
                total+=dis[i][j];
            }
        }

        int ans=0;
        for (int i=0;i<node;++i){
            for (int j=i+1;j<node;++j){
                if ( dis[i][j] && dis[j][i] ){
                    dis[i][j]=dis[j][i]=min( dis[i][j], dis[j][i] );
                }else{
                    dis[i][j]=dis[j][i]=max( dis[i][j], dis[j][i] );
                }
            }
        }

        for (int i=0;i<node;++i){
            if ( dis[i][i] ){
                dis[i][i]=0;
            }
        }
        int tt=prim(0);

        if ( tt != -1 ){
            tt=total-tt;
        }
        printf("Case %d: %d\n",kk,tt);

    }


    return 0;
}
