/*
 * Author  : Pallab
 * Program : 1126
 *
 * 2012-03-10 10:02:31
 * I have not failed, I have just found 10000 ways that won't work.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;


#define foR(i1,st,ed) for(int i1 = st , j1 = ed ; i1 < j1 ; ++i1 )
#define fo(i1,ed) foR( i1 , 0 , ed )
#define foE(i1,st,ed) foR( i1, st, ed+1 )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")
template<class T>
inline void debug(T _x) {
    cout<<_x<<'\n';
}
template<class T1, class T2>
inline void debug(T1 _x,T2 _y) {
    cout<<_x<<' '<<_y<<'\n';
}
template<class T1, class T2, class T3>
inline void debug(T1 _x,T2 _y,T3 _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
template<class T1, class T2, class T3, class T4>
inline void debug(T1 _x,T2 _y,T3 _z,T4 _zz) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<'\n';
}
inline bool CI(int &_x) {
    return scanf("%d",&_x)==1;
}
inline bool CI(int &_x, int &_y) {
    return CI(_x)&&CI(_y) ;
}
inline bool CI(int &_x, int &_y, int &_z) {
    return CI(_x)&&CI(_y)&&CI(_z) ;
}
inline bool CI(int &_x, int &_y, int &_z, int &_zz) {
    return CI(_x)&&CI(_y)&&CI(_z)&&CI(_zz) ;
}
const int mx=50;
const int maxn=500000;
const int inf=1023456789;
int N;
int w[mx];
inline void Read() {
    CI(N);
    fo(i,N) {
        CI(w[i]);
    }
}
/*
int dp[mx][maxsum+1];
int go(int at, int diff) {
    if (diff>maxsum) {
        return -inf;
    }

    if (at==N) {
        return diff==0 ? 0 : -inf ;
    }
    int &best=dp[at][diff];
    if (best!=-1)return best;

    best=-inf;
    //current ta na niye
    int a=go(at+1,diff);
    best=max(best,a);
    //prothom tower a bosay
    int b=go(at+1,diff+w[at]);
    best=max(best,b);

    //second tower a bosay
    if (w[at]>diff) {
        int c=diff+go(at+1,w[at]-diff);
        best=max(best,c);
    }
    else {
        int c=w[at]+go(at+1,diff-w[at]);
        best=max(best,c);
    }
    return best;
}
*/
int dp[2][maxn+1];
inline int solve() {
    int i,end,j,k,p;
    SET(dp,-1);
    dp[1][0]=p=end=0;
    for (int i=0;i<N;++i,p^=1) {
        memcpy(dp[p],dp[p^1],sizeof(dp[p]));
        end+=w[i];
        for (int j=0;j<=end;++j) {
            k=j+w[i];
            if (k<=end) {
                if ( dp[p^1][j]>=0 && dp[p][k]<dp[p^1][j]+w[i]) {
                    dp[p][j+w[i]]=dp[p^1][j]+w[i];
                }
            }
            k=abs(j-w[i]);
            if (k<=end) {
                if ( dp[p^1][j]>=0 && dp[p][k]<dp[p^1][j]+w[i]) {
                    dp[p][k]=dp[1^p][j]+w[i];
                }
            }
        }
    }
    if (dp[p^1][0])return dp[p^1][0]>>1;
    return -1;
}

inline void Proc() {
    int var=solve();
    if (var==-1) {
        puts("impossible");
    }
    else {
        cout<<var;
        line;
    }
}
int main() {
    freopen("in.txt","r",stdin);
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
