#include <cstdio>
#include <vector>
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


int main(){
    //freopen("in.txt","r",stdin);
    int kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
            int n=fastIn<int>();
            int r=fastIn<int>();

            n -=r;

            int tmp=sqrt(n);
            vector<int> rr;
            for (int i=1;i<=tmp;++i){
                if ( n%i==0 ){
                    if ( n/i>r )
                        rr.push_back(n/i);
                    if ( i>r && n/i!=i )
                        rr.push_back(i);
                }
            }

            sort(rr.begin(),rr.end());
            printf("Case %d:",kk);
            tmp=rr.size();
            if ( !tmp ){
                printf(" impossible\n");
                continue;
            }
            for (int i=0;i<tmp;++i){
                printf(" %d",rr[i]);
            }
            printf("\n");
    }
    return 0;
}
