#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 10000000

int tree[500001];
int save[200001];
int ql,qr;

void build(int node,int l,int r)
{
    if(l==r){
        tree[node]=save[l];
    }
    else
    {
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);

        tree[node]=min( tree[2*node],tree[2*node+1]);
    }
}

int query(int node,int l,int r)
{
    if (r<ql || l>qr)return INF;
    else if (l>=ql && r<=qr)return tree[node];
    else{
        return min( query(2*node,l,(l+r)/2),query(2*node+1,(l+r)/2+1,r) );
    }
}

int main()
{

    freopen("in.txt","r",stdin);

    int leaf;
    int kase,qq;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk)
    {
        scanf("%d %d",&leaf,&qq);



        printf("Case %d:\n",kk);


        for (int i=1;i<=leaf;++i){
            scanf("%d",&save[i]);
        }


        build(1,1,leaf);


        while (qq--)
        {
            scanf("%d %d",&ql,&qr);
            printf("%d\n",query(1,1,leaf));
        }
    }
    return 0;
}
