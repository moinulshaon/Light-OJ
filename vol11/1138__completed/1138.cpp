#include <cstdio>
#include <cstring>

using namespace std;


int func( int x ){

    if ( x==0 )return 0;
    else return x/5+func(x/5);

}


int main(){
    int kase,n;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);

        int ans= -1;

        int low=1;
        int high=500000000;

        while (low<=high){
            int mid=(low+high)/2;
            int rr=func(mid);

            if ( rr==n ){
                ans=mid;
                high=mid-1;
            }else if ( n<rr ){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        if ( ans==-1 ){
            printf("Case %d: impossible\n",kk);
        }else{
            printf("Case %d: %d\n",kk,ans);
        }

    }
    return 0;
}
