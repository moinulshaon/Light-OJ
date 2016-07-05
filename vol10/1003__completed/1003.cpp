#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define N 10005
using namespace std;

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
vector <int> stk;
int component [N + 10];
bool in [N + 10];



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


int main(){
    freopen("in.txt","r",stdin);

    int prv=0;
    int kase,total;
    string s1,s2;

    cin>>kase;

    for (int kk=1;kase--;++kk){
        int line;
        cin>>line;

        for (int i=0;i<prv;++i){
            outarrow [i].clear ();
            inarrow [i].clear ();
            vis[i]=false;
            in[i]=false;
        }
        stk.clear ();

        map<string,int> myp;
        total=0;

        while (line--){

            cin>>s1>>s2;

            if ( myp.find(s1)==myp.end() )
                myp[s1]=total++;

            if ( myp.find(s2)==myp.end() )
                myp[s2]=total++;

            outarrow[myp[s1] ].push_back( myp[s2] );
            inarrow[myp[s2] ].push_back( myp[s1] );
        }

        for ( int i = 0; i < total; i++ )
			if ( !vis [i] )
                dfs1 (i);

		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [stk [i]] )
                dfs2 (stk [i], ++c);

        printf("Case %d: ",kk);
        if (c==total)
            printf("Yes\n");
        else
            printf("No\n");


        prv=total;
    }
    return 0;



}
