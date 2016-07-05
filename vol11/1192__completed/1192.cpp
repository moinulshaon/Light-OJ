#include <cstdio>

using namespace std;

int main(){

    int kase,n,a,b,ans;
    scanf("%d",&kase);


    for (int kk=1;kase--;++kk){
        scanf("%d",&n);

        ans=0;
        while ( n-- ){
            scanf("%d %d",&a,&b);
            ans^= b-a-1;
        }
        if ( ans ){
            printf("Case %d: Alice\n",kk);
        }else{
            printf("Case %d: Bob\n",kk);
        }
    }
    return 0;

}
