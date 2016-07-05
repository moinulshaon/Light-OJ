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

const int maxBufSize = (7000000);

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
};
struct Output
{
	int bufSize, bufEnd, bufPos;
	char buffer[maxBufSize];
	Output() {bufPos = bufEnd = 0; bufSize = maxBufSize;}
	void print(int x) {
		if (x < 0) {
			print('-'); print(-x); return;
		}
		char temp[1 << 4]; int idx = 0;
		do {
			temp[idx++] = '0' + (x % 10);
			x /= 10;
		} while (x != 0);
		temp[idx] = '\0';
		reverse(temp, temp + idx);
		print(temp);
	}
	void printme(LL x) {
		if (x < 0) {
			print('-'); printme(-x); return;
		}
		char temp[1 << 4]; int idx = 0;
		do {
			temp[idx++] = '0' + (x % 10);
			x /= 10;
		} while (x != 0);
		temp[idx] = '\0';
		reverse(temp, temp + idx);
		print(temp);
	}
	inline void print(char ch) {buffer[bufEnd++] = ch;}
	inline void print(const char* s) {while (*s) buffer[bufEnd++] = *s++;}
	inline void print(const string& s) {print(s.c_str());}
	inline void flushBuffer() {buffer[bufEnd] = '\0'; printf("%s", buffer); bufEnd = 0;}
	template <class A, class B>
	void print(const A& a, const B& b) {print(a); print(b);}
	template <class A, class B, class C>
	void print(const A& a, const B& b, const C& c) {print(a); print(b); print(c);}
};

Output output;
Input input;

#define SIZE 100010

LL ans;
int n;
LL arr[SIZE];

int main(){
    FRO

    input.grabBuffer();

    int kase;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){
        int qq;
        n=input.rInt();
        qq=input.rInt();
        ans= 0;

        for (int i=0;i<n;++i){
            arr[i]=input.rInt();
            ans -= arr[i] * i - arr[i]* ( n-i-1 );
        }


        output.print("Case ");
        output.print(kk);
        output.print(":\n");
        int cc;
        int x;
        LL y;
        while ( qq-- ){
            cc=input.rChar();
            if ( cc== '1'  ) {
                output.printme(ans);
                output.print('\n');
            }else{
                x=input.rInt();
                y=input.rInt();
                ans += arr[x] * x - arr[x]* ( n-x-1 );
                arr[x]= y;
                ans -= arr[x] * x - arr[x]* ( n-x-1 );
            }
        }

    }
    output.flushBuffer();

    return 0;
}
