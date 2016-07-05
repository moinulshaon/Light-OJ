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

#define SIZE 22

int vis[SIZE];
deque<int> dq;
deque<pint> wheel;
int n,m;

bool done(){
    for (int i=0;i<n;++i){
        if ( vis[i] != (1<<m)-1 )return false;
    }
    return true;
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        CLR(vis);
        dq.clear();
        wheel.clear();

        scanf("%d %d",&n,&m);

        for (int i=0;i<n;++i){
            dq.PB( i );
        }
        for (int i=0;i<m;++i){
            wheel.PB( MP(i,-1) );
        }

        int cnt = 0;
        while ( true ){


            pint g=wheel.front();
            bool ok = false;
            for (int i=0;i<dq.size();++i ){
                int p = dq[i];
                if ( ( vis[p] & (1<<g.X) ) == 0 ){
                    wheel[0] = MP( g.X , p );
                    dq.erase( dq.begin()+i );
                    ok= true;
                    break;
                }
            }
            if ( !ok )wheel[0] = MP( g.X , -1 );

            if ( g.Y != -1 ){
                vis[g.Y] |= 1<<g.X;
                dq.PB( g.Y );
            }

            cnt++;
            g = wheel.front();wheel.pop_front();
            wheel.push_back( g );
            if ( done() )break;
        }
        printf("Case %d: %d\n",kk,cnt*5);

    }


    return 0;
}
