#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;


#define SIZE 2050

struct two_sat{

    vector <int> out[SIZE];
    vector <int> in[SIZE];
    bool vis [SIZE];
    vector <int> stk;
    int component[SIZE];
    vector<int> n_com[SIZE];

    int n;

    void ini(int n){
        this->n= n;
        n<<=1;

        for (int i=0;i<n;++i){
            out[i].clear();
            in[i].clear();
            n_com[i].clear();
            vis[i]=false;
        }
        stk.clear();
    }

    void add_edge(int x,int y){
        out[x].PB( y );
        in[y].PB( x );
    }

    void add_or(int x,int basex,int y,int basey){

        x= x*2+basex;
        y= y*2+basey;

        add_edge( x^1,y );
        add_edge( y^1,x );
    }
    void remove_edge(int x,int y){
        out[x].pop_back();
        in[y].pop_back();
    }
    void remove_or(int x,int basex,int y,int basey){

        x= x*2+basex;
        y= y*2+basey;

        remove_edge( x^1,y );
        remove_edge( y^1,x );
    }


    void dfs1 (int x){
        vis [x] = true;
        for ( int i=0;i<out[x].size();++i ){
            int &y=out[x][i];
            if ( !vis [ y ] )
                dfs1(y);
        }

        stk.push_back (x);
    }
    void dfs2 (int x, int c){
        vis [x] = false;
        component [x] = c;
        n_com[c].PB( x );

        for (int i=0; i<in[x].size();++i ){
            int &y = in[x][i];
            if ( vis [y] )
                dfs2 ( y, c);
        }
    }




    bool solve(){
        int n=this->n*2;

        for ( int i = 0; i < n; i++ )
            n_com[i].clear();
        stk.clear();

        for ( int i = 0; i < n; i++ )
			if ( !vis [i] )
                dfs1 (i);

        int c= 0;
        for ( int i = stk.size () - 1; i >= 0; i-- )
			if ( vis [ stk [i] ] )
                dfs2 (stk [i], c++ );

        for (int i=0;i<n;++i){
            if ( component[i] == component[i^1] ){
                return false;
            }
        }
        return true;
    }

    int check[SIZE];

    void dfs3( int u ,int ss ){
        for (int i=0;i<n_com[u].size();++i){
            check[ n_com[u][i] ]=ss;
        }
        for (int i=0;i<n_com[u].size();++i){
            if ( check[ n_com[u][i] ^1 ]== -1 )
                dfs3( component[ n_com[u][i] ^1 ] , !ss );
        }
    }


    vector<int> solution(){
        for (int i=0;i<2*n;++i){
            check[i] = -1;
        }
        for ( int i = stk.size () - 1; i >= 0; i-- ){
            if ( check[ stk[i] ] == -1 ){
                dfs3( component[ stk[i] ], 0 );
            }
        }
        vector<int> ret;
        for (int i=0;i<2*n;i+=2){
            if ( check[ i ] == 1 ){
                ret.PB(i/2);
            }
        }
        return ret;
    }

}solver;



struct opp{
    int type,x[3];
}council[10];

bool backtrack(two_sat &sol,int k){
    if ( !solver.solve() )return false;

    if ( k<0 )return true;

    if ( council[k].type == 1 ){
        for (int state=1;state<(1<<3);++state){
            for (int i=0;i<3;++i){
                if ( state & (1<<i) ){
                    sol.add_or( council[k].x[i] , 0,council[k].x[i] , 0  );
                }else{
                    sol.add_or( council[k].x[i] , 1,council[k].x[i] , 1  );
                }
            }

            if ( backtrack( sol,k-1 ) )return true;

            for (int i=0;i<3;++i){
                if ( state & (1<<i) ){
                    sol.remove_or( council[k].x[i] , 0,council[k].x[i] , 0  );
                }else{
                    sol.remove_or( council[k].x[i] , 1,council[k].x[i] , 1  );
                }
            }
        }

    }else{
        for (int state=0;state<(1<<3)-1;++state){
            for (int i=0;i<3;++i){
                if ( state & (1<<i) ){
                    sol.add_or( council[k].x[i] , 0,council[k].x[i] , 0  );
                }else{
                    sol.add_or( council[k].x[i] , 1,council[k].x[i] , 1  );
                }
            }

            if ( backtrack( sol,k-1 ) )return true;

            for (int i=0;i<3;++i){
                if ( state & (1<<i) ){
                    sol.remove_or( council[k].x[i] , 0,council[k].x[i] , 0  );
                }else{
                    sol.remove_or( council[k].x[i] , 1,council[k].x[i] , 1  );
                }
            }
        }
    }

    return false;
}


int main(){



    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);

        solver.ini(n);

        int t,x,y;
        while ( m-- ){
            scanf("%d %d %d",&t,&x,&y);
            x--,y--;
            if ( t == 1 ){
                solver.add_or(x,0,y,0);
            }else if ( t==2 ){
                x *=2;
                y *=2;
                //cout<<(x^1)<<" "<<(y^1)<<endl;
                solver.add_edge(x^1,y^1);
                solver.add_edge(y,x);
            }else if ( t==3 ){
                solver.add_or(x,1,y,1);
            }else {
                solver.add_or(x,0,y,0);
                solver.add_or(x,1,y,1);
            }
        }

        set<int> req;
        for (int i=0;i<k;++i){
            scanf("%d %d %d %d",&council[i].type,&council[i].x[0],&council[i].x[1],&council[i].x[2]);
            council[i].x[0]--;
            council[i].x[1]--;
            council[i].x[2]--;
        }



        printf("Case %d: ",kk);

        if ( !solver.solve() ){
            printf("Impossible.\n");
            continue;
        }

        bool solved = backtrack( solver ,k-1 );


        if ( !solved ){
            printf("Impossible.\n");
        }else{
            printf("Possible");

            vector<int> ans = solver.solution();

            printf(" %d",ans.size());
            for (int i=0;i<ans.size();++i){
                printf(" %d",ans[i]+1);
            }

            printf(".\n");
        }

    }

    return 0;
}
