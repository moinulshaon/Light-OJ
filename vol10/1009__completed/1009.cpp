#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define SIZE 20100

vector<int> outarrow[SIZE];

char vis[SIZE];

int checkBipartite(int start){

    queue<int> q;

    q.push(start);
    vis[start]=0;
    //bool bipartitePossible=true;
    int cnt[2]={0};

    while (!q.empty() /*&& bipartitePossible*/){
        int tmp=q.front();
        q.pop();
        cnt[ vis[tmp] ]++;

        for (int i=0;i<outarrow[tmp].size();++i){
            if ( vis[ outarrow[tmp][i] ]==-1 ){
                vis[ outarrow[tmp][i] ]=  !vis[tmp];
                q.push( outarrow[tmp][i] );
            }
            /*else if ( vis[ outarrow[tmp][i] ]==  vis[tmp]){
                bipartitePossible=false;
                break;
            }*/
        }
    }
    return max(cnt[0],cnt[1]);
}

int main(){
    int kase,n,a,b;

    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        int mx=0;

        for (int i=0;i<SIZE;++i){
            outarrow[i].clear();
        }
        map<int,int> mp;
        while ( n-- ){
            scanf("%d %d",&a,&b);
            if ( mp.find(a)==mp.end() ){
                mp[a]=++mx;
            }
            if ( mp.find(b)==mp.end() ){
                mp[b]=++mx;
            }

            outarrow[ mp[a] ].push_back(mp[b]);
            outarrow[ mp[b] ].push_back(mp[a]);
        }

        memset(vis,-1,sizeof(vis));

        int sum=0;
        for (int i=1;i<=mx;++i){
            if ( vis[i]== -1 ){
                sum+=checkBipartite(i);
            }
        }
        printf("Case %d: %d\n",kk,sum);

    }
    return 0;
}
