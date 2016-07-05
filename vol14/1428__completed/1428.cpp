#include <cstdio>
#include <cstring>
#include <algorithm>

#define SIZE 51000
#define MAXLG 20

using namespace std;

typedef long long LL;

int failure[SIZE];

int nxt[SIZE];
int len;
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


struct entry
{
    int first, second, p;
} L[SIZE];
int P[MAXLG][SIZE];
int LCP[SIZE];
int step;
int B[SIZE];

int cmp(const struct entry &a, const struct entry &b)
{
    return a.first == b.first ? (a.second < b.second ? 1 : 0) : (a.first < b.first ? 1 : 0);
}

int comp2(const int& a, const int& b)
{
	return P[step-1][a] < P[step-1][b];
}

char line[SIZE];
char sub[SIZE];

int pos(int x){
    return (x<0)?0:x;
}

int findnxt( int x ){
    if ( x== len )return len;
    if ( nxt[x] != -1 )return nxt[x];
    else return nxt[x] = findnxt(x+1);
}

LL suffixArray(char *A)
{
    int i, count;
    len = strlen(A);

    for (i = 0; i < len; i ++)
        P[0][i] = A[i] - 'a';

    for (step = 1, count = 1; count>>1 < len; step++, count <<= 1){
    	for (i = 0; i < len; i++){
			L[i].first = P[step - 1][i];
			L[i].second = i + count < len ? P[step - 1][i + count] : -1;
			L[i].p = i;
    	}

 		sort(L, L + len, cmp);

        for (i = 0; i < len; i ++)
            P[step][L[i].p] = i > 0 && L[i].first == L[i - 1].first && L[i].second == L[i - 1].second ?
				P[step][L[i - 1].p] : i;
    }

    for(i = 0; i < len; i++) B[i] = i;
    sort(B, B + len, comp2);

    for(i = 1; i < len; i++)
    {
	    int k;
	    int x = B[i], y = B[i - 1];

	    LCP[i] = 0;
	    for (k = step - 1; k >= 0 && x < len && y < len; k--)
	        if (P[k][x] == P[k][y])
	            x += 1 << k, y += 1 << k, LCP[i] += 1 << k;
    }
    /*
    for(i = 0; i < len; i++)
    	cout << LCP[i] << ' ';
    cout << endl;*/

    memset(nxt,-1,sizeof(nxt));
    Morris_Pratt( A,sub );

    LL sum=0;
    for (int i=0;i<len;++i){
        sum=sum+ pos( -LCP[i]+ findnxt( B[i] )-B[i] );
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
        gets(line);
        gets(sub);

        //printf("%d\n",Morris_Pratt(line,sub));
        printf("Case %d: %lld\n",kk,suffixArray(line));
    }
    return 0;
}
