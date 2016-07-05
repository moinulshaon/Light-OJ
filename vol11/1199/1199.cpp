#include <cstdio>
#include <cstring>

using namespace std;

#define sz 10010

int grundy[sz];

void findGrundy(int n){

    bool state[1000]={false};
    int lim=(n&1)?(n/2):(n-2)/2;
    for (int i=1 ; i<=lim ; ++i ){
        if ( grundy[i]== -1 )
            findGrundy(i);
        if ( grundy[n-i]== -1 )
                findGrundy(n-i);
        //printf("%d %d %d\n",i,n-i,n);
        state[ grundy[i]^grundy[n-i] ]=true;
    }
    for (int i=0;i<1000;++i){
        if ( !state[i] ){
            grundy[n]=i;
            return ;
        }
    }

}

int main(){

    grundy[0]=grundy[1]=0;

    int kase,n,a,ans;
    scanf("%d",&kase);
    //kase=0;

    memset(grundy,-1,sizeof(grundy));

    for (int i=0;i<10000;++i){
        if ( grundy[i]== -1 )
            findGrundy(i);
    }

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        ans=0;
        while (n--){
            scanf("%d",&a);
            if ( grundy[a]== -1 )
                findGrundy(a);

            ans^=grundy[a];
        }
        if ( ans )
            printf("Case %d: Alice\n",kk);
        else{
            printf("Case %d: Bob\n",kk);
        }
    }
    return 0;

}
