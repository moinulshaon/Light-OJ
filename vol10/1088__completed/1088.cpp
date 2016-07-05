#include <cstdio>
#include <cstring>

using namespace std;

int arr[101000];
int n;

int search(int x,int cc){

    int low=0,high=n-1;

    while (low<=high){
        int mid=(low+high)/2;
        if ( arr[mid]==x ){
            if ( cc==1 )return mid;
            else return mid+1;
        }
        else if (x> arr[mid] ) {
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if ( cc==1 ){
        return high+1;
    }else{
        return low;
    }
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int q;
        scanf("%d %d",&n,&q);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        int a,b,x,y;
        printf("Case %d:\n",kk);
        while ( q-- ){
            scanf("%d %d",&a,&b);
            x=search(a,1);
            y=search(b,2);

            //printf("%d %d\n",x,y);

            printf("%d\n",y-x);
        }
    }
    return 0;

}
