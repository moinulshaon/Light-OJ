#include <cstdio>
#include <cstring>
#include <vector>
#define N 40100
using namespace std;


int NODE(int x){
    return ((20000)+(x));
}

vector <int> outarrow [N + 10];
vector <int> inarrow [N + 10];
bool vis [N + 10];
vector <int> stk;
int component [N + 10];

int result[ N+ 10 ];


void dfs1 (int x)
{
	vis [x] = true;

	for ( int u = 0; u < outarrow [x].size (); u++ )
		if ( !vis [ outarrow [x] [u]] )
            dfs1 (outarrow [x] [u]);

	stk.push_back (x);
}

vector<int> arrayOfComponentNode[N+10];

void dfs2 (int x, int c)
{
	vis [x] = false;
	component [x] = c;
	arrayOfComponentNode[c].push_back( x-20000 );

	for ( int u = 0; u < inarrow [x].size (); u++ )
		if ( vis [inarrow [x] [u]] )
            dfs2 (inarrow [x] [u], c);
}

char check[N+10];


void dfs3( int u ,int ss){


    for (int i=0;i<arrayOfComponentNode[u].size();++i){
        check[ NODE( arrayOfComponentNode[u][i] ) ]=ss;
    }

    for (int i=0;i<arrayOfComponentNode[u].size();++i){
        if ( check[ NODE( -arrayOfComponentNode[u][i] )  ]== -1 )
            dfs3( component[ NODE( -arrayOfComponentNode[u][i] ) ] , !ss );
    }
}

int main ()
{
	int testCase;
	scanf ("%d", &testCase);

	for (int kk=1; testCase-- ;++kk)
	{
		int n, m;
		scanf ("%d %d", &m, &n);

        for ( int i = 0; i <= n ; i++ )
        {
            outarrow [ NODE(i) ].clear ();
            outarrow [ NODE(-i) ].clear ();
            inarrow [NODE(i)].clear ();
            inarrow [NODE(-i)].clear ();


            vis[NODE(i)]=vis[NODE(-i)]=false;

        }

        stk.clear ();

		for ( int i = 0; i < m; i++ )
		{
			int a, b;
			scanf ("%d %d", &a, &b);
			outarrow [NODE(-a)].push_back (NODE(b));
			inarrow [NODE(b)].push_back (NODE(-a));

			outarrow [NODE(-b)].push_back (NODE(a));
			inarrow [NODE(a)].push_back (NODE(-b));
		}

		for ( int i = 1; i <= n; i++ ){
            if ( !vis [NODE(i)] )
                dfs1 (NODE(i));
            if ( !vis [ NODE(-i) ] )
                dfs1 ( NODE(-i) );

		}


		int c = 0;

		for ( int i = stk.size () - 1; i >= 0; i-- ){
            if ( vis [stk [i]] ){
                arrayOfComponentNode[ ++c ].clear();
                dfs2 (stk [i], c);
            }


		}


		printf("Case %d: ",kk);

		bool pos=true;
		for (int i=1;i<=n;++i){
            if ( component[ NODE(i) ]==component[ NODE(-i)  ] ){
                pos=false;
                break;
            }
		}
		if ( !pos ){
            printf("No\n");
		}else{
            printf("Yes\n");

            memset(check,-1,sizeof(check));

            for ( int i = stk.size () - 1; i >= 0; i-- ){

                if ( check[ stk[i] ]== -1 ){
                    dfs3( component[ stk[i] ], 0 );
                    //printf("%d\n",stk[i]);
                }

            }
            int cnt=0;
            for (int i=1;i<=n;++i){
                if ( check[ NODE(i) ] ){
                    result[cnt]=i;
                    cnt++;
                    //printf("%d %d %d\n",i,NODE(i),check[NODE(i)]);
                }
            }
            printf("%d",cnt);
            for (int i=0;i<cnt;++i){
                printf(" %d",result[i]);
            }
            printf("\n");



		}



	}

	return 0;
}
