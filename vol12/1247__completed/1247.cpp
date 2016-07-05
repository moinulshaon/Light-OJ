#include <cstdio>

using namespace std;

int main(){

    int kase,m,n,ans,a,b;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&m,&n);
        ans=0;
        while ( m-- ){
            a=0;
            for (int i=0;i<n;++i){
                scanf("%d",&b);
                a+=b;
            }
            //printf("sjaoh\n");
            ans^=a;
        }
        printf("Case %d: ",kk);
        if ( ans ){
            puts("Alice");
        }else{
            puts("Bob");
        }
    }
    return 0;

}
