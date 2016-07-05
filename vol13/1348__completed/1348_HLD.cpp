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

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 30100
int tree[SIZE];
int MaxVal=SIZE-5;
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
    }
}

int chainNo[SIZE];
int chaincnt;
int chainLdr[SIZE];

int pos[SIZE];
vector<int> out[SIZE];

int level[SIZE];
int childcnt[SIZE];
int parent[SIZE];

void dfs( int x,int p ){
    level[x]= level[p]+1;
    childcnt[x] = 1;
    parent[x] = p;
    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != p ){
            dfs( out[x][i] , x  );
            childcnt[x] += childcnt[ out[x][i] ];
        }
    }
}

int snow;

void HLD( int x,int cnt , bool start ){

    //cout<<x<<" "<<cnt<<" "<<start<<endl;

    if ( start ){
        chainLdr[ cnt ] = x;
    }
    chainNo[ x ] = cnt;
    pos[x] = ++snow;

    int mx = -1;
    for (int i=0;i<out[x].size();++i){
        if ( out[x][i] != parent[x] ){
            if ( mx == -1 )mx = out[x][i];
            else if ( childcnt[ out[x][i] ] > childcnt[ mx ] ){
                mx = out[x][i];
            }
        }
    }

    if ( mx == -1 )return ;
    HLD( mx,cnt,false );
    for (int i=0;i<out[x].size() ;++i){
        if ( out[x][i] != mx && out[x][i] != parent[x]  ){
            HLD( out[x][i],++chaincnt,true );
        }
    }
}

int lca( int x,int y ){

    while ( chainNo[x] != chainNo[y] ){
        if (  level[ chainLdr[ chainNo[x] ] ] >  level[ chainLdr[ chainNo[y] ] ] ){
            x= parent[ chainLdr[ chainNo[x] ] ];
        }else{
            y = parent[ chainLdr[ chainNo[y] ] ];
        }
    }

    if ( level[x] < level[y] ){
        return x;
    }else{
        return y;
    }
}

int query( int x,int u ){

    if ( chainNo[x] !=  chainNo[u]  ){
        return read( pos[x] ) - read(  pos[ chainLdr[ chainNo[x] ] ]-1 )
        + query( parent[ chainLdr[ chainNo[x] ] ] , u );
    }else{
        //cout<<"shaon "<<x<<" "<<u<<" "<<read( pos[x] )<<" "<<read( pos[ parent[ u ] ] )<<endl;
        return read( pos[x] ) - read( pos[ u ] -1 );
    }
}


int save[SIZE];
int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        CLR(tree);

        printf("Case %d:\n",kk);

        int n,q;
        scanf("%d",&n);

        for (int i=1;i<=n;++i){
            scanf("%d",&save[i]);

        }

        for (int i=0;i<=n;++i){
            out[i].clear();
        }

        int u,v;
        for (int i=1;i<n;++i){
            scanf("%d %d",&u,&v);
            v++,u++;
            out[u].PB( v );
            out[v].PB( u );
        }

        dfs( 1,0 );
        snow=0;
        chaincnt = 0;
        HLD(1,++chaincnt,true);

        for (int i=1;i<=n;++i){
            //cout<<pos[i]<<" "<<save[i]<<endl;
            update( pos[i], save[i] );
        }

        scanf("%d",&q);
        int ins ;
        while ( q-- ){
            scanf("%d",&ins);
            if ( ins ){
                scanf("%d %d",&u,&v);
                u++;
                update( pos[u],-save[ u ] );
                save[ u ] = v;
                update( pos[u],v );
            }else{
                scanf("%d %d",&u,&v);
                u++,v++;
                int cca= lca(u,v);
                printf("%d\n",query(u,cca) + query( v,cca ) - save[ cca ] );
            }

        }

    }


    return 0;
}
