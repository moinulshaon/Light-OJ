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

int n,m,k;

int color[10][10];

int ans[2][52];

int func( int x, int y ){
    if ( y == m )return func( x+1,0 );
    if ( x == n ){/*
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                printf("%3d",color[i][j]);
            }printf("\n");
        }printf("\n");*/
/*
        CLR(ans);
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                ans[(i+j)%2][ color[i][j] ]++;
            }
        }
*/
/*
        for (int i=0;i<k;++i){
            cout<<ans[0][i]<<" "<<ans[1][i]<<endl;;
        }cout<<endl;
*/
        return 1;
    }

    set<int> vis;
    for (int i=0;i<x;++i){
        for (int j=0;j<m;++j){
            if ( ( abs(x-i)+abs(y-j) ) %2 == 1 ){
                vis.insert( color[i][j] );
            }
        }
    }

    for (int j=0;j<y;++j){
        if ( ( abs(x-x)+abs(y-j) ) %2 == 1 ){
            vis.insert( color[x][j] );
        }
    }

    int sum = 0;
    for (int i=0;i<k;++i){
        if ( vis.find(i) == vis.end() ){
            color[x][y] = i;
            sum += func( x,y+1 );
        }
    }
    return sum;
}


int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d %d",&n,&m,&k);

        n++,m++;

        cout<<func(0,0)<<endl;



    }

    return 0;
}
