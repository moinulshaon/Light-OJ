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

int Set(int N,int pos){
    return N=N | (1<<pos);
}
int Reset(int N,int pos){
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos){
    return (bool)(N & (1<<pos));
}


#define SIZE 35

vector<LL> le,ri;

LL arr[SIZE];

LL w;

int bsearch( LL x ){

    int mid,low = 0,high= ri.size()-1;
    while ( low<=high ){
        mid= (low+high)>>1;
        if ( x+ ri[mid] <= w ){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high+1;
}

int main(){

    int kase;
    scanf("%d",&kase);


    int n;

    for (int kk=1;kase--;++kk){
        scanf("%d %lld",&n,&w);

        for (int i=0;i<n;++i){
            scanf("%lld",&arr[i]);
        }

        le.clear();ri.clear();

        int p1=n/2;
        int p2=n-n/2;

        for (int i=0;i<(1<<p1);++i){
            LL sum = 0;
            for (int j=0;j<p1;++j){
                if ( Check( i,j ) ){
                    sum+= arr[j];
                }
            }
            le.PB( sum );
        }

        for (int i=0;i<(1<<p2);++i){
            LL sum = 0;
            for (int j=0;j<p2;++j){
                if ( Check( i,j ) ){
                    sum+= arr[j+p1];
                }
            }
            ri.PB( sum );
        }


        sort( ri.begin(),ri.end() );


        int ans = 0;
        for (int i=0;i<le.size();++i){
            ans+= bsearch( le[i] );
        }

        printf("Case %d: %d\n",kk,ans);
    }


    return 0;
}
