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


#define SIZE 100100
int inf = 10000000;

struct node{
    int val;
    int left,right;
}tree[7*SIZE];

int mark[SIZE];

node merge( node x,node y ){
    node tmp;
    tmp.val= min( x.val, y.val ) ;

    tmp.left=x.left;
    tmp.right=y.right;

    return tmp;
}

void build( int num ,int le,int ri){
    //printf("%d\n",num);
    tree[num].left=le;
    tree[num].right=ri;
    if ( le==ri ){
        mark[le]=num;
        tree[num].val=inf;
    }else{
        build(2*num,le,(le+ri)/2);
        build(2*num+1, (le+ri)/2+1,ri);
        tree[num]=merge(tree[2*num],tree[2*num+1]);
    }
}

node query( int num,int ql,int qr ){
    //printf("%d %d %d\n",num,tree[num].left,tree[num].right);
    if ( ql <= tree[num].left && qr >= tree[num].right  )return tree[num];
    else{
        bool lon=false,ron=false;
        if (  ql<= tree[2*num].right )
            lon=true;
        if ( qr>= tree[2*num+1].left  )
            ron=true;
        if ( lon && ron ){
            return merge(query(2*num,ql,qr),query(2*num+1,ql,qr));
        }else if ( lon ){
            return query(2*num,ql,qr);
        }else if ( ron ){
            return query(2*num+1,ql,qr);
        }
    }
}
void update(int pos,int val){
    int pp=mark[pos];

    tree[pp].val=val;

    pp/=2;

    while (pp){
        tree[pp]=merge(tree[2*pp],tree[2*pp+1]);
        pp/=2;
    }
}



int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n,k;
        scanf("%d %d",&n,&k);

        printf("Case %d: ",kk);

        vector<int> vec;
        int tmp;
        vec.PB( -inf );
        for (int i=0;i<n;++i){
            scanf("%d",&tmp);
            vec.PB( tmp );
        }

        if ( n<3 ){
            printf("-1\n");
            continue;
        }

        sort( vec.begin(),vec.end() );

        build(1,1,n);

        vector<int>::iterator it;
        for (int i=3;i<=n;++i){
            it=lower_bound( vec.begin(),vec.end(), vec[i]-2*k );


            int ind = distance( vec.begin(),it );

            if ( i-ind+1<3 ){
                continue;
            }

            if ( ind-1==0 ){
                update( i,1 );
            }else{
                update( i,1+query(1,ind-1,i-1).val );
            }

        }

        int ans = query(1,n,n).val;

        if ( ans>=inf ){
            printf("-1\n");
        }else{
            printf("%d\n",ans);
        }

    }


    return 0;
}
