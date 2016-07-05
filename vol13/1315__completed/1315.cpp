#include <cstdio>
#include <cstring>

using namespace std;


#define sz 510

int grundy[sz][sz];


int dc[]={-2,-3,-2,-1,-1,1};
int dr[]={1,-1,-1,-2,-3,-2};
void findGrundy( int a,int b ){

    bool state[10]={false};
    int c,d;
    for (int i=0;i<6;++i){
        c=a+dr[i];
        d=b+dc[i];
        if ( c>=0 && c<sz && d>=0 && d<sz ){

            if ( grundy[c][d]== -1 ){
                findGrundy(c,d);
            }
            state[ grundy[c][d] ]=true;

        }

    }
    for (int i=0;i<10;++i){
        if ( !state[i] ){
            grundy[a][b]=i;
            return ;
        }
    }


}


int main(){

    memset(grundy,-1,sizeof(grundy));
    grundy[0][0]=0;

    int kase,n,a,b,ans;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        ans=0;
        scanf("%d",&n);
        while (n--){
            scanf("%d %d",&a,&b);
            if ( grundy[a][b]== -1 ){
                findGrundy(a,b);
                //printf("%d %d %d\n",a,b,grundy[a][b]);
            }
            ans^=grundy[a][b];
        }
        if ( ans ){
            printf("Case %d: Alice\n",kk);
        }else{
            printf("Case %d: Bob\n",kk);
        }

    }
    return 0;

}
