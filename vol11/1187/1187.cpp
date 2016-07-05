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


#define SIZE 100010

struct node{
    int min_val;
    bool pos_left;
    bool pos_right;
    bool pos_me;
    int lim;
    int left,right;
}tree[7*SIZE];
int lazy[7*SIZE];

int arr[SIZE];

node merge( node x,node y ){

    node tmp;

    tmp.min_val = min( x.min_val,y.min_val );

    tmp.pos_left = x.pos_me;
    tmp.pos_right = y.pos_me;

    tmp.pos_me = x.pos_me || y.pos_me;

    tmp.lim = min( x.lim,y.lim ) ;

    tmp.left=x.left;
    tmp.right=y.right;

    return tmp;
}

void build( int num ,int le,int ri){

    tree[num].left=le;
    tree[num].right=ri;

    lazy[num] = 0;

    if ( le==ri ){
        tree[num].min_val=arr[le];
        tree[num].lim = 0;

        if ( arr[le] == 0 )tree[num].pos_me= true;
        else tree[num].pos_me= false;

    }else{

        build(2*num,le,(le+ri)/2);
        build(2*num+1, (le+ri)/2+1,ri);

        tree[num]=merge(tree[2*num],tree[2*num+1]);

    }
}



void change(int x){
    tree[x].lim += lazy[x];
    if ( tree[x].min_val <= tree[x].lim ){
        tree[x].pos_me = true;
    }else{
        tree[x].pos_me = false;
    }
}

node query( int num ){

    //cout<<tree[num].left<<" "<<tree[num].right<<" "<<tree[num].min_val<<" "<<tree[num].lim<<endl;

    change( num );
    lazy[num] = 0;

    if ( tree[num].left == tree[num].right )return tree[num];

    if ( tree[num].pos_right )return query( 2*num+1 );
    else if ( tree[num].pos_left )return query( 2*num );
    else {
        //cout<<tree[num].left<<" "<<tree[num].right<<" "<<tree[num].min_val<<" "<<tree[num].lim<<endl;
        exit(5);
    }
}

void update(int num,int ul,int ur,int vv){

    if ( lazy[num]!= 0 ){
        lazy[2*num]+= lazy[num] ;
        lazy[2*num+1]+= lazy[num] ;
        change(num);
        lazy[num]=0;
    }

    if (tree[num].right  <ul || tree[num].left>ur)return ;
    else if (tree[num].left>=ul && tree[num].right <=ur){
        lazy[num]=vv;
        change(num);
        lazy[num]=0;
        lazy[2*num]+= vv;
        lazy[2*num+1]+= vv ;
    }else{
        update(2*num,ul,ur,vv);
        update(2*num+1,ul,ur,vv);

        tree[num]=merge( tree[2*num],tree[2*num+1] );
    }
}

void update2( int num,int ul,int ur ){

    if ( lazy[num]!= 0 ){
        lazy[2*num]+= lazy[num] ;
        lazy[2*num+1]+= lazy[num] ;
        change(num);
        lazy[num]=0;
    }

    if (tree[num].right  <ul || tree[num].left>ur)return ;
    else if (tree[num].left>=ul && tree[num].right <=ur){
        tree[num].min_val = (1<<30);
        change(num);

    }else{

        update2(2*num,ul,ur);
        update2(2*num+1,ul,ur);

        tree[num]=merge( tree[2*num],tree[2*num+1] );
    }
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
        }
        build( 1,1,n );

        int ans = -1;
        int now = n;
        while ( true ){

            node tmp = query( 1 );
            //cout<<tmp.left<<endl;

            //cout<<tmp.left<<endl;

            if ( tmp.left == 1 ){
                ans = now;
                break;
            }


            update2( 1,tmp.left,tmp.left );


            update( 1,tmp.left,n,1 );


            now--;
        }
        printf("Case %d: %d\n",kk,ans);

    }


    return 0;
}
