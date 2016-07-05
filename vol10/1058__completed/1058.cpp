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

#define X first
#define Y second

typedef pair<int,int> pint;
typedef map<int,int> mint;

pint point[1010];

int main(){
    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        vector<pint> v;;
        int n;

        scanf("%d",&n);

        for (int i=0;i<n;++i){
            scanf("%d %d",&point[i].X,&point[i].Y);
        }



        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                v.PB(  make_pair( point[i].X+point[j].X , point[i].Y+point[j].Y ) );
            }
        }

        sort( v.begin(),v.end() );


        int ans=0;
        int tmp=v.size();
        for (int i=0;i<tmp;){
            int cnt=1;
            for (int j=i+1;j<tmp;++j){
                //printf("%d %d %d %d\n",v[i].X,v[i].Y,v[j].X,v[j].Y);
                if ( v[j]!=v[i] )break;
                ++cnt;
            }
            i+=cnt;
            //printf("%d\n",cnt);
            ans+= (cnt)*(cnt-1)/2;
        }
        printf("Case %d: %d\n",kk,ans);
    }
    return 0;
}
