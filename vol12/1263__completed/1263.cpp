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

#define SIZE 1010

int arr[SIZE];

struct u_find{
    int parent[SIZE];
    int size[SIZE];
    int val[SIZE];

    void ini(int n){
        for (int i=1;i<=n;++i){
            parent [i] = i;
            size[i]=1;
            val[i] = arr[i];
        }
    }
    int parentOf (int n){
        if ( n == parent [n] ) return n;
        return parent [n] = parentOf (parent [n]);
    }
    void make_union(int x,int y){
        int p = parentOf (x);
        int q = parentOf (y);

        if ( p != q ) {
            if (size[p]>size[q])swap(p,q);
            size[q]+=size[p];
            val[q] += val[p];
            parent [p] = q;
        }
    }
}tree;

int main(){

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,m,u,v;
        scanf("%d %d",&n,&m);
        int sum = 0;
        for (int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
            sum += arr[i];
        }
        tree.ini(n);
        while ( m-- ){
            scanf("%d %d",&u,&v);
            tree.make_union(u,v);
        }

        bool pos=true;
        if ( sum%n  != 0 )pos=false;
        sum /= n;
        for (int i=1;i<=n && pos ;++i){
            if ( tree.parentOf(i) == i ){
                if ( tree.val[i] % tree.size[i] != 0 || tree.val[i] / tree.size[i] != sum ){
                    pos=false;
                }
            }
        }

        if ( pos )printf("Case %d: Yes\n",kk);
        else printf("Case %d: No\n",kk);

    }


    return 0;
}
