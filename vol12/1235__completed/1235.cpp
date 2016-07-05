#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

int SET(int N,int pos){
    return N=N | (1<<pos);
}
int RESET(int N,int pos){
    return N= N & ~(1<<pos);
}
bool CHECK(int N,int pos){
    return (bool)(N & (1<<pos));
}


int arr[20];
int pp[20];

int main(){


    int kase;
    scanf("%d",&kase);
    pp[0]=1;
    for (int i=1;i<20;++i){
        pp[i]=pow(3,i)+1e-6;
    }

    for (int kk=1;kase--;++kk){
        int n,k;
        scanf("%d %d",&n,&k);

        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }


        int tmp=pp[n/2];
        set<int> ss;
        for (int i=0;i<tmp ;++i){
            int sum=0;
            for (int j=0;j<n/2 ;++j){
                sum+= arr[j]*( (i%pp[j+1]) / pp[j] ) ;
            }
            ss.insert(sum);
            //printf("%d\n",sum);
            //if ( ss.find(k-sum) != ss.end() )pos=true;
        }

         bool pos=false;
         int shaon=n-n/2;
         tmp=pp[shaon];

         for (int i=0;i<tmp && !pos ;++i){
            int sum=0;
            for (int j=0;j<shaon ;++j){
                sum+= arr[n/2+j]*( (i%pp[j+1]) / pp[j] ) ;
            }
            ss.insert(sum);
            //printf("%d\n",sum);
            if ( ss.find(k-sum) != ss.end() )pos=true;
        }

        if ( pos ){
            printf("Case %d: Yes\n",kk);
        }else{
            printf("Case %d: No\n",kk);
        }
    }
    return 0;
}
