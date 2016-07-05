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

vector<string> rev;
int out[400];

void calc(int x){
    if ( x == -1 ){
        printf("\n");
        return ;
    }
    printf("%s\n",rev[x].c_str());
    calc( out[x] );
}

int main(){

    FRO

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        map<string,int> mp;
        int n;
        scanf("%d",&n);
        int deg[400]={0};


        NEG(out);

        rev.clear();

        string a,b;
        int cnt = 0;
        for (int i=1;i<n;++i ){
            cin>>a>>b;
            if ( mp.find( a ) == mp.end() ){
                rev.PB( a );
                mp[ a ] = cnt++;
            }
            if ( mp.find( b ) == mp.end() ){
                rev.PB( b );
                mp[ b ] = cnt++;
            }

            out[ mp[a] ] = mp[b];

            deg[ mp[a] ]++;
            deg[ mp[b] ]--;
        }
        int ind = 0;
        for (int i=0;i<cnt;++i){
            if ( deg[i] >0 ){
                ind = i;
                break;
            }
        }

        printf("Case %d:\n",kk);
        calc(ind);

    }



    return 0;
}
