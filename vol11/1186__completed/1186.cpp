#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

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
int white[500];

int main(){
    freopen("in.txt","r",stdin);
    int tmp,n,kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            white[i]=fastIn<int>();
        }
        int ans=0;
        for (int i=0;i<n;++i){
            tmp=fastIn<int>();
            ans^=tmp-white[i]-1;
        }
        if ( ans ){
            printf("Case %d: white wins\n",kk);
        }else{
            printf("Case %d: black wins\n",kk);
        }
    }
    return 0;
}
