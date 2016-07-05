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

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    while ( kase-- ){
        int n;
        scanf("%d",&n);
        vector<int> vec(n);
        for (int i=0;i<n;++i){
            scanf("%d",&vec[i]);
        }

        int ans = 0;
        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                for (int p=j+1;p<n;++p){
                    for (int q=p+1;q<n;++q){
                        if ( __gcd(  vec[i],__gcd(vec[j] , __gcd(vec[p],vec[q]) )  ) == 1 ){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;

    }


    return 0;
}
