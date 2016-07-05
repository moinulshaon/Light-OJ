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

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

typedef pair<int,int> pint;
typedef map<int,int> mint;


#define SIZE 100100

int length;
int fenwick[SIZE];

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += fenwick[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= length){
		fenwick[idx] += val;
		idx += (idx & -idx);
    	}
}
int arr[SIZE];
vector<int> v[SIZE];
struct tt{
    int first,second,ser,result;
}query[SIZE];

bool cmp( const tt&x,const tt&y ){
    return x.first<y.first;
}
bool cmp2( const tt&x,const tt&y ){
    return x.ser<y.ser;
}


bool vis[SIZE];

int main(){

    FRO
freopen("out.txt","w",stdout);

    int kase;
    scanf("%d",&kase);
    int len,qq;
    for (int kk=1;kase--;++kk){
        printf("Case %d:\n",kk);
        scanf("%d %d",&len,&qq);
        length=len+2;



        for (int i=1;i<=len;++i){
            scanf("%d",&arr[i]);
            arr[i]++;
        }

        for (int i=0;i<SIZE;++i){
            v[i].clear();
        }
        for (int i=0;i<SIZE;++i){
            v[i].PB(len+1);
        }
        for (int i=len;i>0;--i){
            v[ arr[i] ].PB(i);
        }

        for (int i=0;i<qq;++i){
            scanf("%d %d",&query[i].first,&query[i].second);
            query[i].ser=i;
        }

        sort( query,query+qq ,cmp);

        CLR(fenwick);
        CLR(vis);

        for (int i=1;i<=len;++i){
            if ( !vis[ arr[i] ] ){
                vis[ arr[i] ]=true;
                update(i,1);
            }
        }
        /*
        for (int i=1;i<=len;++i){
            printf("%3d",read(i));
        }printf("\n");
        */
        int left=1,tmp;
        for (int i=0;i<qq;++i){
            //printf("%d %d\n",query[i].first,query[i].second);
            //printf("new query\n\n");
            for (int j=left;j<query[i].first;++j,++left){

                tmp=v[ arr[j] ].size()-1;

                /*
                for (int i=1;i<=len;++i){
                    printf("%3d",read(i));
                }printf("\n");
                */
                update( v[ arr[j] ][tmp],-1 );
                update( v[ arr[j] ][tmp-1],1 );
                /*
                for (int i=1;i<=len;++i){
                    printf("%3d",read(i));
                }printf("\n");
                */

                v[ arr[j] ].pop_back();

            }

            query[i].result=read(query[i].second)-read(query[i].first-1);
        }

        sort(query,query+qq,cmp2);
        for (int i=0;i<qq;++i){
            printf("%d\n",query[i].result);
        }
    }

    return 0;
}
