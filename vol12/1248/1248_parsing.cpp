#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define SIZE 100010

double dp[SIZE];
const int maxBufSize = (1 << 22);

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

    dp[1]=1;
    for (int i=2;i<SIZE;++i ){
        dp[i]= dp[i-1]+ 1.0/ i ;
    }

    input.grabBuffer();

    int kase;
    kase=input.rInt();

    int n;
    for (int kk=1;kase--;++kk){

        n=input.rInt();
        printf("Case %d: %lf\n",kk,dp[n]*n);
    }
    return 0;
}
