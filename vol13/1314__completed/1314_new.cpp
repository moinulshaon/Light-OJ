#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define SIZE 10100

char str[SIZE];
int len;

bool cmp(const int &a,const int &b){
    return strcmp(&str[a],&str[b])<=0;
}
int lcp[SIZE];

int getlcp( int a,int b ){
    int lena=len-a;
    int lenb=len-b;
    int len=( lena<lenb )?lena:lenb;
    int same;
    for (same=0;same<len;++same)
        if (str[a+same]!=str[b+same])
            return same;
    return same;
}


int pos(int n){
    return (n<0)?0:n;
}

int main(){
    freopen("in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s",str);
        len=strlen(str);

        vector<int> suffix;
        for (int i=0;i<len;++i){
            suffix.push_back(i);
        }
        sort(suffix.begin(),suffix.end(),cmp );

        lcp[0]=0;
        for (int i=1;i<len;++i){
            lcp[i]=getlcp(suffix[i],suffix[i-1]);
        }



        int left,right;
        scanf("%d %d",&left,&right);

        int rr=pos( min( len-suffix[0] ,right )- left+1 );
        for (int i=1;i<len;++i){
            rr+=pos(  min( len-suffix[i] ,right )-max(left,1+lcp[i]) + 1 );
        }
        printf("Case %d: %d\n",kk,rr);
    }
    return 0;

}
