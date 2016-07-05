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
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 50100

int failure[SIZE];
int dp[SIZE];

int len,sublen;

void Morris_Pratt(char *encrypt,char *plain,int *cnt){

    len = strlen(encrypt);
    sublen= strlen(plain);


    for (int i=1, j=failure[0]= -1; i<sublen; ++i){
        while (j >= 0 && plain[j+1] != plain[i])
            j = failure[j];
        if (plain[j+1] == plain[i]) j++;
        failure[i] = j;
    }

    dp[0] = 1;
    for (int i=1;i<sublen;++i){
        dp[i] = ( i != sublen-1 );
        if ( failure[i]>=0 )
            dp[i] += dp[ failure[i] ];
    }


    for (int i=0, j=-1; i<len; ++i){

        while (j >= 0 && plain[j+1] != encrypt[i])
            j = failure[j];

        if (plain[j+1] == encrypt[i]) j++;

        if ( j>=0 )
            cnt[i] = dp[j];

        if (j == sublen-1){
            j = failure[j];
        }
    }
}

int f_match[SIZE];
int b_match[SIZE];

char A[SIZE];
char B[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%s %s",A,B);
        len = strlen(A);
        sublen = strlen(B);

        for (int i=0;A[i];++i){
            f_match[i]=b_match[i] = 0;
        }

        Morris_Pratt(A,B,f_match);

/*
        for (int i=0;i<len;++i){
            cout<<f_match[i]<<endl;
        }
*/
        reverse( A,A+len );
        reverse( B,B+sublen );

        Morris_Pratt(A,B,b_match);

        reverse( b_match,b_match+len );
/*
        for (int i=0;i<len;++i){
            cout<<b_match[i]<<endl;
        }
*/
        LL ans = 0;
        for (int i=0;i+1<len;++i){
            ans += LL( f_match[i] )*b_match[i+1];
        }

        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}
