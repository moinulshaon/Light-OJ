#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

#define SIZE 105

using namespace std;

struct mm{
    int match;
    int yet;
    vector<int> serial;
    int nxt(){
        return serial[yet++];
    }
}men[SIZE];
struct wo{
    int match;
    map<int,int> prefer;
}women[SIZE];
int n;

int main(){
    freopen("in.txt","r",stdin);
    int kase,a;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            men[i].match= -1;
            men[i].yet=0;
            men[i].serial.clear();

            for (int j=1;j<=n;++j){
                scanf("%d",&a);
                a-=n;
                men[i].serial.push_back(a);
            }
        }
        for (int i=1;i<=n;++i){
            women[i].match= -1;
            women[i].prefer.clear();

            for (int j=1;j<=n;++j){
                scanf("%d",&a);
                women[i].prefer[a]=n-j+1;
            }
        }

        for (int i=1;i<=n;){
            //printf("%d\n",i);

            if ( men[i].match == -1 ){
                int lady=men[i].nxt();
                if (women[ lady ].match == -1  ){
                    women[ lady ].match=i;
                    men[i].match=lady;
                }else{
                    if (  women[lady].prefer[i] > women[lady].prefer[  women[lady].match ]  ){

                        men[ women[lady].match  ].match = -1;

                        men[i].match=lady;

                        int tmp=women[lady].match;
                        women[lady].match=i;
                        i=min(i,tmp);
                    }
                }
            }else{
                ++i;
            }
            /*
            for (int i=1;i<=n;++i){
                printf(" (%d %d) %d   ",i,(men[i].match==-1)?-1:men[i].match+n,men[i].yet);
            }
            printf("\n");*/
        }

        printf("Case %d:",kk);
        for (int i=1;i<=n;++i){
            printf(" (%d %d)",i,men[i].match+n);
        }
        printf("\n");

    }
    return 0;
}
