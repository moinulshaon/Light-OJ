#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 200100

int MaxVal=SIZE-10;
int tree[SIZE];

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

struct qq{
    int down,up,col;
}query[SIZE];

bool cmp( const qq&a,const qq&b  ){
    return a.down<b.down;
}

int main(){

    //FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m;
        scanf("%d %d",&n,&m);

        CLR(tree);

        int cnt = 0;
        for (int i=0;i<n;++i){
            scanf("%d %d",&query[cnt].down,&query[cnt].up);
            query[cnt++].col = 1;
        }

        for (int i=0;i<m;++i){
            scanf("%d %d",&query[cnt].down,&query[cnt].up);
            query[cnt++].col = 2;
        }

        sort( query,query+cnt,cmp );

        LL ans = 0;
        for (int i=0;i<cnt;++i){
            if ( query[i].col == 2 ){
                ans = ans + read(n+m+1)-read( query[i].up-1 );
            }else{
                update( query[i].up,1 );
            }
        }

        CLR(tree);
        for (int i=cnt-1;i>=0;--i){
            if ( query[i].col == 2 ){
                ans = ans + read( query[i].up );
            }else{
                update( query[i].up,1 );
            }
        }


        printf("Case %d: %lld\n",kk,ans);
    }


    return 0;
}
