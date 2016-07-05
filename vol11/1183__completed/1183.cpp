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


struct ttt{
    int val;
    ttt operator + ( const ttt & b){
        ttt tmp;
        tmp.val=val+b.val;
        return tmp;
    }
}tree[800001],zz;
int lazy[800001];




int ql,qr;
ttt query(int node,int l,int r){
    if (r<ql || l>qr)return zz;
    else if ( lazy[node] != -1 ){
        lazy[2*node]= lazy[node] ;
        lazy[2*node+1]= lazy[node] ;
        if ( lazy[node]!= -1 )
            tree[node].val=lazy[node]*(r-l+1);
        lazy[node]= -1;
    }

    if (l>=ql && r<=qr)return tree[node];
    else{
        return query(2*node,l,(l+r)/2)+query(2*node+1,(l+r)/2+1,r);
    }
}

int ul,ur,tofix;
void update(int node,int l,int r){
    //printf("%d %d %d %d %d %d\n",l,r,lazy[node],tree[node].zero,tree[node].one,tree[node].two);
    if ( lazy[node] != -1 ){
        lazy[2*node]= lazy[node] ;
        lazy[2*node+1]= lazy[node] ;

        if( lazy[node] != -1 )
            tree[node].val=lazy[node]*(r-l+1);
        lazy[node]= -1;
        //printf("now value %d %d %d %d %d\n",l,r,tree[node].zero,tree[node].one,tree[node].two);
    }

    if (r<ul || l>ur)return ;
    else if (l>=ul && r<=ur){
        tree[node].val=tofix*(r-l+1);
        lazy[2*node]= tofix ;
        lazy[2*node+1]= tofix ;
    }else{
        update(2*node,l,(l+r)/2);
        update(2*node+1,(l+r)/2+1,r);

        while (node){
            tree[node]=tree[2*node]+tree[2*node+1];
            node/=2;
        }
    }
}


int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    zz.val=0;

    for (int kk=1;kase--;++kk){
        printf("Case %d:\n",kk);
        CLR(tree);
        NEG(lazy);

        int len,qq;
        scanf("%d %d",&len,&qq);
        int id,le,ri,vv;
        while(qq--){
            scanf("%d",&id);
            if ( id==1 ){
                scanf("%d %d %d",&le,&ri,&vv);
                ul=le+1;
                ur=ri+1;
                tofix=vv;
                update(1,1,len);
            }else{
                scanf("%d %d",&le,&ri);
                ql=le+1;
                qr=ri+1;
                int sum=query(1,1,len).val;
                if ( sum%(qr-ql+1)==0 ){
                    printf("%d\n",sum/(qr-ql+1));
                }else{
                    int d=__gcd( sum,qr-ql+1 );
                    printf("%d/%d\n",sum/d,(qr-ql+1)/d);
                }
            }
        }
    }


    return 0;
}
