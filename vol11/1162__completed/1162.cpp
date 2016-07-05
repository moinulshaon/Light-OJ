#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
#define SIZE 101000


int parent[SIZE][18],depth[SIZE];
vector<int> out[SIZE],cost[SIZE];

int pcostmin[SIZE][18],pcostmax[SIZE][18];

void dfs(int x,int p,int cc){

    //printf("saon %d %d %d\n",x,p,cc);

    parent[x][0] = p;
    //printf("shaon %d %d %d\n",x,p,parent[x][0]);

    depth[x]=depth[p]+1;
    pcostmin[x][0]=cc;
    pcostmax[x][0]=cc;



    for (int i=1;i<18;++i){
        parent[x][i]=parent[ parent[x][i-1] ][i-1];
        pcostmax[x][i]=max( pcostmax[x][i-1], pcostmax[ parent[x][i-1] ][i-1] );
        pcostmin[x][i]=min( pcostmin[x][i-1], pcostmin[ parent[x][i-1] ][i-1] );
    }


    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( y!= p ){
            //printf("going %d %d %d\n",x,y,cost[x][i]);
            dfs(y,x,cost[x][i]);
        }
    }
}

pair<int ,int > modifiedlca(int x,int y){
    int aa=INT_MIN,bb=INT_MAX;
    if ( depth[x]>depth[y] ){
        swap(x,y);
    }
    for (int i=0;i<17;++i){
        if( ( ( depth[y]-depth[x] )>>i )&1){
            aa=max( aa, pcostmax[y][i] );
            bb=min( bb, pcostmin[y][i] );
            y=parent[y][i];
        }
    }
    if ( x==y ){

        return make_pair(aa,bb);
    }
    for(int i=16;i>=0;--i)
        if(parent[x][i]!=parent[y][i] ){
            aa=max( aa, pcostmax[x][i] );
            aa=max( aa, pcostmax[y][i] );

            bb=min( bb, pcostmin[x][i] );
            bb=min( bb, pcostmin[y][i] );


            x=parent[x][i];
            y=parent[y][i];

        }

    return make_pair( max(aa,max( pcostmax[x][0],pcostmax[y][0]) ) , min(bb,min( pcostmin[x][0],pcostmin[y][0]) )  )  ;
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

    int kase,a,b,w,vertex;
    kase=fastIn<int>();

    for (int kk=1;kase--;++kk){
        printf("Case %d:\n",kk);
        vertex=fastIn<int>();

        for (int i=0;i<=vertex;++i){
            out[i].clear();
            cost[i].clear();
        }

        for (int i=1;i<vertex;++i){
            a=fastIn<int>();
            b=fastIn<int>();
            w=fastIn<int>();

            out[ a ].push_back( b );
            cost[ a ].push_back( w );

            out[ b ].push_back(  a );
            cost[ b ].push_back( w );
        }






        dfs(1,0,0);
        //printf("cost %d %d\n",parent[4][16],pcostmin[4][16]);
        int qq,u,v;
        qq=fastIn<int>();
        while(qq--){
            u=fastIn<int>();
            v=fastIn<int>();
            pair<int,int> rr=modifiedlca(u,v);
            printf("%d %d\n",rr.second,rr.first );
        }

    }
    return 0;

}
