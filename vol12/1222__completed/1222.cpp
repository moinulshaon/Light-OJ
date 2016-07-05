#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;


int totalnode;
int adj[110][110];
int d[110];
int prv[110];

const int INF=(1<<28);


struct node{
    int val,city,prv;
    bool operator < (const node & p)const{return val>p.val;}
};

int dijkstra(int s,int f){

    bool vis[110]={false};
    memset(prv,-1,sizeof(prv));

    node place,temp,u;
    place.val=0;
    place.city=s;
    place.prv= -1;

    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();
        if (temp.city==f)break;

        if (vis[temp.city])
            continue;
        prv[temp.city]=temp.prv;
        vis[temp.city]=true;


        for (int i=0;i<=totalnode;++i){
            if ( vis[i] )continue;
            u.val=adj[temp.city][i]+temp.val;
            u.city=i;
            u.prv=temp.city;
            q.push(u);
        }
    }
    printf("%d\n",temp.val);
    //getchar();
    if ( temp.city==f ){
        return temp.val;
    }
    else return INF;
}


int minCostFlow(int s,int e){

    int perpath,path=0;

    while ( ( perpath=dijkstra(s,e) )!=INF ){
        path+=perpath;
        printf("%d\n",perpath);
    }
    return path;
}

int main(){
    int tmp,kase,left;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&left);
        for (int i=0;i<110;++i){
            for (int j=0;j<110;++j){
                adj[i][j]=INF;
            }
        }
        totalnode=2*left;
        for (int i=0;i<left;++i){
            for (int j=0;j<left;++j){
                scanf("%d",&adj[i+1][left+j+1]);
                adj[i+1][left+j+1]=1000-adj[i+1][left+j+1];
            }
        }

        int source=0,end=totalnode+1;

        for (int i=1;i<=left;++i){
            adj[source][i]=0;
        }
        for (int j=1;j<=left;++j){
            adj[left+j][end]=0;
        }

        ++totalnode;
        printf("Case %d: %d\n",kk,minCostFlow(source,end));
    }
}
