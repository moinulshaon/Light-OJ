#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define N 1005
using namespace std;

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
int in[N+10];
int out[N+10];
vector <int> stk;
int component [N + 10];
vector<int> super[N];



void dfs1 (int x)
{
	vis [x] = true;

	for ( int u = 0; u < outarrow [x].size (); u++ )
		if ( !vis [ outarrow [x] [u]] )
            dfs1 (outarrow [x] [u]);

	stk.push_back (x);
}

void dfs2 (int x, int c)
{
	vis [x] = false;
	component [x] = c;

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

bool pos;


int main ()
{
    freopen("in.txt","r",stdin);
	int testCase;
	scanf ("%d", &testCase);

	for (int kk=1; testCase-- ;++kk){
		int  person,m;
		scanf ("%d",  &person);

        for ( int i = 0; i < N ; i++ ){
            outarrow [i].clear ();
            inarrow [i].clear ();
            super[i].clear();
            vis[i]=false;
            in[i]=0;
            out[i]=0;
        }

        int a, b;
        map<int,int> mp;
        int vertex=1;
        pos=false;
        while(person--){
            scanf("%d",&m);
            while(m--){
                scanf ("%d %d", &a, &b);
                if ( a==0 )pos=true;
                if ( mp.find(a)==mp.end() ){
                    mp[a]=vertex++;
                }
                if ( mp.find(b)==mp.end() ){
                    mp[b]=vertex++;
                }
                outarrow [ mp[a] ].push_back (mp[b]);
                inarrow [ mp[b] ].push_back (mp[a]);
                //printf("edge %d %d\n",mp[a],mp[b]);
            }
        }

        stk.clear ();


		for ( int i = 1; i < vertex; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] ){
                dfs2 (stk [i], ++c);
                //printf("stk %d\n",stk[i]);
			}

        //printf("%d\n",c);

        for (int i=1;i<=vertex;++i){
            for (int j=0;j<outarrow[i].size();++j){
                if ( component[i] !=component[ outarrow[i][j] ] ){
                    out[ component[i] ]++;
                    in[ component[ outarrow[i][j] ] ]++;
                }
            }
        }


        int cnt=0;
        for (int i=1;i<=c && pos;++i){
            //printf("%d\n",component[mp[0]]);
            if ( i==component[mp[0]] )continue;
            else if ( in[i] == 1 && out[i]==0 ){
                cnt++;
                if ( cnt>1 )pos=false;
            }else if ( out[i]!=1 || in[i]!=1  ){
                pos=false;
                //printf("%d %d\n",in[i],out[i]);
            }
        }

        if (  pos )
            printf("Case %d: YES\n",kk);
        else{
            printf("Case %d: NO\n",kk);
        }
	}

	return 0;
}
