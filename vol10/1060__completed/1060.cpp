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

LL fact[21];
char str[22];
char ans[22];

int main(){

    fact[0] = 1;
    for (int i=1;i<21;++i){
        fact[i] = fact[i-1] * LL(i);
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        LL tar;
        scanf("%s %lld",str,&tar);
        n = strlen(str);


        int cnt[26]={0};

        for (int i=0;i<n;++i){
            cnt[ str[i]-'a' ]++;
        }
        int have = n;

        int len = 0;
        for ( int i=0;i<n;++i ){
            for (int j=0;j<26;++j){
                if ( cnt[j] > 0 ){
                    LL tmp = fact[have-1];
                    for (int k=0;k<26;++k){
                        tmp/= fact[ cnt[k]- ( k == j ) ];
                    }
                    if (  tar <= tmp ){
                        ans[ len++ ] = j+'a';
                        cnt[ j ]--;
                        have--;
                        break;
                    }else{
                        tar -= tmp;
                    }
                }
            }
        }

        ans[len++]='\0';

        printf("Case %d: ",kk);
        if ( len-1 != n )printf("Impossible\n");
        else printf("%s\n",ans);

    }

    return 0;
}
