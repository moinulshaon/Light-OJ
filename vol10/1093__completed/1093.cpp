    #include <cstdio>
    #include <cstring>
    #include <utility>
    #include <algorithm>

    #define INF (1<<30)

    using namespace std;

    pair<int,int> tree[500001];
    int save[200001];
    pair<int,int> dummy( +INF,-INF ),tmp;
    int ql,qr;

    void build(int node,int l,int r)
    {
        if(l==r){
            tree[node].first=save[l];
            tree[node].second=save[l];
        }
        else{
            build(2*node,l,(l+r)/2);
            build(2*node+1,(l+r)/2+1,r);

            tree[node].first=min( tree[2*node].first , tree[2*node+1].first );
            tree[node].second=max( tree[2*node].second , tree[2*node+1].second );
        }
    }

    pair<int,int> query(int node,int l,int r){

        if (r<ql || l>qr)return dummy;
        else if (l>=ql && r<=qr)return tree[node];
        else{
            pair<int,int> x=query(2*node,l,(l+r)/2),y=query(2*node+1,(l+r)/2+1,r);
            return make_pair( min( x.first,y.first )  , max( x.second,y.second ) );
        }
    }

    int main(){
        int kase,leaf,d;
        scanf("%d",&kase);

        for (int kk=1;kase--;++kk){

            scanf("%d %d",&leaf,&d);
            for (int i=1;i<=leaf;++i){
                scanf("%d",&save[i]);
            }
            build(1,1,leaf);

            int result= -INF;
            for (int i=1;i<=leaf-d+1;++i){
                ql=i;
                qr=i+d-1;
                tmp=query(1,1,leaf);
                result=max( result, tmp.second-tmp.first );
            }
            printf("Case %d: %d\n",kk,result);
        }
        return 0;
    }

