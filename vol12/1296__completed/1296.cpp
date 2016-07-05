#include <cstdio>
#include <cstring>

using namespace std;

int findGrundy(int n){
    if ( n & 1 )return findGrundy(n/2);
    else return n/2;
}

int main(){

    int ans,n,a,kase,cc=0;
    scanf("%d",&kase);

    while (kase--){
        ans=0;
        scanf("%d",&n);
        while (n--){
            scanf("%d",&a);
            ans^=findGrundy(a);
        }
        if ( ans ){
            printf("Case %d: Alice\n",++cc);
        }else{
            printf("Case %d: Bob\n",++cc);
        }


    }
    return 0;

}
