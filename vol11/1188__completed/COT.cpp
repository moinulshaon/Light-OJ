#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


#define FO(i,a,b) for (int i = (a); i < (b); i++)

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

#define SIZE 100100

struct SEG{

    struct NODE{
        LL val;
        int left,right;
        int low,high;
    }tree[20*SIZE];

    int ptr;
    int create(int ulow,int uhigh){

        if ( ptr >= 20*SIZE ){
            exit(5);
        }

        tree[ptr].left=0;
        tree[ptr].right=0;
        tree[ptr].low = ulow;
        tree[ptr].high = uhigh;
        tree[ptr].val=0;

        return ptr++;
    }

    void add(int num,int q_l,int q_h,LL val){

        NODE &node=tree[num];

        if ( node.low> node.high || q_l > node.high || q_h<node.low )return ;

        if ( q_l<=node.low && node.high <= q_h ){
            node.val += val;
            return ;
        }

        int mid=(node.low+node.high)/2;
        if ( node.left == 0 ){
            node.left = create(node.low,mid);
            node.right = create(mid+1,node.high);
        }

        add( node.left,q_l,q_h,val );
        add( node.right,q_l,q_h,val );

        node.val= tree[node.left].val+tree[node.right].val;
    }

    int add_persistent(int num,int q_l,int q_h,LL val){


        NODE &prvnode=tree[num];
        int ret = create(prvnode.low,prvnode.high);
        NODE &node=tree[ret];

        //make same as before
        node.val = prvnode.val;
        node.left = prvnode.left;
        node.right = prvnode.right;

        if ( node.low> node.high || q_l > node.high || q_h<node.low ){
            return ret;
        }

        if ( q_l<=node.low && node.high <= q_h ){
            node.val += val;
            return ret;
        }

        int mid=(node.low+node.high)/2;

        if ( ( q_l>=node.low && q_l<=mid ) || ( q_h>=node.low && q_h<=mid ) ){
            node.left = add_persistent( prvnode.left,q_l,q_h,val );
        }
        if ( ( q_l>=mid+1 && q_l<=node.high ) || ( q_h>=mid+1 && q_h<=node.high ) ){
            node.right= add_persistent( prvnode.right,q_l,q_h,val );
        }

        node.val = tree[node.left].val+tree[node.right].val;

        return ret;
    }


    LL query(int num,int q_l,int q_h){

        NODE &node=tree[num];

        if ( node.low> node.high || q_l > node.high || q_h<node.low )return 0;

        if ( q_l<=node.low && node.high <= q_h  ){
            return node.val;
        }

        int mid=(node.low+node.high)/2;

        return query( node.left,q_l,q_h )+query( node.right,q_l,q_h );
    }

    void ini(int low,int high){
        ptr=1;
        create( low,high );
    }

}ds;


int arr[SIZE];
int last[SIZE];
int nxt[SIZE];

int root[SIZE];

int main(){

    FRO
    freopen("out.txt","w",stdout);

    NEG(last);

    int kase;
    scanf("%d",&kase);
    int n;
    int q;

    for ( int kk=1;kase--;++kk ){

        printf("Case %d:\n",kk);

        scanf("%d %d",&n,&q);
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
        }

        for (int i=n;i>0;--i){
            nxt[i] = last[ arr[i] ];

            last[ arr[i] ] = i;
        }

        ds.ini( 1,n );
        root[1] = 1;

        for (int i=1;i<=n;++i){
            ds.add( root[1],i,i,0 );
        }
        for (int i=0;i<SIZE;++i){
            if (  last[i] != -1 ){
                ds.add( root[1] , last[i],last[i] ,1 );
            }
        }

/*
        for (int i=1;i<=n;++i){
            show(i,nxt[i],last[ arr[i] ]);
        }
*/
        for (int i=2;i<=n;++i){
            if (  nxt[i-1] != -1 ){
                root[i] = ds.add_persistent( root[i-1],nxt[i-1],nxt[i-1],1 );
            }else{
                root[i] = root[i-1];
            }
        }


        int a,b;
        while ( q-- ){
            scanf("%d %d",&a,&b);
            printf("%d\n",ds.query( root[a],a,b ));
        }


        for (int i=1;i<=n;++i){
            last[ arr[i] ] = -1;
        }

    }

    return 0;
}
