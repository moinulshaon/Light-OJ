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

#define SIZE 505

vector <int> edge[SIZE], cost[SIZE];

struct node{
    int val,city;
    bool operator < (const node & p)const{return val>p.val;}
};

mint mp;

int dis[20][20];

void dijkstra(int s){

    bool vis[SIZE]={false};

    node place,temp,u;
    place.val=0;
    place.city=s;


    priority_queue<node> q;

    q.push(place);


    while (!q.empty()){

        temp=q.top();q.pop();

        if (vis[temp.city])
            continue;
        vis[temp.city]=true;


        if ( mp.find( temp.city )!= mp.end() ){
            dis[ mp[s] ][ mp[ temp.city ] ] = temp.val;
        }

        for (int i=0;i<edge[temp.city].size();++i){
            u.val=cost[temp.city][i]+temp.val;
            u.city=edge[temp.city][i];

            if ( !vis[ u.city ] )
                q.push(u);
        }
    }
}

int shop;
pint dp[1<<16][16];

#define INF 10000000

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}

int n;

pint func( int state,int now ){

    if ( dp[ state ][now].first != -1 )return dp[ state ][now];

    //printf("%d %d\n",state,now);

    pint ans;

    if(  dis[ now ][ mp[n-1] ] >=INF ){
        ans= make_pair( -INF,0 );
    }else{
        ans= make_pair( 0, dis[ now ][ mp[n-1] ] );
    }

    pint tt;
    for (int i=0;i<shop;++i){
        if ( Check( state,i ) == 0 && dis[ now ][ i ]<INF ){

            //cout<<"going to "<<i<<endl;

            tt=func( Set( state,i ), i );

            tt.first++;
            tt.second += dis[ now ][i];

            if ( tt.first>ans.first ){
                ans=tt;
            }else if ( tt.first == ans.first ){
                ans.second=min( ans.second,tt.second );
            }
        }
    }


    return dp[state][now] = ans;
}

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int ee;
        scanf("%d %d %d",&n,&ee,&shop);

        mp.clear();

        int tmp;
        for (int i=0;i<shop;++i){
            scanf("%d",&tmp);
            mp[tmp] = i;
        }

        if ( mp.find( n-1 ) == mp.end() )
            mp[ n-1 ]= shop;
        if ( mp.find( 0 ) == mp.end() )
            mp[0]= shop+1;


        for (int i=0;i<n;++i){
            edge[i].clear();
            cost[i].clear();
        }

        int u,v,w;
        while ( ee-- ){
            scanf("%d %d %d",&u,&v,&w);

            edge[u].PB( v );
            cost[u].PB( w );
        }

        for (int i=0;i<=shop+1;++i){
            for (int j=0;j<=shop+1;++j){
                dis[i][j] = INF;
            }
        }

        for( mint::iterator it=mp.begin();it !=mp.end() ; ++it ){
            dijkstra ( it->first );
        }

        /*
        for (int i=0;i<=shop+1;++i){
            for (int j=0;j<=shop+1;++j){
                printf("%4d",dis[i][j]);
            }printf("\n");
        }
        */

        NEG(dp);
        pint ans=make_pair( -INF,0 );

        for (int i=0;i<shop;++i){

            if ( dis[ mp[0] ][i]>= INF )continue;

            //cout<<"going to "<<i<<endl;

            pint tt= func( Set(0,i),i );
            tt.second+= dis[ mp[0] ][i];
            tt.first++;
            if ( tt.first>ans.first ){
                ans=tt;
            }else if ( tt.first == ans.first ){
                ans.second=min( ans.second,tt.second );
            }
        }


        printf("Case %d: ",kk);
        if ( ans.first < 0 ){
            printf("Impossible\n");
        }else{
            printf("%d %d\n",ans.first,ans.second);
        }

    }


    return 0;
}
