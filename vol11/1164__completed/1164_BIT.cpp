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

#define SIZE 110000

LL dataMul[SIZE];
LL dataAdd[SIZE];

int length;

void internalUpdate(int ind, int mul, int add) {
    while (ind < length) {
        dataMul[ind] += mul;
        dataAdd[ind] += add;
        ind |= (ind + 1);
    }
}

void update(int left, int right, int by) {
    internalUpdate(left, by, -by * (left - 1));
    internalUpdate(right, -by, by * right);
}



LL read(int ind){
    LL mul = 0;
    LL add = 0;
    int start = ind;
    while (ind >= 0) {
        mul += dataMul[ind];
        add += dataAdd[ind];
        ind = (ind & (ind + 1)) - 1;
    }
    return mul * start + add;
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
    int kase,qq,a,b,c,d;

    kase=input.rInt();

    for (int kk=1;kase--;++kk){
        length=input.rInt();
        qq=input.rInt();

        memset(dataAdd,0,sizeof(LL)*(length+1));
        memset(dataMul,0,sizeof(LL)*(length+1) );
        printf("Case %d:\n",kk);
        while( qq-- ){
            a=input.rInt();
            if ( a ){
                b=input.rInt();
                c=input.rInt();
                printf("%lld\n",read(c)-read(b-1));
            }else{
                b=input.rInt();
                c=input.rInt();
                d=input.rInt();
                update( b,c,d );
            }
        }
    }

    return 0;
}
