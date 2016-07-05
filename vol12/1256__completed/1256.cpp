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

#define SIZE 26

int adj[SIZE][SIZE];
int indeg[SIZE];
int outdeg[SIZE];
vector<string> save[SIZE][SIZE];

void pre(){
    CLR(adj);
    CLR(indeg);
    CLR(outdeg);

    for (int i=0;i<SIZE;++i){
        for (int j=0;j<SIZE;++j){
            save[i][j] .clear();
        }
    }
}

int getout(){
    for (int i=0;i<26;++i){
        if ( outdeg[i] == indeg[i]+1 ){
            return i;
        }
    }
    return -1;
}

int getin(){
    for (int i=0;i<26;++i){
        if ( indeg[i] == outdeg[i]+1 ){
            return i;
        }
    }
    return -1;
}

pint pos(){

    int x = getout();
    int y = getin();

    if ( (x== -1 && y != -1) || (x!= -1 && y == -1)){
        return MP(-1,-1);
    }

    for (int i=0;i<26;++i){
        if ( i == x || i == y )continue;
        if ( indeg[i] != outdeg[i] ){
            return MP(-1,-1);
        }
    }

    if ( x == -1 && y == -1 ){
        for (int i=0;i<26;++i){
            if ( outdeg[i] > 0 ){
                x = y = i;
                break;
            }
        }
    }

    return MP(x,y);
}

vector<int> path;
void dfs(int x){

    for (int i=0;i<26;++i){
        if ( adj[x][i] >0 ){
            adj[x][i]--;
            dfs(i);
        }
    }
    path.PB( x );
}

int main(){

    FRO

    int kase;
    cin>>kase;

    for (int kk=1;kase--;++kk){

        pre();

        int n;
        cin>>n;

        string str;

        for (int i=0;i<n;++i){
            cin>>str;
            char tmp = str[ str.size()-1 ];
            save[ str[0]-'a' ][ tmp-'a' ].PB( str );
            outdeg[ str[0]-'a' ]++;
            indeg[ tmp-'a' ]++;
            adj[ str[0]-'a' ][ tmp-'a' ]++;
        }

        cout<<"Case "<<kk<<": ";


        pint base=pos();

        if ( base.X == -1 ){
            cout<<"No\n";
            continue;
        }

        path.clear();
        dfs(base.X);

        if ( path.size()-1 != n ){
            cout<<"No\n";
            continue;
        }

        reverse( ALL(path) );

        cout<<"Yes\n";
        for (int i=1;i<path.size();++i){
            if ( i!= 1 )cout<<" ";
            if ( save[ path[i-1] ][ path[i] ].empty() )return 0;

            cout<<save[ path[i-1] ][ path[i] ].back();
            save[ path[i-1] ][ path[i] ].pop_back();
        }cout<<"\n";
    }



    return 0;
}
