#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long tree[600001];
long long lazy[600001];



int ql,qr;
long long query(int node,int l,int r){
    if (r<ql || l>qr)return 0;
    else if ( lazy[node] ){
        lazy[2*node]+=lazy[node] ;
        lazy[2*node+1]+= lazy[node] ;

        tree[node]+=(r-l+1)*lazy[node];
        lazy[node]=0;
    }

    if (l>=ql && r<=qr)return tree[node];
    else{
        return query(2*node,l,(l+r)/2)+query(2*node+1,(l+r)/2+1,r);
    }
}

int ul,ur;
void update(int node,int l,int r,int v){
    //printf("%d %d %d %d %d %d\n",l,r,lazy[node],tree[node].zero,tree[node].one,tree[node].two);
    if ( lazy[node] ){
        lazy[2*node]+=lazy[node] ;
        lazy[2*node+1]+= lazy[node] ;

        tree[node]+=(r-l+1)*lazy[node];
        lazy[node]=0;
        //printf("now value %d %d %d %d %d\n",l,r,tree[node].zero,tree[node].one,tree[node].two);
    }

    if (r<ul || l>ur)return ;
    else if (l>=ul && r<=ur){
        tree[node]+=(r-l+1)*v;
        lazy[2*node]+=v ;
        lazy[2*node+1]+=v ;
    }else{
        update(2*node,l,(l+r)/2,v);
        update(2*node+1,(l+r)/2+1,r,v);

        while (node){
            tree[node]=tree[2*node]+tree[2*node+1];
            node/=2;
        }

    }
}

int main(){

    int kase,leaf,q,a,b,c,v;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&leaf,&q);

        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));

        printf("Case %d:\n",kk);
        while (q--){
            scanf("%d",&a);
            if ( !a ){
                scanf("%d %d %d",&b,&c,&v);
                ul=b+1;
                ur=c+1;
                update(1,1,leaf,v);
            }else{
                scanf("%d %d",&b,&c);
                ql=b+1;
                qr=c+1;
                printf("%lld\n",query(1,1,leaf));
            }
        }
    }
    return 0;
}
