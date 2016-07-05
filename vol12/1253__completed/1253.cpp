#include <cstdio>
#include <cstring>
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


int main(){
    freopen("in.txt","r",stdin);
    int kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        int tmp,ans=0,n=fastIn<int>();
        bool alllessone=true;
        while(n--){
            tmp=fastIn<int>();
            ans^= tmp;
            if ( tmp>1 ){
                alllessone=false;
            }
        }
        if ( (!ans && !alllessone) || (ans && alllessone)  ){
            printf("Case %d: Bob\n",kk);
        }else{
            printf("Case %d: Alice\n",kk);
        }
    }
    return 0;
}
