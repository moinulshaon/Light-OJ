#include <cstdio>
#include <cstring>

using namespace std;

char tree[520000];
char save[510000];
int mark[510000];
int lazy[510000];
int total;
int ql,qr;

void build(int node,int l,int r)
{
    if(l==r){
        tree[node]=save[l];
        mark[l]=node;
    }
    else{

        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);
        if ( tree[2*node] == tree[2*node+1]  )
            tree[node]=tree[2*node];
        else
            tree[node]= -1;
    }
}

char query(int node,int l,int r,int sumOfLazy)
{
    if (r<ql || l>qr)return '0';
    else if (l>=ql && r<=qr){
        if ( ( sumOfLazy+lazy[node] )%2 ==1){

            if (tree[node]=='0')
                return '1';
            else
                return '0';

        }else{
            return tree[node];
        }
    }
    else{
        return ( (query(2*node,l,(l+r)/2,sumOfLazy+lazy[node])-'0') || ( query(2*node+1,(l+r)/2+1,r,sumOfLazy+lazy[node])-'0') ) +'0' ;
    }
}
int ul,ur;
void update(int node,int l,int r){

    if (r<ul || l>ur)return ;
    else if (l>=ul && r<=ur ){
        //printf("%d %d %d\n",node,l,r);
        lazy[ node ]++;
    }else{
        //printf("%d %d %d\n",node,l,r);
        update(2*node,l,(l+r)/2);
        update(2*node+1,(l+r)/2+1,r);
    }
}


int main()
{

    freopen("in.txt","r",stdin);

    int leaf;
    int kase,qq,a,b;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk)
    {
        scanf("%s",save+1);
        leaf=strlen(save+1);
        //printf("%s\n",save+1);

        //printf("%d\n",leaf);
        printf("Case %d:\n",kk);


        total=2*leaf-1;

        memset(lazy,0,sizeof(lazy));

        build(1,1,leaf);
        /*
        for (int i=1;i<=total;++i){
            printf("%d\n",tree[i]);
        }*/

        scanf("%d",&qq);
        char tt[3];
        while (qq--){
            scanf("%s",tt);
            if ( tt[0]=='Q' ){
                scanf("%d",&a);
                ql=qr=a;
                printf("%c\n",query(1,1,leaf,0));
            }else{
                scanf("%d %d",&ul,&ur);
                //printf("%d %d\n",a,b);
                update(1,1,leaf);
                //printf("\n");
            }
        }

    }
    return 0;
}
