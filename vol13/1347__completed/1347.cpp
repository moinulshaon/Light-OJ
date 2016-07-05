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

#define MAX_N 15100

char str [MAX_N];
int N, m, SA [MAX_N], LCP [MAX_N];
int x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];

inline bool cmp (const int a, const int b, const int l) {
    return (y [a] == y [b] && y [a + l] == y [b + l]);
}

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
    for (int i = 1; i < N; ++i) SA [i - 1] = SA [i];
    --N;
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
    N = strlen (str);
    DA ();
    kasaiLCP ();
}

char tmp[MAX_N];
int dollar,hash;
int low ,high;

int cnt[3];

bool pos() {
    if ( cnt[0]>0 && cnt[1]>0 && cnt[2]>0 )return true;
    else return false;
}

int detect_region(int x) {
    if ( x<=dollar ) {
        return 0;
    } else if ( x>dollar && x<=hash ) {
        return 1;
    } else if ( x>hash && x<N) {
        return 2;
    }else{
        cout<<"shaon\n";
        exit(5);
    }
}

multiset<int> ss;

void changelow() {

    int rr = detect_region( SA[low] );

    cnt[ rr ]--;
    low++;
    if ( ss.find( LCP[low] ) != ss.end() )
        ss.erase( ss.find( LCP[low] ) );
}

void changehigh() {

    ++high;

    int rr = detect_region( SA[high] );

    //cout<<rr<<endl;
    cnt[ rr ]++;
    if ( high != low )
        ss.insert(LCP[high] );
}

int main() {

    FRO
    //freopen("out.txt","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1; kase--; ++kk) {
        scanf("%s",str);
        tmp[0]='$';
        dollar=strlen( str );
        scanf("%s",&tmp[1]);
        strcat( str,tmp );

        tmp[0]='#';
        hash=strlen( str );
        scanf("%s",&tmp[1]);
        strcat( str,tmp );

        //cout<<strlen(str)<<endl;

        suffixArray();

        /*
        for (int i=0;i<N;++i){
            printf("%d %s %d\n",i,&str[ SA[i] ],LCP[i]);
        }
        */

        int ans = 0;

        low = 0,high= -1;

        CLR(cnt);
        ss.clear();


        while ( low<N ) {

            //cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<low<<" "<<high<<endl;

            if (  pos() ) {
                /*
                cout<<low<<" "<<high<<" "<<endl;
                snuke ( ss,itr ){
                    cout<<*itr<<" ";
                }cout<<endl;
                */

                ans =max( ans , *ss.begin() );
                changelow();
            } else {
                if ( high+1<N )
                    changehigh();
                else
                    changelow();
            }
            //cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<low<<" "<<high<<endl;
            //exit(0);
        }

        printf("Case %d: %d\n",kk,ans);

    }


    return 0;
}
