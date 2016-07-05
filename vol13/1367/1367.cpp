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

#define INF (1<<28)
#define SIZE 210

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

edges E[SIZE*SIZE*2];

void addedge(int u,int v,int cap)
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

        for(int i=0;i<adj[u].size();++i)
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
        for(int i=0;i<adj[sink].size();++i)
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

int save[SIZE*SIZE];
int out[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        cnt = 0;

        int n,m;
        scanf("%d %d",&n,&m);

        source= 0 , sink = n+1;
        for (int i=0;i<=sink;++i){
            out[i] = 0;
            adj[i].clear();
        }

        int u,v,low,high;
        for (int i=0;i<m;++i){
            scanf("%d %d %d %d",&u,&v,&low,&high);
            save[i] = low;
            addedge(u,v,high-low);
            out[u] -= low;
            out[v] += low;
        }




        int shaon=cnt;
        for (int i=2;i<n;++i){
            if ( out[i]<0 ){
                addedge( i , sink , -out[i] );
            }else if(out[i]>0){
                addedge( source , i , out[i] );
            }
        }

        addedge(source,1,INF);
        addedge(n,sink,INF);

        printf("Case %d: ",kk);

        MaxFlow();

        bool pos=true;
        for (int i=2;i<n && pos ;++i){
            if ( out[i]<0 ){
                if ( E[shaon].cap != -out[i] ) pos=false;
                shaon+=2;
            }else if(out[i]>0){
                if ( E[shaon].cap != out[i] ) pos=false;
                shaon+=2;
            }
        }
        if ( pos ){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }


    return 0;
}
