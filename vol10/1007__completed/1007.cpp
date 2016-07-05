#include <cstdio>
#define size 5000001

using namespace std;

unsigned long long phi[size];
bool prime[size];

int main()
{

    //freopen("in.txt","r",stdin);

    for (int i=2;i<size;++i){
        prime[i]=true;
        phi[i]=i;
    }
    phi[1]=1;
    for (int i=2;i<size;++i)
        if (prime[i]){
            phi[i]=i-1;
            for (int j=i*2;j<size;j+=i){
                prime[j]=false;
                phi[j]=phi[j]/i*(i-1);
            }
        }

    for (int i=1;i<size;++i){
        phi[i]=phi[i-1]+phi[i]*phi[i];
    }

    int a,b,kase;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",kk,phi[b]-phi[a-1]);
    }
    return 0;

}
