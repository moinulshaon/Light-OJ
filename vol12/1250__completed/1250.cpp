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

#define SIZE 205

multiset<int> out[SIZE];

void add_edge(int x,int y){
    out[x].insert( y );
    out[y].insert( x );
}

void remove_edge(int x,int y){
    out[x].erase( out[x].find(y) );
    out[y].erase( out[y].find(x) );
}

vector<int> path;

void dfs(int x){

    while ( out[x].size() > 0 ){
        int y = *out[x].begin();
        remove_edge( x,y );
        dfs( y );
    }

    path.PB( x );
}

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m;
        scanf("%d %d",&n,&m);

        int tmp,sum = 0;
        for (int i=0;i<n;++i){
            scanf("%d",&tmp);
            sum += tmp;
        }
        sum -= n*(n+1)/2;
        sum -= m;

        for (int i=0;i<SIZE;++i){
            out[i].clear();
        }

        int x,y;
        while ( m-- ){
            scanf("%d %d",&x,&y);
            add_edge(x,y);
        }

        path.clear();
        dfs(1);


        printf("Case %d: %d\n",kk,sum);
        for (int i=0;i<path.size();++i){
            if ( i )printf(" ");
            printf("%d",path[i]);
        }
        printf("\n");
    }


    return 0;
}
