#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#define SIZE 1010

typedef pair<int,int> point;

int tree[SIZE][SIZE];
int max_x=SIZE;
int max_y=SIZE;

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

    int kase,query,q,ans;
    point a,b;

    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        memset(tree,0,sizeof(tree));

        printf("Case %d:\n",kk);
        scanf("%d",&query);

        set<point> sset;
        vector<point> v;
        while ( query-- ){
            scanf("%d",&q);

            if( !q ){
                scanf("%d %d",&a.first,&a.second);
                a.first++;
                a.second++;
                if ( sset.find(a)==sset.end() ){
                    sset.insert(a);
                    update( a.first ,a.second , 1 );
                }
            }else {
                scanf("%d %d %d %d",&a.first,&a.second,&b.first,&b.second);
                a.first++;
                b.first++;

                a.second++;
                b.second++;

                ans=0;
                ans+= read( b.first,b.second );
                ans-= read( a.first-1 , b.second );
                ans-= read( b.first , a.second-1 );
                ans+= read( a.first-1 , a.second-1 );
                printf("%d\n",ans);

            }
        }

    }
    return 0;

}
