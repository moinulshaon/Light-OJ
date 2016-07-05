#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

int step;
int n,arr[1010];

bool ispos(int perday){
    int start=0;
    for ( int day=0;day<=step && start<=n ;++day ){
        int sum=0;
        for (int j=start;j<=n;++j){
            sum+=arr[j];
            if ( sum>perday )break;
            start++;
        }
    }
    return start>=n+1;
}

int result[1010];
void undoing(int ans){
    CLR(result);

    int start=0;

    for (int day=0;day<=step && start<=n ;++day ){
        int sum=0;
        for (int j=start;j<=n;++j){
            sum+=arr[j];
            if ( sum>ans )break;

            start++;
            result[day]=sum;
        }
    }
}

void prnt(int ans){

    CLR(result);

    int start=0;

    for (int day=0;day<=step && start<=n ;++day ){
        int sum=0;
        for (int j=start;j<=n;++j){
            sum+=arr[j];
            if ( sum>ans )break;

            start++;
            result[day]=sum;
        }
    }

    int left=-1;

    for (int i=0;i<=step;++i){
        if ( result[i] ){
            left=i;
        }
    }

    int ptr=n;
    for (int i=step;i>=0 && left>=0 && ptr>=0 ;--i){
        if ( result[i]==0 ){
            result[i]=arr[ptr];
            result[ left ] -= arr[ptr];
            --ptr;

            if ( result[ left ] ==0  )left--;
        }
    }

    if ( result[0] == 0 )undoing(ans);

}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&n,&step);

        for (int i=0;i<=n;++i){
            scanf("%d",&arr[i]);
        }
        int ans= -1;
        int low=0,high=(1<<29);
        while(low<=high){
            int mid=(low+high)/2;
            if ( ispos(mid) ){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        printf("Case %d: %d\n",kk,ans);
        prnt(ans);
        //printf("%d\n",n);
        for (int i=0;i<=step;++i){
            printf("%d\n",result[i]);
        }
    }


    return 0;
}
