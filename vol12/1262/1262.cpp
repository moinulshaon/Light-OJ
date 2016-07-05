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


#define INF (1<<28)
#define SIZE 2800

int source,sink,par[SIZE],flow,cnt;
vector<int>adj[SIZE];

struct edges
{
    int u,v,cap,rev_ind;

    edges(int _u=0,int _v=0,int _cap=0,int _rev_ind=0)
    {
        u=_u;v=_v;cap=_cap;rev_ind=_rev_ind;
    }
};

edges E[210000];

void add_edge(int u,int v,int cap)
{
    //cout<<u<<" "<<v<<" "<<cap<<endl;
    E[cnt]=edges(u,v,cap,cnt+1);
    E[cnt+1]=edges(v,u,0,cnt);
    adj[u].PB(cnt);
    adj[v].PB(cnt+1);
    cnt+=2;
}

bool AugmentPath()
{
    int i,u,ind,v,cap;
    queue<int>Q;

    NEG(par);
    Q.push(source);
    par[source]=-2;

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();

        for(i=0;i<adj[u].size();++i)
        {
            ind=adj[u][i];
            v=E[ind].v;
            cap=E[ind].cap;
            if(par[v]==-1 && cap>0)
            {
                par[v]=ind;
                if(v!=sink)
                    Q.push(v);
            }
        }
    }
    return par[sink]!=-1;

}

void Update_Graph(int v)
{
    int ind=par[v];

    if(ind>=0)
    {
        flow=min(flow,E[ind].cap);
        Update_Graph(E[ind].u);
        E[ind].cap-=flow;
        ind=E[ind].rev_ind;
        E[ind].cap+=flow;
    }
}

int MaxFlow()
{
    int ans=0,i,u,ind;

    while(AugmentPath())
    {
        for(i=0;i<adj[sink].size();++i)
        {
            ind=E[adj[sink][i]].rev_ind;
            u=E[ind].u;
            if(par[u]>=0)
            {
                par[sink]=ind;
                flow=INF;
                Update_Graph(sink);
                ans+=flow;
            }
        }
    }
    return ans;
}


void clear(){

    for (int i=0;i<SIZE;++i){
        adj[i].clear();
    }
    cnt = 0;
}

int num[100][100];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        clear();

        int n,m;
        scanf("%d %d",&n,&m);

        source = 0;
        sink = n*m + 2*( n+m-1 )+1;


        int cntl[110]={0};
        int cntr[110]={0};

        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                int ldiag = (i-1) + (j-1) +1  ;
                add_edge( n*m+ldiag, (i-1)*m + j , 99 );

                num[i][j] = cnt-1;

                int rdiag = (i-1) - (j-1) +m  ;
                add_edge( (i-1)*m + j , n*m+ n+m-1 +rdiag , 99 );

                cntl[ldiag]++;
                cntr[rdiag]++;
            }
        }

        int tmp;
        for (int i=1;i<=n+m-1;++i){
            scanf("%d",&tmp);
            add_edge(source , n*m + i,tmp - cntl[i] );
        }
        for (int i=1;i<=n+m-1;++i){
            scanf("%d",&tmp);
            add_edge( n*m + n+m-1 + i,sink,tmp- cntr[i] );
        }

        MaxFlow();
        printf("Case %d:\n",kk);

        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if ( j != 1 )printf(" ");
                printf("%d",E[ num[i][j] ].cap+1);
            }
            printf("\n");
        }


    }


    return 0;
}

