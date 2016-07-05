
#include<cstdio>
#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define sf scanf
#define pf printf
#define ps for(;;)
#define fr freopen
#define lp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
vector<int>to[100010],we[100010];
int n,m,q;
struct node
{
    node(int a,int b):x(a),d(b) {} int x,d;
};
int dis[100010];
bool operator<(const node&a,const node&b)
{
    return a.d>b.d;
}
void dijkstra()
{
    lp(i,1,n)dis[i]=~0u>>1;
    dis[1]=0;
    priority_queue<node>qu;
    qu.push(node(1,0));
    while(!qu.empty())
    {
        node t=qu.top();
        qu.pop();
        if(t.d!=dis[t.x])continue;
        int u=t.x;
        lp(i,0,int(to[u].size()-1))
        {
            int v=to[u][i],w=we[u][i];
            if(dis[u]+w<dis[v])qu.push(node(v,dis[v]=dis[u]+w));
        }
    }
//lp(i,1,n)pf("[%d]",dis[i]);
}
vector<int>xto[100010];
int up[100010][18],dep[100010],siz[100010];
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    lp(i,0,17)if(((dep[x]-dep[y])>>i)&1)x=up[x][i];
    if(x==y)return x;
    for(int i=17; i>=0; --i)
        if(up[x][i]!=up[y][i])
            x=up[x][i],y=up[y][i];
    return up[x][0];
}
void build()
{
    lp(i,1,n)xto[i].clear();
    lp(u,1,n)
    {
        if(dis[u]==~0u>>1)continue;
        lp(i,0,int(to[u].size()-1))
        {
            int v=to[u][i],w=we[u][i];
            if(dis[u]+w==dis[v])xto[v].push_back(u);
        }
    }
    xto[1].push_back(0);
    /*lp(i,1,n){
    pf("[");lp(j,0,int(xto[i].size()-1))
    pf("%d",xto[i][j]);pf("]\n");
    }*/
    vector<node>tmp;
    lp(i,1,n)if(dis[i]!=~0u>>1)tmp.push_back(node(i,dis[i]));
    sort(tmp.begin(),tmp.end());
    for(int i=int(tmp.size()-1); i>=0; --i)
    {
        int u=tmp[i].x;
        int t=xto[u][0];
        for(int j=1; j<xto[u].size(); ++j)
            t=lca(t,xto[u][j]);
        up[u][0]=t;
        dep[u]=dep[t]+1;
        lp(j,1,17)up[u][j]=up[up[u][j-1]][j-1];
    }
    lp(i,1,n)siz[i]=1;
    lp(i,0,int(tmp.size()-1))
    {
        int u=tmp[i].x;
        siz[up[u][0]]+=siz[u];
    }
//lp(i,1,n)pf("[%d]",up[i][0]);
}
int main()
{
    fr("in.txt","r",stdin);
//fr("test.out","w",stdout);
    int test;
    sf("%d",&test);
    lp(kase,1,test)
    {
        sf("%d%d",&n,&m);
        lp(i,1,n)to[i].clear(),we[i].clear();
        lp(i,1,m)
        {
            int u,v,w;
            sf("%d%d%d",&u,&v,&w);
            ++u,++v;
            to[u].push_back(v);
            we[u].push_back(w);
            to[v].push_back(u);
            we[v].push_back(w);
        }
        dijkstra();
        build();
        sf("%d",&q);
        pf("Case %d:\n",kase);
        lp(i,1,q)
        {
            vector<int>tmp;
            int k;
            sf("%d",&k);
            lp(j,1,k)
            {
                int t;
                sf("%d",&t);
                ++t;
                if(dis[t]!=~0u>>1)tmp.push_back(t);
            }
            if(tmp.size()==0)pf("0\n");
            else
            {
                int t=tmp[0];
                for(int j=1; j<tmp.size(); ++j)
                    t=lca(t,tmp[j]);
                //cout<<t<<endl;
                pf("%d %d\n",dep[t],siz[t]);
            }
        }
    }//ps;
    return 0;
}
