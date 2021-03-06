#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

#define SIZE 100100

int arr[SIZE],arr2[SIZE];
int inter[SIZE];
int fromLeft[SIZE],fromRight[SIZE];
int n;


void LIS(int seq[],int save[]){

    for (int i=0;i<=n;++i){
        inter[i]=INT_MIN;
    }

    int lis=0,low,high,mid;

    for (int i=1;i<=n;++i){
        low=0;
        high=lis;

        while (low<=high){
            mid=(low+high)>>1;
            if (seq[i] <= inter[mid] )high=mid-1;
            else low=mid+1;
        }

        inter[low]=seq[i];

        save[i]=low;
        if ( low>lis )lis=low;
    }

}


int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);

        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            arr2[n-i+1]=arr[i];
        }

        LIS(arr,fromLeft);

        LIS(arr2,fromRight);
        /*
        for (int i=1;i<=n;++i){
            printf("%3d",fromLeft[i]);
        }
        printf("\n");
        for (int i=1;i<=n;++i){
            printf("%3d",fromRight[n-i+1]);
        }
        printf("\n");
        */

        int ans=1,tmp;
        for (int i=1;i<=n;++i){
            tmp=min( fromLeft[i]-1,fromRight[n-i+1]-1 );
            if ( 2*tmp+1>ans ){
                ans=2*tmp+1;
            }
        }
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}
