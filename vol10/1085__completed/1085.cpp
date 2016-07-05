#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

#define SIZE 100100


const int mod=1000000007;


int tree[SIZE];

int MaxVal;

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum = ( sum+tree[idx] )%mod;
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] = (tree[idx]+val)%mod;
		idx += (idx & -idx);
    }
}
int arr[SIZE];
int tmp[SIZE];
int main(){

    int kase,n;
    scanf("%d",&kase);
    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            tmp[i]=arr[i];
        }
        sort(tmp,tmp+n);
        map<int,int> mp;

        for (int i=0;i<n;++i){
            mp[ tmp[i] ]=i+1;
        }
        MaxVal=n+1;

        memset(tree,0,sizeof(tree));

        int ans=0,tt;
        for (int i=0;i<n;++i){
            tt=( 1+read(mp[ arr[i] ]-1) )%mod;
            ans=( ans+tt )%mod ;
            update( mp[ arr[i] ], tt );
        }
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;

}
