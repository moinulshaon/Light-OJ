#include<cstdio>
#include<algorithm>
#include<vector>
#include <cstring>

using namespace std;
vector<int> out[30010];
int n,w[30010];
int depth[30010],parent[30010][17],innow[30010],outnow[30010],now;
bool vis[30010];

void dfs(int x,int p){
    vis[x]=true;

    parent[x][0]=p;
    depth[x]=depth[p]+1;

    innow[x]=++now;
    for (int i=1;i<17;++i)
        parent[x][i]=parent[ parent[x][i-1] ][i-1];

    for (int i=0;i<out[x].size();++i){
        int y=out[x][i];
        if ( !vis[y] ){
            dfs(y,x);
        }
    }

    outnow[x]=now;
}

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

const int MaxVal=30100;
int tree[31000];

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
    int T;
    T=fastIn<int>();
    for (int kk=1;T--;++kk){
        n=fastIn<int>();
        for (int i=1;i<=n;++i)
            w[i]=fastIn<int>();
        for (int i=1;i<=n;++i)
            out[i].clear();
        for (int i=1;i<n;++i){
            int u,v;
            u=fastIn<int>();
            v=fastIn<int>();
            ++u,++v;
            out[u].push_back(v);out[v].push_back(u);
        }
        now=0;
        memset(vis,false,sizeof(vis));
        dfs(1,0);
        memset(tree,0,sizeof(tree));
        for (int i=1;i<=n;++i){
            update(innow[i],w[i]);
            update(outnow[i]+1,-w[i]);
        }

        int q;
        q=fastIn<int>();
        printf("Case %d:\n",kk);
        while(q--){
            int a,b,c;
            a=fastIn<int>();
            b=fastIn<int>();
            c=fastIn<int>();
            if(a==0){
                ++b,++c;
                int t=lca(b,c);
                printf("%d\n",read(innow[b])+read(innow[c])-read(innow[t])-read(innow[parent[t][0]]));
            }else{
                ++b;
                update(innow[b],c-w[b]),update(outnow[b]+1,-c+w[b]);
                w[b]=c;
            }
        }
    }
    return 0;
}
