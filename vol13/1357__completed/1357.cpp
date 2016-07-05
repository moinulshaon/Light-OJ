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

#define SIZE 100010

vector<int> out[SIZE];

LL ans,black,vis;

void dfs(int x ){

    LL save=vis++;

    for (int i=0;i<out[x].size();++i){
        dfs( out[x][i] );
    }
    ans+= black - ( vis-save-1 );
    black++;
}

int main(){

    FRO

    input.grabBuffer();

    int kase=input.rInt();


    for (int kk=1;kase--;++kk){

        int v=input.rInt();

        for (int i=1;i<=v;++i){
            out[i].clear();
        }

        int x,y;
        for (int i=1;i<v;++i){
            x=input.rInt();
            y=input.rInt();

            out[x].PB(y);

        }


        ans=black=vis=0;

        dfs(1);

        printf("Case %d: %d %lld\n",kk,v-1,ans);
    }

    return 0;
}

