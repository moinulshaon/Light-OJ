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

int row,col;

int grid[505][505];

struct node{
    int val;
    pint a,b;
}tree[SIZE*SIZE*10];


void build( int num, int left,int right,int low,int high ){

    tree[num].a = MP( left,low );
    tree[num].b = MP( high,right );

    if ( left== right && low == high ){
        tree[num].val = grid[left][low];
    }else if ( left == right ){
        build( 4*num+1,left,right,low,(low+high)/2 );
        build( 4*num+3,left,right,(low+high)/2+1,high );
        tree[num].val = max( tree[4*num+1].val , tree[4*num+3].val );
    }else if ( low == high ){
        build( 4*num+1,left,(left+right)/2,low,high );
        build( 4*num+2,(left+right)/2+1,right,low,high );
        tree[num].val = max( tree[4*num+1].val , tree[4*num+2].val );
    }else{
        build( 4*num+1,left,(left+right) )
    }

}




int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int qq;
        scanf("%d %d",&row,&qq);
        col=row;

        for (int i=0;i<row;++i){
            for (int j=0;j<col;++j){
                scanf("%d",&grid[i][j]);
            }
        }
        build_x(1,1,row-1);
    }


    return 0;
}
