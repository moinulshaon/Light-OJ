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

#define SIZE 100100

int tree[SIZE];
int MaxVal=SIZE-10;
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
mint mp;
vector<pint> v;
vector<int> tmp;

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        CLR(tree);

        mp.clear();
        v.clear();
        tmp.clear();
        int a,b;
        for (int i=0;i<n;++i){
            scanf("%d %d",&a,&b);
            v.PB( MP(a,b) );
            tmp.PB( a );
            tmp.PB( b );
        }
        sort( tmp.begin(),tmp.end() );

        int cnt = 1;
        for (int i=0;i<tmp.size();++i){
            if ( mp.find( tmp[i] ) == mp.end() ){
                mp[ tmp[i] ]= cnt++;
            }
        }

        for (int i=0;i<n;++i){
            update( mp[ v[i].X ],1 );
            update( mp[ v[i].Y ]+1,-1 );
        }

        int ans = 0;
        for (int i=1;i<=cnt;++i){
            ans = max( ans ,read(i) );
        }
        printf("Case %d: %d\n",kk,ans);

    }


    return 0;
}
