#include <cstdio>
#include <cstring>
#include <algorithm>

#define SIZE 51000

using namespace std;

typedef long long LL;

int failure[SIZE];

int nxt[SIZE];
int len;

int findnxt( int x ){
    if ( x== len )return len;
    if ( nxt[x] != -1 )return nxt[x];
    else return nxt[x] = findnxt(x+1);
}

int pos(int x){
    return (x<0)?0:x;
}


int Morris_Pratt(char *encrypt,char *plain){

    int sublen=strlen(plain);

    if (sublen > len) return len;

    for (int i=1, j=failure[0]= -1; i<sublen; ++i){
        while (j >= 0 && plain[j+1] != plain[i])
            j = failure[j];
        if (plain[j+1] == plain[i]) j++;
        failure[i] = j;
    }


    for (int i=0, j=-1; i<len; ++i){

        while (j >= 0 && plain[j+1] != encrypt[i])
            j = failure[j];

        if (plain[j+1] == encrypt[i]) j++;


        if (j == sublen-1){

            nxt[i-j]=i;
            //j= -1 ;
        }
    }

    return len;
}
#define MAX_N 51000

char str [MAX_N],sub[MAX_N];
int N, m, SA [MAX_N], LCP [MAX_N];
int x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];

inline bool cmp (const int a, const int b, const int l) { return (y [a] == y [b] && y [a + l] == y [b + l]); }

void Sort () {
    for (int i = 0; i < m; ++i) w [i] = 0;
    for (int i = 0; i < N; ++i) ++w [x [y [i]]];
    for (int i = 0; i < m - 1; ++i) w [i + 1] += w [i];
    for (int i = N - 1; i >= 0; --i) SA [--w [x [y [i]]]] = y [i];
}

void DA () {
    ++N;
    for (int i = 0; i < N; ++i) x [i] = str [i], y[i] = i;
    Sort ();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
        for (p = 0, i = N - j; i < N; i++) y [p++] = i;
        for (int k = 0; k < N; ++k) if (SA [k] >= j) y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i) x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
    for (int i = 1; i < N; ++i) SA [i - 1] = SA [i]; --N;
}

void kasaiLCP () {
    for (int i = 0; i < N; ++i) c [SA [i]] = i;
    LCP [0] = 0;
    for (int i = 0, h = 0; i < N; ++i)
        if (c[i] > 0) {
            int j = SA [c [i] - 1];
            while (i + h < N && j + h < N && str [i + h] == str [j + h]) ++h;
                LCP [c [i]] = h;
            if (h > 0) --h;
        }
}

LL suffixArray () {
    m = 256;
    len=N = strlen (str);
    DA ();
    kasaiLCP ();

    memset(nxt,-1,sizeof(nxt));

    Morris_Pratt( str,sub );

    LL sum=0;
    for (int i=0;i<len;++i){
        sum=sum+ pos( -LCP[i]+ findnxt( SA[i] )-SA[i] );
        //printf("%s %d %d %d\n",&A[ B[i] ],len-B[i],LCP[i],len-B[i]-Morris_Pratt(&A[ B[i] ],sub) );
        //printf("%d\n",sum);
    }
    return sum;
}



int main(){
    freopen("in.txt","r",stdin);

    char mmmm[100];
    gets(mmmm);
    int kase;
    sscanf(mmmm,"%d",&kase);

    for (int kk=1;kase--;++kk){
        gets(str);
        gets(sub);

        //printf("%d\n",Morris_Pratt(line,sub));
        printf("Case %d: %lld\n",kk,suffixArray());
    }
    return 0;
}
