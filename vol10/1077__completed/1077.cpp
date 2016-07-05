#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long LL;

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}


int main(){

    int kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        LL x=fastIn<int>();
        LL y=fastIn<int>();

        x=abs( x- fastIn<int>() );
        y=abs( y- fastIn<int>() );

        printf("Case %d: %lld\n",kk,__gcd(x,y)+1);
    }
    return 0;
}
