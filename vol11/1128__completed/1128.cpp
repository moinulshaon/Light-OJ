#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define SIZE 101000


bool vis[SIZE];
int parent[SIZE][18];
int depth[SIZE];
int vertex;
vector<int> out[SIZE];
int val[SIZE];

void dfs(int x,int p){
    vis[x]=true;

    parent[x][0]=p;
    depth[x]=depth[p]+1;


    for (int i=1;i<18;++i)
        parent[x][i]=parent[ parent[x][i-1] ][i-1];

    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( !vis[y] ){
            dfs(y,x);
        }
    }

}
/*
int lca(int x,int y){
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    for (int i=0;i<17;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            y=parent[y][i];
        }
    }
    if ( x==y ){
        return x;
    }
    for(int i=16;i>=0;--i)
        if(parent[x][i]!=parent[y][i] )
            x=parent[x][i],y=parent[y][i];
    return parent[x][0];
}
*/

int func(int x,int lim){

    for ( int i=17;i>=0;--i ){
        if ( parent[x][i]!= 0 && val[ parent[x][i] ]>=lim ){
            //printf("%d %d %d\n",x,lim,i);
            return func( parent[x][i],lim );
        }
    }
    return x;
}

template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}


int main(){
    freopen("in.txt","r",stdin);
    int a,b,q,kase;
    kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        vertex=fastIn<int>();
        q=fastIn<int>();

        for (int i=1;i<=vertex;++i){
            out[i].clear();
        }

        memset(val,-1,sizeof(-1));
        for (int i=1;i<vertex;++i){
            a=fastIn<int>();
            b=fastIn<int>();
            out[a+1].push_back(i+1);
            val[i+1]=b;
        }
        memset(vis,false,sizeof(vis));
        val[1]=1;
        dfs(1,0);
        printf("Case %d:\n",kk);
        while(q--){
            a=fastIn<int>();
            b=fastIn<int>();
            printf("%d\n",func(a+1,b)-1);
        }
    }
    return 0;
}
