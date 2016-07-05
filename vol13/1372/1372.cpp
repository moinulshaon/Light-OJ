#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[101];

int tree[102][100002];
int max_x;
int max_y;

int read(int x , int y ){
    int val=0;
	int y1;
	while (x > 0 ){
		y1 = y;
		while (y1>0){
			val+=tree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return val;
}

void update(int x , int y , int val){
	int y1;
	while (x <= max_x){
		y1 = y;
		while (y1 <= max_y){
			tree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int main(){
    freopen("in.txt","r",stdin);
    int kase,n;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        max_y=arr[n]+1;
        max_x=n;
        printf("%d\n",max_y);
        memset(tree,0,sizeof(tree));

        for (int i=n;i>0;--i){
            for (int j=i-1;j>0;--j){
                for (int k=j-1;k>0;--k){
                    //if ( arr[i]-arr[j]-arr[k] >0 ){
                    int tmp=arr[i]-arr[j]-arr[k];
                    if ( tmp<0 )
                        update( k,arr[i]-arr[j]-arr[k], 1 );
                        printf("%d %d %d %d %d\n",arr[i]-arr[j]-arr[k],k,arr[i],arr[j],arr[k]);
                    //}
                }
            }
        }
        //printf("%d\n",read(n,max_y-1));
        int ans=0;
        for (int i=1;i<=n;++i){
            for (int j=i+1;j<=n;++j){
                for (int k=j+1;k<=n;++k){
                    ans+=read( k-1,arr[i]+arr[j]+arr[k] );
                }
            }
        }
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}
