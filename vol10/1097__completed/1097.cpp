#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MaxVal=1429431;

int tree[MaxVal+1];

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

int binarySearch(int ind){
    int low=1,high=MaxVal,mid,tmp;
    bool found;
    while ( low<=high ){
        mid=(low+high)/2;
        found=false;
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


    int kase,a,b,tmp;


    for (int i=1;i<=MaxVal;i+=2){
        update(i,1);
    }


    for (int i=2;i<=MaxVal;i++){
        a=binarySearch(i);
        if ( a== -1 )break;

        for (int j=a;j<=MaxVal;j+=a-1){
            b=binarySearch(j);
            if ( b== -1 )break;
            update(b,-1);
        }

    }

    //scanf("%d",&kase);
    kase=0;
    for (int kk=1;kase--;++kk){
        scanf("%d",&a);
        printf("Case %d: %d\n",kk,binarySearch(a) );
    }
    return 0;

}
