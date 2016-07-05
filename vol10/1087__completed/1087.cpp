    #include <cstdio>
    #include <cstring>

    using namespace std;

    const int MaxVal=2*101000;

    int tree[MaxVal];
    int arr[MaxVal];
    int n,q,lim;
    int read(int idx){
        int sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void update(int idx ,int val){
        while (idx <= lim){
            tree[idx] += val;
            idx += (idx & -idx);
            }
    }

    int binarySearch(int ind){
        int low=1,high=n,mid,tmp;

        while ( low<=high ){
            mid=(low+high)/2;
            bool found=false;
            while (mid>0 && read(mid)==ind ){
                --mid;
                found=true;
            }
            if ( found )return mid+1;
            tmp=read(mid);
            if ( tmp<ind )low=mid+1;
            else if ( tmp>ind )high=mid-1;
        }
        return -1;
    }


    int main(){


        int kase,q,a,b;
        scanf("%d",&kase);
        char ca[2];
        for (int kk=1;kase--;++kk){

            scanf("%d %d",&n,&q);
            lim=n+q;
            printf("Case %d:\n",kk);
            for (int i=1;i<=n;++i){
                scanf("%d",&arr[i]);
            }
            memset(tree,0,sizeof(tree));
            for (int i=1;i<=n+q;++i){
                update(i,1);
            }


            while(q--){
                scanf("%s %d",ca,&a);
                if (ca[0]=='c'){
                    int b=binarySearch(a);

                    if ( b!= -1 ){
                        update(b,-1);
                        printf("%d\n",arr[b]);
                    }

                    else{
                        printf("none\n");
                    }
                }else{
                    arr[ ++n ]= a;
                }
            }
        }
        return 0;

    }

