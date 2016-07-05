#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

#define SIZE 200000


int tree[SIZE];
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

pair<int,int> point[60000];
int query[60000];

int main(){

    int kase,n,q;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d %d",&n,&q);

        vector<int> v;

        for (int i=0;i<n;++i){
            scanf("%d %d",&point[i].first,&point[i].second);

            v.push_back(point[i].first);

            v.push_back(point[i].second);


        }

        for (int i=0;i<q;++i){
            scanf("%d",&query[i]);
            v.push_back(query[i]);
        }

        sort(v.begin(),v.end());
        map<int,int> mp;
        for (int i=0;i<v.size();++i){
            mp[ v[i] ]=i+1;
        }

        MaxVal=mp[ v.back() ]+1;
        memset(tree,0,sizeof(tree));

        for (int i=0;i<n;++i){
            update( mp[ point[i].first ] , 1 );
            update( mp[ point[i].second ]+1 , -1 );
        }
        printf("Case %d:\n",kk);
        for (int i=0;i<q;++i){
            printf("%d\n",read(mp[ query[i] ]));
        }

    }
    return 0;

}
