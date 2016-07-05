    #include <cstdio>
    #include <algorithm>

    using namespace std;

    struct NODE{
        int val,num;
        int left,right;
        bool isleaf;
    }tree[500001],save[200001];

    int total;
    int ql,qr;

    void build(int node,int l,int r)
    {
        if(l==r){
            tree[node].val= save[l].right-save[l].left+1 ;
            tree[node].left=save[l].left;
            tree[node].right=save[l].right;
            tree[node].isleaf=true;
        }
        else{
            build(2*node,l,(l+r)/2);
            build(2*node+1,(l+r)/2+1,r);


            tree[node].left=tree[2*node].left;
            tree[node].right=tree[2*node+1].right;
            if ( tree[2*node].val >= tree[2*node+1].val ){
                tree[node].val=tree[2*node].val;
            }else{
                tree[node].val=tree[2*node+1].val;
            }
            tree[node].isleaf=false;

        }
    }

    int query(int node){

        if (tree[node].right<ql || tree[node].left>qr)return 0;
        else if (tree[node].left>=ql && tree[node].right<=qr)return tree[node].val;
        else if ( tree[node].isleaf ){
            if ( ql>= tree[node].left && qr<=tree[node].right )return qr-ql+1;
            else if ( ql>= tree[node].left ){
                return tree[node].right-ql+1;
            }else{
                return qr-tree[node].left+1;
            }
        }
        else{
            return max( query(2*node), query(2*node+1) );
        }
    }

    int main(){



        int kase,leaf,cc,q,diff,tmp;
        scanf("%d",&kase);

        for (int kk=1;kase--;++kk){
            scanf("%d %d %d",&leaf,&cc,&q);
            diff=0;
            for (int i=1;i<=leaf;++i){
                scanf("%d",&tmp);
                if ( tmp != save[diff].num ){
                    save[++diff].num=tmp;
                    save[diff].left=i;
                    save[diff].right=i;
                }else{
                    save[diff].right++;
                }
            }
            build(1,1,diff);


            printf("Case %d:\n",kk);
            while (q-- ){
                scanf("%d %d",&ql,&qr);
                printf("%d\n",query(1));
            }
        }
        return 0;
    }

