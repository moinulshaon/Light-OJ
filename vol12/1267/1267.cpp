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

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 200010

struct L{
    int x1,x2;
    int y;
    int val;
    int ind;
    L(int a,int b,int c,int d,int in){
        x1=a;
        x2=b;
        y=c;
        val=d;
        ind = in;
    }
    L(){}
}line[SIZE];

pint point[SIZE];

bool cmp1( pint a,pint b ){
    return a.Y<b.Y;
}
bool cmp2( L a,L b ){
    return a.y<b.y;
}

int tree[SIZE];
int sz;
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <=sz ){
		tree[idx] += val;
		idx += (idx & -idx);
    }
}

int ans[SIZE];

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n,q;
        scanf("%d %d",&n,&q);

        mint mp;
        for (int i=0;i<n;++i){
            scanf("%d %d",&point[i].X,&point[i].Y);
            mp[ point[i].X ];
        }

        int a,b,c,d;
        int cnt = 0;
        for (int i=0;i<q;++i){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            line[cnt++] = L( a,c,b-1,-1,i );
            line[cnt++] = L( a,c,d,1,i );
            mp[ a ];
            mp[ c ];
            ans[i] = 0;
        }
        sz = 0;
        snuke ( mp,itr ){
            itr->second = ++sz;
        }
        for (int i=0;i<=sz;++i)tree[i] = 0;
        for (int i=0;i<n;++i){
            point[i].X = mp[ point[i].X ];
            //cout<<point[i].X<<endl;
        }
        for (int i=0;i<cnt;++i){
            line[i].x1 = mp[ line[i].x1 ];
            line[i].x2 = mp[ line[i].x2 ];
        }

        sort( point,point+n,cmp1 );
        sort( line,line+cnt,cmp2 );

        int ind = 0;

        for (int i=0;i<cnt;++i){
            while ( ind<n && point[ind].Y <= line[i].y ){
                update( point[ind].X,1 );
                //cout<<"point "<<point[ind].X<<endl;
                ind++;
            }

            L& now = line[i];
            //cout<<now.ind<<" "<<now.val<<" "<<now.x1<<" "<<now.x2<<endl;
            ans[ now.ind ] += now.val *( read( now.x2 ) - read( now.x1-1 ) );
        }

        printf("Case %d:\n",kk);
        for (int i=0;i<q;++i){
            printf("%d\n",ans[i]);
        }
    }


    return 0;
}
