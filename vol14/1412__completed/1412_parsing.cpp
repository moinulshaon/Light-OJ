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

#define SIZE 100100

const int maxBufSize = (8000000);

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
	inline void print(char ch) {buffer[bufEnd++] = ch;}
	inline void print(const char* s) {while (*s) buffer[bufEnd++] = *s++;}
	inline void print(const string& s) {print(s.c_str());}
	inline void flushBuffer() {buffer[bufEnd] = '\0'; printf("%s", buffer); bufEnd = 0;}
	template <class A, class B>
	void print(const A& a, const B& b) {print(a); print(b);}
	template <class A, class B, class C>
	void print(const A& a, const B& b, const C& c) {print(a); print(b); print(c);}
}output;

int parent [SIZE];
int sz[SIZE];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}
void makeUnion(int x,int y){
    int p = parentOf ( x );
    int q = parentOf ( y );

    if ( p != q ) {
        if (sz[p]>sz[q])swap(p,q);
        sz[q]+=sz[p];
        parent [p] = q;
    }
}


vector<int> out[SIZE];

pint dfs1( int x,int p ){

    pint tt,tmp=make_pair( 0,x );
    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != p ){
            tt=dfs1( out[x][i] , x);
            tt.first++;

            if ( tt.first >tmp.first ){
                tmp=tt;
            }
        }
    }
    return tmp;
}

int dfs2( int x,int p ){


    int tt,tmp=0 ;
    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != p ){
            tt=dfs2( out[x][i] , x)+1;

            if ( tt>tmp ){
                tmp=tt;
            }
        }
    }
    return tmp;
}

int diameter(int x){

    pint tmp=dfs1(x,0);
    return dfs2( tmp.second,0 );
}

int ans[SIZE];
void calc(int x){

    int d=diameter(x);
    int ss= sz[x];

    for (int i=1;i<=ss;++i){
        if ( i<= d+1 ){
            ans[i]=min(ans[i],i-1);
        }else{
            ans[i]=min(ans[i],2*(i-1)-d);
        }
    }

}

int main(){
    FRO

    input.grabBuffer();

    int kase;
    kase=input.rInt();

    for (int kk=1;kase--;++kk){
        int v,e;
        v=input.rInt();
        e=input.rInt();

        for (int i=1;i<=v;++i){
            parent [i] = i;
            sz[i]=1;
            out[i].clear();
        }

        int x,y;
        for (int i=0;i<e;++i){
            x=input.rInt();
            y=input.rInt();

            makeUnion(x,y);

            out[x].PB(y);
            out[y].PB(x);
        }

        memset(ans,63,sizeof(ans));

        for (int i=1;i<=v;++i){
            if ( parentOf(i) == i ){
                calc(i);
            }
        }

        output.print("Case ");
        output.print(kk);
        output.print(":\n");

        int qq;
        qq=input.rInt();

        while( qq-- ){
            x=input.rInt();
            if ( ans[x] <100000000 ){
                output.print( ans[x] );
                output.print("\n");
            }else{
                output.print("impossible\n");
            }
        }
    }
    output.flushBuffer();

    return 0;
}
