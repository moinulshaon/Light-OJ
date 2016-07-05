#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
#define SIZE 51000


int parent[SIZE][17],depth[SIZE];
vector<int> out[SIZE],cost[SIZE];

int pcost[SIZE][17];

void dfs(int x,int p,int cc){

    //printf("saon %d %d %d\n",x,p,cc);

    parent[x][0] = p;
    //printf("shaon %d %d %d\n",x,p,parent[x][0]);

    depth[x]=depth[p]+1;
    pcost[x][0]=cc;



    for (int i=1;i<17;++i){
        parent[x][i]=parent[ parent[x][i-1] ][i-1];
        pcost[x][i]=max( pcost[x][i-1], pcost[ parent[x][i-1] ][i-1] );
    }


    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( y!= p ){
            //printf("going %d %d %d\n",x,y,cost[x][i]);
            dfs(y,x,cost[x][i]);
        }
    }
}

int modifiedlca(int x,int y){
    int ans=INT_MIN;
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    for (int i=0;i<17;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            ans=max( ans, pcost[y][i] );
            y=parent[y][i];
        }
    }
    if ( x==y ){
        //printf("shaon %d %d\n",x,ans);
        return ans;
    }
    for(int i=16;i>=0;--i)
        if(parent[x][i]!=parent[y][i] ){
            ans=max( ans, pcost[x][i] );
            ans=max( ans, pcost[y][i] );

            x=parent[x][i];
            y=parent[y][i];

        }

    return max(ans,max( pcost[x][0],pcost[y][0]) );
}


struct lists {
    int start;
    int end;
    int distance;
} a [100000+ 10];

int pp [SIZE];
int component[SIZE];
int vertex;
int edges;

bool cmp (lists p, lists q)
{
    if ( p.distance < q.distance ) return true;
    return false;
}

int parentOf (int n)
{
    if ( n == pp [n] ) return n;
    return pp [n] = parentOf (pp [n]);
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

    int kase;
    kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        printf("Case %d:\n",kk);
        vertex=fastIn<int>();
        edges=fastIn<int>();
        //printf("shaon\n");
        for (int i=0;i<edges;++i){
            a[i].start=fastIn<int>();
            a[i].end=fastIn<int>();
            a[i].distance=fastIn<int>();
            //printf("shaon2\n");
        }
        //printf("end\n");
        sort (a, a + edges , cmp);


        for (int i=0;i<=vertex;++i){
            out[i].clear();
            cost[i].clear();
        }

        for (int i=0;i<=vertex; ++i ){
            pp [i] = i;
            component[i]=1;
        }


        int selectedEdges = vertex - 1;
        for ( int i = 0; i < edges && selectedEdges; i++ ) {
            int p = parentOf (a [i].start);
            int q = parentOf (a [i].end);

            if ( p != q ) {
                if (component[p]>component[q])swap(p,q);

                component[q]+=component[p];
                pp [p] = q;
                selectedEdges--;

                out[ a [i].start ].push_back(  a [i].end );
                cost[ a[i].start ].push_back( a[i].distance );

                out[ a [i].end ].push_back(  a [i].start );
                cost[ a[i].end ].push_back( a[i].distance );
                //printf("edge %d %d\n",a [i].start,a [i].end);

            }
        }

        dfs(1,0,0);
        //printf("cost %d %d\n",parent[4][16],pcost[4][16]);
        int qq,u,v;
        qq=fastIn<int>();
        while(qq--){
            u=fastIn<int>();
            v=fastIn<int>();
            printf("%d\n",modifiedlca(u,v) );
        }

    }
    return 0;

}
