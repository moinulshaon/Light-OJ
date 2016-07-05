#include <cstdio>
#include <cstring>

int failure[1000100];

char encrypt[1000100],plain[1000100];
int len,sublen;

int Morris_Pratt(){
    if (sublen > len) return 0;


    for (int i=1, j=failure[0]= -1; i<sublen; ++i){
        while (j >= 0 && plain[j+1] != plain[i])
            j = failure[j];
        if (plain[j+1] == plain[i]) j++;
        failure[i] = j;
    }

    int ss=0;
    for (int i=0, j=-1; i<len; ++i){

        while (j >= 0 && plain[j+1] != encrypt[i])
            j = failure[j];

        if (plain[j+1] == encrypt[i]) j++;


        if (j == sublen-1){
            ss++;
            j = failure[j];
        }
    }
    return ss;
}


int main(){
    freopen("in.txt","r",stdin);
    char dd[100];
    gets(dd);
    int kase;
    sscanf(dd,"%d",&kase);

    for (int kk=1;kase--;++kk){
        gets(encrypt);
        gets(plain);



        len=strlen(encrypt);
        sublen=strlen(plain);

        printf("Case %d: %d\n",kk,Morris_Pratt());
    }
    return 0;
}
