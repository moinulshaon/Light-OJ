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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 100100

int parent [SIZE];
int sz[SIZE];

int parentOf (int n){
    if ( n == parent [n] ) return n;
    return parent [n] = parentOf (parent [n]);
}
void makeUnion(int x,int y){
    int p = parentOf ( x );
    int q = parentOf ( y );

    if ( p != q ) {
        if (sz[p]>sz[q])swap(p,q);
        sz[q]+=sz[p];
        parent [p] = q;
    }
}


vector<int> out[SIZE];

pint dfs1( int x,int p ){

    pint tt,tmp=make_pair( 0,x );
    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != p ){
            tt=dfs1( out[x][i] , x);
            tt.first++;

            if ( tt.first >tmp.first ){
                tmp=tt;
            }
        }
    }
    return tmp;
}

int dfs2( int x,int p ){


    int tt,tmp=0 ;
    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != p ){
            tt=dfs2( out[x][i] , x)+1;

            if ( tt>tmp ){
                tmp=tt;
            }
        }
    }
    return tmp;
}

int diameter(int x){

    pint tmp=dfs1(x,0);
    return dfs2( tmp.second,0 );
}

int ans[SIZE];
void calc(int x){

    int d=diameter(x);
    int ss= sz[x];

    for (int i=1;i<=ss;++i){
        if ( i<= d+1 ){
            ans[i]=min(ans[i],i-1);
        }else{
            ans[i]=min(ans[i],2*(i-1)-d);
        }
    }

}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int v,e;
        scanf("%d %d",&v,&e);

        for (int i=1;i<=v;++i){
            parent [i] = i;
            sz[i]=1;
            out[i].clear();
        }

        int x,y;
        for (int i=0;i<e;++i){
            scanf("%d %d",&x,&y);
            makeUnion(x,y);

            out[x].PB(y);
            out[y].PB(x);
        }

        memset(ans,63,sizeof(ans));

        for (int i=1;i<=v;++i){
            if ( parentOf(i) == i ){
                calc(i);
            }
        }

        printf("Case %d:\n",kk);

        int qq;
        scanf("%d",&qq);

        while( qq-- ){
            scanf("%d",&x);
            if ( ans[x] <100000000 ){
                printf("%d\n",ans[x]);
            }else{
                printf("impossible\n");
            }
        }
    }


    return 0;
}
