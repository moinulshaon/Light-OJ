#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[110];
double pr[110];

int main(){
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        for (int i=0;i<n;++i){
            pr[i]=0;
        }
        pr[0]=1;
        for (int i=0;i<n;++i){
            int ll=min(6,n-i-1);
            for (int j=1;j<=ll;++j){
                pr[i+j]+=pr[i]/ll;
            }
        }

        double ans=0;
        for (int i=0;i<n;++i){
            ans+=pr[i]*arr[i];
        }
        printf("Case %d: %.7lf\n",kk,ans);
    }
    return 0;
}
