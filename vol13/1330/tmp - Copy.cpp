/*
 * Author  : Pallab
 * Program : 1330
 *
 * 2012-02-28 23:45:33
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

inline void debug(int _x) {
    cout<<_x<<'\n';
}
inline void debug(int _x,int _y) {
    cout<<_x<<' '<<_y<<'\n';
}
inline void debug(int _x,int _y,int _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
inline void debug(int _x,int _y,int _z,int _zz) {
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

int R,C;
int row[51];
int col[51];
int ones;
inline void Read() {
    CI(R,C);
    //row sum
    fo(i,R) {
        CI(row[i]);
    }
    //col sum
    fo(i,C) {
        CI(col[i]);
    }
}

const int mx=(50<<1)+5;
int cap[mx][mx],source,sink,flow[mx][mx];
const int inf=1;
vector<int>E[mx];
inline void build_flowgraph() {
    fo(i,mx) {
        E[i].clear();
    }
    SET(cap,0);
    //row=>col
    fo(i,R) {
        fo(j,C) {
            cap[i][R+j]=inf;
            E[i].pb(R+j);
            E[R+j].pb(i);
            //    debug(i,R+j);
        }
    }
    source=R+C;
    sink=R+C+1;
//  debug(source,sink,N);
    //source=>row
    fo(i,R) {
        cap[source][i]=row[i];
        E[source].pb(i);
        E[i].pb(source);
    }
    //column=>sink
    fo(j,C) {
        cap[R+j][sink]=col[j];
        E[R+j].pb(sink);
        E[sink].pb(R+j);
    }
}
int used[mx];
int from[mx];
inline void bfs(int src, int snk) {
    SET(used,0);
    SET(from,-1);
    queue<int>q;
    q.push(src);
    used[src]=1;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        fo(i,SZ(E[u])) {
            int v=E[u][i];
            if ( used[v]==0) {
                if ( v==sink||v==source||u==source||u==sink ) {
                    if (cap[u][v]-flow[u][v]>0) {
                        used[v]=1;
                        from[v]=u;
                        q.push(v);
                        if (v==snk)return ;
                    }
                }
                else if ( flow[u][v]<1&&cap[u][v]-flow[u][v]>0) {
                    used[v]=1;
                    from[v]=u;
                    q.push(v);
                    if (v==snk)return ;
                }
            }
        }
    }
    return ;
}
inline int augument(int src,int snk) {
    bfs(src,snk);
    if (from[snk]==-1)return 0;
    int v=snk;
    int mnflow=inf;
    while (from[v]!=-1) {
        int u=from[v];
        mnflow=min(mnflow,cap[u][v]-flow[u][v]);
        v=u;
    }
    v=snk;
    mnflow=min(1,mnflow);
    while (from[v]!=-1) {
        int u=from[v];
        flow[u][v]+=mnflow;
        flow[v][u]-=mnflow;
        v=u;
    }
    return mnflow;
}
inline int maxflow() {
    SET(flow,0);
    int tf=0;
    while (1) {
        int cf=augument(source,sink);
        if (cf==0)break;
        tf+=cf;
    }
    return tf;
}
inline bool checkNice() {
    ones=0;
    int a=0;
    fo(i,R) {
        a+=row[i];
        ones+=row[i];
    }
    fo(j,C) {
        a-=col[j];
    }
    return (a==0);
}
int res[mx][mx];
inline void Print() {
    int i,j;
    for (i=0;i<R;++i) {
        for (j=0;j<C;++j) {
            cout<<res[i][j];
        }
        puts("");
    }
    //puts("----------------------------");
}
inline void gen() {
    fo(i,R) {
        fo(j,C) {
            if (flow[i][R+j]==0) {
                flow[i][R+j]+=1;
                flow[R+j][i]-=1;
                res[i][j]=0;
            }
            else {
                res[i][j]=1;

                //lock this path
                flow[j+R][i]+=1;


                //open partial flow
                flow[source][i]-=1;
                flow[i][source]+=1;
                flow[j+R][sink]-=1;
                flow[sink][j+R]+=1;


                //check for new flow
                if (augument(source,sink)) {
                    res[i][j]=0;
                }
                else {
                    flow[source][i]+=1;
                    flow[i][source]-=1;
                    flow[j+R][sink]+=1;
                    flow[sink][j+R]-=1;
                }
            }
            // Print();
            // sleep(1);
        }
    }
}
inline void solve() {
    int i,j;
    SET(res,0);
    for (i=0;i<R;++i) {
        for (j=0;j<C;++j) {
            res[i][j]= flow[i][R+j];
        }
    }
    gen();
    Print();
}
inline void Proc() {
    if (!checkNice()) {
        puts(" impossible");
    }
    else {
        build_flowgraph();
        int ret=maxflow();
        if (ret!=ones) {
            puts(" impossible");
            return ;
        }
        puts("");
        solve();
    }
}
int main() {

    freopen("in.txt","r",stdin);

    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":";
        Proc();
    }

}
// kate: indent-mode cstyle; space-indent on; indent-width 0;
