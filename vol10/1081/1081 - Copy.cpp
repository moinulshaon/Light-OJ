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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 505
#define X first
#define Y second
#define MP make_pair

int grid[SIZE][SIZE];

int tree[SIZE*SIZE*5];

void build(int num,int left,int right,int low,int high,int d){

    if ( left>right || low>high ){
        tree[num] = -1;
        return ;
    }

    if ( left == right && low == high ){
        tree[num]= grid[low][left];
        return ;
    }

    if ( d == 0 ){

        build( 2*num,left,(left+right)/2,low,high,d^1 );
        build( 2*num+1,(left+right)/2+1,right,low,high,d^1 );

        tree[num] = max( tree[2*num] ,tree[2*num+1] );
    }else{
        build( 2*num,left,right,low,(low+high)/2,d^1 );
        build( 2*num+1,left,right,(low+high)/2+1,high,d^1 );

        tree[num] = max( tree[2*num] ,tree[2*num+1] );
    }

}


pint qa,qb;
int query(int num,int left,int right,int low,int high,int d){

    if ( left>right || low>high ){
        return -1;
    }

    if ( left> qb.Y || right<qa.Y || low>qb.X || high<qa.X )return -1;

    if ( left>=qa.Y && right<=qb.Y && low>=qa.X && high<=qb.X ){
        return tree[num];
    }

    if ( d == 0 ){

        int ret = query( 2*num,left,(left+right)/2,low,high,d^1 );
        ret = max( ret, query( 2*num+1,(left+right)/2+1,right,low,high,d^1 ) );

        return ret;
    }else{
        int ret = query( 2*num,left,right,low,(low+high)/2,d^1 );
        ret = max( ret, query( 2*num+1,left,right,(low+high)/2+1,high,d^1 ) );

        return ret;
    }

}


int main(){

    //FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,qq;
        scanf("%d %d",&n,&qq);

        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                scanf("%d",&grid[i][j]);
            }
        }

        build( 1,1,n,1,n , 0 );

        printf("Case %d:\n",kk);
        int x,y,s;
        while ( qq-- ){
            scanf("%d %d %d",&x,&y,&s);

            qa = MP( x,y );
            qb = MP( x+s-1,y+s-1 );

            printf("%d\n",query( 1,1,n,1,n,0 ));
        }

    }


    return 0;
}
