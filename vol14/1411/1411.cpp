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

#define SIZE 250010

struct node{
    LL sum;
    LL size;
    int left,right;
}tree[7*SIZE];

node merge( node x,node y ){
    node tmp;
    tmp.sum=x.sum+y.sum;
    tmp.left=x.left;
    tmp.right=y.right;
    tmp.size = x.size+y.size;

    return tmp;
}

void build( int num ,int le,int ri){
    tree[num].left=le;
    tree[num].right=ri;
    if ( le==ri ){
        tree[num].sum=0;
        tree[num].size=1;
    }else{
        build(2*num,le,(le+ri)/2);
        build(2*num+1, (le+ri)/2+1,ri);
        tree[num]=merge(tree[2*num],tree[2*num+1]);
    }
}

LL base[7*SIZE],ltor[7*SIZE],rtol[7*SIZE],perfix[7*SIZE];

void stepahead(int num,bool can){
    if ( num>=7*SIZE )return ;

    if ( perfix[num] != INT_MIN ){
        tree[num].sum = perfix[num]*tree[num].size;
        perfix[2*num] = perfix[num];
        perfix[2*num+1] = perfix[num];

        if ( can )
            base[num]=0;
        if ( 2*num+1<7*SIZE  ){
            base[2*num]=0;
            base[2*num+1]=0;
        }

        if ( can )
            ltor[num]=0;
        if ( 2*num+1<7*SIZE  ){
            ltor[2*num]=0;
            ltor[2*num+1]=0;
        }
        if ( can )
            rtol[num]=0;
        if ( 2*num+1<7*SIZE  ){
            rtol[2*num]=0;
            rtol[2*num+1]=0;
        }
        perfix[num] = INT_MIN;
    }
}

void change(int num,bool can){

    stepahead(num,can);
    stepahead(2*num,can);
    stepahead(2*num+1,can);


    if ( base[num] != 0 ){
        base[2*num]+= base[num] ;
        base[2*num+1]+= base[num] ;
        tree[num].sum += base[num]*tree[num].size;
        base[num]=0;
    }
    if ( ltor[num] != 0 ){
        ltor[2*num]+= ltor[num] ;
        ltor[2*num+1]+= ltor[num] ;
        base[2*num+1] += tree[2*num].size* ltor[num] ;
        tree[num].sum += tree[num].size*(tree[num].size+1)/2 * ltor[num];
        ltor[num]=0;
    }
    if ( rtol[num] != 0 ){
        rtol[2*num]+= rtol[num] ;
        rtol[2*num+1]+= rtol[num] ;
        base[2*num] += tree[2*num+1].size* rtol[num] ;
        tree[num].sum += tree[num].size*(tree[num].size+1)/2 * rtol[num];
        rtol[num]=0;
    }
}

node query( int num,int ql,int qr ){
    change(num,true);


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

void update1(int num,int ul,int ur,int b ){
    change(num,true);

    if (tree[num].right  <ul || tree[num].left>ur)return ;
    else if (tree[num].left>=ul && tree[num].right <=ur){
        ltor[num]++;
        base[num]+= b;
        change(num,false);
    }else{
        bool lon=false,ron=false;
        if (  ul<= tree[2*num].right )
            lon=true;
        if ( ur>= tree[2*num+1].left  )
            ron=true;

        update1(2*num,ul,ur,b);
        if ( lon && ron ){
            b += tree[2*num].right- max( tree[2*num].left,ul ) +1;
        }
        update1(2*num+1,ul,ur,b);
        tree[num]=merge( tree[2*num],tree[2*num+1] );
    }
}

void update2(int num,int ul,int ur,int b ){
    change(num,true);

    if (tree[num].right  <ul || tree[num].left>ur)return ;
    else if (tree[num].left>=ul && tree[num].right <=ur){
        rtol[num]++;
        base[num]+= b;
        change(num,false);
    }else{
        bool lon=false,ron=false;
        if (  ul<= tree[2*num].right )
            lon=true;
        if ( ur>= tree[2*num+1].left  )
            ron=true;

        update2(2*num+1,ul,ur,b);
        if ( lon && ron ){
            b += min( tree[2*num+1].right,ur ) - tree[2*num+1].left +1;
        }
        update2(2*num,ul,ur,b);


        tree[num]=merge( tree[2*num],tree[2*num+1] );
    }
}
void update3(int num,int ul,int ur,int vv ){
    change(num,true);

    if (tree[num].right  <ul || tree[num].left>ur)return ;
    else if (tree[num].left>=ul && tree[num].right <=ur){
        perfix[num] = vv;
        change(num,true);
    }else{
        update3(2*num,ul,ur,vv);
        update3(2*num+1,ul,ur,vv);
        tree[num]=merge( tree[2*num],tree[2*num+1] );
    }
}




int main(){

    FRO


    int kase=1;

    for (int kk=1;kase--;++kk){
        int q;
        scanf("%d",&q);
        char tmp[5];

        build( 1,1,SIZE-5);

        for (int i=0;i<7*SIZE;++i){
            ltor[i]=0;
            rtol[i]=0;
            base[i]=0;
            perfix[i]=INT_MIN;
        }


        int u,v,x;
        while ( q-- ){
            scanf("%s",tmp);
            if ( tmp[0] == 'A' ){
                scanf("%d %d",&u,&v);
                update1(1,u,v,0);
            }else if ( tmp[0] == 'B' ){
                scanf("%d %d",&u,&v);
                update2(1,u,v,0);
            }else if ( tmp[0] == 'S' ){
                scanf("%d %d",&u,&v);
                printf("%lld\n",query(1,u,v).sum);
            }else{
                scanf("%d %d %d",&u,&v,&x);
                update3( 1,u,v,x );
            }
        }
    }


    return 0;
}
