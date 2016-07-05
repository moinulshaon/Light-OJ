#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define SIZE 100100

int tree[SIZE];
int save[SIZE];
int MaxVal;

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
    	}
}


int main(){

    int kase,q,tmp,a,b;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %d",&MaxVal,&q);
        memset(tree,0,sizeof(tree));

        for (int i=1;i<=MaxVal;++i){
            scanf("%d",&save[i]);
            update(i,save[i]);
        }
        printf("Case %d:\n",kk);
        while (q--){
            scanf("%d",&tmp);
            if ( tmp==1 ){
                scanf("%d",&a);
                a++;
                printf("%d\n",save[a]);
                update(a,-save[a]);
                save[a]=0;
            }else if ( tmp==3 ){
                scanf("%d %d",&a,&b);
                a++;
                b++;
                printf("%d\n",read(b)-read(a-1));
            }
            else {
                scanf("%d %d",&a,&b);
                a++;
                update(a,b);
                save[a]+=b;
            }
        }
    }
    return 0;


}
